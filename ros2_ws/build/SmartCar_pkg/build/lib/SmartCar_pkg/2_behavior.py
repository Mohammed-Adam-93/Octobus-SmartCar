import rclpy
from rclpy.node import Node
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from octopus_interfaces.msg import ObjectDistance
from octopus_interfaces.msg import MoveIntent


class behaviorNode(Node):

    def __init__(self):
        super().__init__('behavior_node')
        behavior_execution_group = MutuallyExclusiveCallbackGroup()
        custom_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            durability=DurabilityPolicy.VOLATILE
        )
        self.behavior_sub = self.create_subscription(
            ObjectDistance,
            'object_distance',
            self.behavior_listener_callback,
            custom_qos ,
            callback_group=behavior_execution_group)
        self.behavior_sub # prevent unused variable warning
        self.object_distance_msg = ObjectDistance()

        self.intent_pub_ = self.create_publisher(MoveIntent, 'intent', 10)
        intent_pub_period = 0.01
        self.intent_pub_timer = self.create_timer(intent_pub_period, self.intent_pub_timer, behavior_execution_group)
        self.intent_MSG = MoveIntent()
        self.count = 0

    def behavior_listener_callback(self, msg):
        self.object_distance_msg = msg
        self.get_logger().info(f'I heard: {msg}')

    def intent_pub_timer(self):
        l = self.object_distance_msg.left
        r = self.object_distance_msg.right
        m = self.object_distance_msg.middle
        if l <= 1.00 or m <= 1.00 or r <= 1.00:
            while self.count < 300:
                self.intent_MSG.direction = 'TURN RIGHT'
                self.intent_MSG.speed = 150
                self.count = self.count + 1
                return
            self.intent_MSG.direction = 'STOP'
            self.intent_MSG.speed = 40
        else:
            self.intent_MSG.direction = 'MOVE FWD'
            self.intent_MSG.speed = 60

        self.intent_pub_.publish(self.intent_MSG)
        self.get_logger().info(f'Intent being published: {self.intent_MSG.direction} at speed {self.intent_MSG.speed}')



def main(args=None):
    rclpy.init(args=args)
    behavior_subPub = behaviorNode()
    executor = MultiThreadedExecutor()
    executor.add_node(behavior_subPub)
    try:
        #rclpy.spin(behavior_subPub)
        behavior_subPub.get_logger().info('Beginning lidar processing, shut down with CTRL-C')
        executor.spin()
    except KeyboardInterrupt:
        behavior_subPub.get_logger().info('Keyboard interrupt, shutting down.\n')
    behavior_subPub.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()