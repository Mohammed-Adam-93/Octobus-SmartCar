import rclpy
from rclpy.node import Node
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from octopus_interfaces.msg import ObjectDistance

class behaviorNode(Node):

    def __init__(self):
        super().__init__('behavior_node')
        self.behavior_sub = self.create_subscription(
            ObjectDistance,
            'object_distance',
            self.behavior_listener_callback,
            10)
        self.behavior_sub # prevent unused variable warning

    def behavior_listener_callback(self, msg):
        self.get_logger().info(f'I heard: {msg}')


def main(args=None):
    rclpy.init(args=args)

    behavior_subPub = behaviorNode()

    rclpy.spin(behavior_subPub )

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    behavior_subPub .destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()