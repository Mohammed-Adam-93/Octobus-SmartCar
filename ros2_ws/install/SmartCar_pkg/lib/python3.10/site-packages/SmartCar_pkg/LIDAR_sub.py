import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy

class LIDAR_SUB(Node):
    def __init__(self):
        super().__init__('LIDAR_sub')
        lidar_sub_callback_group = MutuallyExclusiveCallbackGroup()
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
            callback_group=lidar_sub_callback_group,  
        )
        self.lidar_subscriber
        self.get_logger().info('LIDAR Subscriber Node(LIDAR_sub) Started. Waiting for msg from "/scan"')


    def lidar_listener_callback(self, msg):
        self.get_logger().info(f'LIDAR Message is: {msg}')

def main(args=None):
    rclpy.init(args=args)
    LIDAR_subscriber = LIDAR_SUB()
    executor = MultiThreadedExecutor()
    executor.add_node(LIDAR_subscriber)
    try:
        #rclpy.spin(GPS_subscriber)
        LIDAR_subscriber .get_logger().info('Beginning LIDAR subscriber, shut down with CTRL-C')
        executor.spin()
    except KeyboardInterrupt:
        LIDAR_subscriber .get_logger().info('Keyboard interrupt, shutting down.\n')
    LIDAR_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()