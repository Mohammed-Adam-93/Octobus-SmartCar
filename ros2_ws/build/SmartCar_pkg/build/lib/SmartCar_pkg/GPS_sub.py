import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor


class GPS_SUB(Node):
    def __init__(self):
        super().__init__('GPS_sub')
        gps_sub_callback_group = MutuallyExclusiveCallbackGroup()
        self.gps_subscriber = self.create_subscription(
            NavSatFix,
            '/fix',
            self.gps_listener_callback,
            10,
            callback_group=gps_sub_callback_group
        )
        self.gps_subscriber
        self.get_logger().info('GPS Subscriber Node(GPS_sub) Started. Waiting for msg from "/fix"')


    def gps_listener_callback(self, msg):
        self.get_logger().info(f'Satalite Messageis: {msg}')

def main(args=None):
    rclpy.init(args=args)
    GPS_subscriber = GPS_SUB()
    executor = MultiThreadedExecutor()
    executor.add_node(GPS_subscriber)
    try:
        #rclpy.spin(GPS_subscriber)
        GPS_subscriber .get_logger().info('Beginning GPS subscriber, shut down with CTRL-C')
        executor.spin()
    except KeyboardInterrupt:
        GPS_subscriber .get_logger().info('Keyboard interrupt, shutting down.\n')
    GPS_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()