import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
#import custom message type
from octopus_interfaces.msg import SensorIndex
from octopus_interfaces.msg import ObjectDistance

class sesnsor_processor(Node):
    def __init__(self):
        super().__init__('LIDAR_sub')
        sesnsor_processor_group = MutuallyExclusiveCallbackGroup()
        custom_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            durability=DurabilityPolicy.VOLATILE
        )
        self.lidar_subscriber = self.create_subscription(
            LaserScan,
            '/scan',
            self.lidar_listener_callback,
            custom_qos ,
            callback_group=sesnsor_processor_group,  
        )
        self.lidar_subscriber
        self.get_logger().info('LIDAR Subscriber Node(LIDAR_sub) Started. Waiting for msg from "/scan"')

        self.lidar_validator_timer = self.create_timer(0.5, self.lidar_validator_callback, callback_group=sesnsor_processor_group)
        self.lidar_msg = None
        # create a publisher to publish the validated LIDAR data to a new topic
        self.lidar_validator_publisher_ = self.create_publisher(SensorIndex, 'lidar_validated', 10)
        self.lidar_validator_pub_timer = self.create_timer(0.1, self.lidar_validator_timer_pub_callback)
        self.lidar_validation_msg = SensorIndex()
        self.lidar_validation_msg.sensor = 'LIDAR'

        self.lidar_processing_list = [None] * 6
        self.object_distance_msg = ObjectDistance()
        self.object_distance_pub_ = self.create_publisher(ObjectDistance, 'object_distance', 10) 
        self.object_distance_pub_timer = self.create_timer(0.01, self.object_distance_pub_callback)


    def lidar_listener_callback(self, msg):
        #self.get_logger().info(f'LIDAR Message is: {msg}')
        if msg is not None:
            self.lidar_msg = msg

    def lidar_validator_callback(self):
        self.get_logger().info('Validating LIDAR data...')
        
        # check if the the data message is not empty
        # Check if the range of the LIDAR data is within expected limits less than 12 m and 
        # greater than 0.0 m
        if self.lidar_msg is not None :   
            self.get_logger().info('Lidar data recieved')
            msgData = self.lidar_msg.ranges
            maxRange = max(msgData)
            minRange = min(msgData)
            if maxRange <= 12.0 and minRange >= 0.0:
                self.get_logger().info('lidar data is valid')
                self.lidar_validation_msg.index = 1
                self.lidar_processing()
        # After ensuring the recieve of lidar data, specially lidar, this important, trigger the the sensor processing  module

        else:
            self.get_logger().info('No lidar data recieved yet')
            self.lidar_validation_msg.index = 2

    def lidar_validator_timer_pub_callback(self):                                        
        self.lidar_validator_publisher_.publish(self.lidar_validation_msg)
        

    def lidar_processing(self):
        # Test the data 
        #self.get_logger().info(f'minAngle:{self.lidar_msg.angle_min}, maxAngele:{self.lidar_msg.angle_max}, angleIncrement:{self.lidar_msg.angle_increment}')
        #self.get_logger().info(f'length of ranges: {len(self.lidar_msg.ranges)}')
        #self.get_logger().info(f'No. angles: {(self.lidar_msg.angle_max-self.lidar_msg.angle_min)/self.lidar_msg.angle_increment}')
        #self.get_logger().info(f'the first range: {self.lidar_msg.ranges[104:109]}')
        center_range = self.lidar_msg.ranges[104:109]
        center_object_distance_new = self.lidar_sampling(center_range)
        #self.get_logger().info(f'center object distance: {round(center_object_distance_new, 2)} m')
        self.lidar_processing_list[0] = center_object_distance_new
        if self.lidar_processing_list[1] == None:           
            self.lidar_processing_list[1] = center_object_distance_new   
        else:
            center_object_distance = 0.8 * self.lidar_processing_list[1] + 0.2 * self.lidar_processing_list[0]
            self.get_logger().info(f'center object distance: {round(center_object_distance, 2)} m')
            self.lidar_processing_list[1] = center_object_distance_new
            self.object_distance_msg.middle = center_object_distance

        # Repeat the same process for the left and right side of the LIDAR data, which are 90 degree to the left and right of the center
        left_range = self.lidar_msg.ranges[109:114]
        left_object_distance_new = self.lidar_sampling(left_range)
        self.lidar_processing_list[2] = left_object_distance_new
        if self.lidar_processing_list[3] == None:           
            self.lidar_processing_list[3] = left_object_distance_new   
        else:
            left_object_distance = 0.8 * self.lidar_processing_list[3] + 0.2 * self.lidar_processing_list[2]
            self.get_logger().info(f'left object distance: {round(left_object_distance, 2)} m')
            self.lidar_processing_list[3] = left_object_distance_new
            self.object_distance_msg.left = left_object_distance

        #Right side
        right_range = self.lidar_msg.ranges[99:104]
        right_object_distance_new = self.lidar_sampling(right_range)
        self.lidar_processing_list[4] = right_object_distance_new
        if self.lidar_processing_list[5] == None:           
            self.lidar_processing_list[5] = right_object_distance_new   
        else:
            right_object_distance = 0.8 * self.lidar_processing_list[5] + 0.2 * self.lidar_processing_list[4]
            self.get_logger().info(f'right object distance: {round(right_object_distance, 2)} m')
            self.lidar_processing_list[5] = right_object_distance_new
            self.object_distance_msg.right =  right_object_distance    

    def lidar_sampling(self, myRanges):
        object_distance_array = []
        for i in range(len(myRanges)):
            if myRanges[i] != float('inf') and myRanges[i] != float('nan') and myRanges[i] != 0.0:
                object_distance_array.append(myRanges[i])
        if len(object_distance_array) == 0:
            object_distance = 0.0
        else:
            object_distance = sum(object_distance_array) / len(object_distance_array)
        return object_distance

    def object_distance_pub_callback(self):                                        
        self.object_distance_pub_.publish(self.object_distance_msg)

        
def main(args=None):
    rclpy.init(args=args)
    lidar_processor = sesnsor_processor()
    executor = MultiThreadedExecutor()
    executor.add_node(lidar_processor)
    try:
        #rclpy.spin(lidar processor)
        lidar_processor.get_logger().info('Beginning lidar processing, shut down with CTRL-C')
        executor.spin()
    except KeyboardInterrupt:
        lidar_processor.get_logger().info('Keyboard interrupt, shutting down.\n')
    lidar_processor.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()