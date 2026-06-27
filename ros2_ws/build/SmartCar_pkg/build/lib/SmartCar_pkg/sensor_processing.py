import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy

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

        self.lidar_validator_timer = self.create_timer(1.0, self.lidar_validator_callback, callback=sesnsor_processor_group)
        self.lidar_msg = None

    def lidar_listener_callback(self, msg):
        self.get_logger().info(f'LIDAR Message is: {msg}')
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
            if maxRange < 12.0 and minRange > 0.0:
                self.get_logger().info('lidar data is valid')
            pass
        else:
            self.get_logger().info('No lidar data recieved yet')

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