import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

class ARDUINO_PUB(Node):
    def __init__(self):
        super().__init__('ARDUINO_pub') 
        ARDUNIO_pub_callback_group = MutuallyExclusiveCallbackGroup()
        self.ArdPi_pub_ = self.create_publisher(String, 'COM3_topic', 10)
        ArdPi_pub_period = 1
        ArdPi_pub_timer = self.create_timer(ArdPi_pub_period, self.pub_timer, ARDUNIO_pub_callback_group)
        self.get_logger().info('ARDUINO UNO Publisher (ARDUINO_PUB) Node Started. Publishing to "/COM3_topic"')
        self.cnt = 0
        self.msg = String()

    def pub_timer(self):    
        if self.cnt == 3:
            self.msg.data = "MOVE FWD 90"
            self.ArdPi_pub_.publish(self.msg)
            self.get_logger().info(f' Message being published: {self.msg.data}, after {self.cnt} seconds')
        if self.cnt == 14:
            self.msg.data = "STOP"
            self.ArdPi_pub_.publish(self.msg)
            self.get_logger().info(f' Message being published: {self.msg.data}, after {self.cnt} seconds')
        if self.cnt == 20:
            self.msg.data = "MOVE BWD 90"
            self.ArdPi_pub_.publish(self.msg)
            self.get_logger().info(f' Message being published: {self.msg.data}, after {self.cnt} seconds')
        if self.cnt == 29:
            self.msg.data = "STOP"
            self.ArdPi_pub_.publish(self.msg)
            self.get_logger().info(f' Message being published: {self.msg.data}, after {self.cnt} seconds')
        self.cnt += 1

def main(args=None):
    rclpy.init(args=args)
    COM3_publisher=ARDUINO_PUB()
    executor = MultiThreadedExecutor()
    executor.add_node(COM3_publisher)
    try:
        #rclpy.spin(DCM_subscriber)
        COM3_publisher.get_logger().info('Beginning ARDUINO-Pi publisher, shut down with CTRL-C')
        executor.spin()
    except KeyboardInterrupt:
        COM3_publisher.get_logger().info('Keyboard interrupt, shutting down.\n')
    COM3_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()