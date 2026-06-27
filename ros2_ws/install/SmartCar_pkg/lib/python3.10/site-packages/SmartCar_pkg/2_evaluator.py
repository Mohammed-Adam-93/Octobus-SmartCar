import rclpy
from rclpy.node import Node
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from octopus_interfaces.msg import SensorIndex
from std_msgs.msg import String
from octopus_interfaces.msg import ObjectDistance

class evaluator(Node):
    def __init__(self):
        super().__init__('evaluator_node')
        evaluator_callback_group = MutuallyExclusiveCallbackGroup()
        self.lidar_evaluator_subscriber = self.create_subscription(
            SensorIndex,
            'lidar_validated',
            self.lidar_evaluator_listener,
            10,
            callback_group=evaluator_callback_group
        )
        self.lidar_evaluator_subscriber
        self.get_logger().info('Evaluator Node Started. Waiting for sensor msgs')

        self.count = 0

        self.event_pub_ = self.create_publisher(String, 'event', 10)
        event_pub_period = 0.01
        self.event_pub_timer = self.create_timer(event_pub_period, self.event_pub_timer, evaluator_callback_group)
        self.event_msg = String()

        self.object_distance_sub = self.create_subscription(
            ObjectDistance,
            'object_distance',
            self.object_distance_listener_callback,
            10 ,
            callback_group=evaluator_callback_group)
        self.object_distance_sub # prevent unused variable warning
        self.object_distance_msg = ObjectDistance()

        self.executor_evaluator_subscriber = self.create_subscription(
            String,
            'execution_event',
            self.executor_evaluator_listener,
            10,
            callback_group=evaluator_callback_group
        )
        self.executor_evaluator_subscriber
        self.executor_evaluator_msg = String()

    def lidar_evaluator_listener(self, msg):
        self.get_logger().info(f'Lidar Validity Message is: {msg}')

    def object_distance_listener_callback(self, msg):
        self.object_distance_msg = msg
        if msg is not None:
            self.get_logger().info(f'Object Detected)')

    def executor_evaluator_listener(self, msg):
        self.executor_evaluator_msg.data = msg.data
        self.get_logger().info(f'executor_evaluator_msg: {msg.data}')

    def event_pub_timer(self):
        if self.count < 5.0:
            self.event_msg.data = 'INIT_STATE'
        else:
            self.event_msg.data = 'INIT_DONE'
        if self.executor_evaluator_msg.data == 'NOT_EXECUTED' or self.executor_evaluator_msg.data == 'NOT_EXECUTING':
            self.event_msg.data = 'EXECUTION_FAILURE'
        if self.executor_evaluator_msg.data == 'EXECUTED':
            self.event_msg.data = 'EXECUTION_SUCCESS'
        self.event_pub_.publish(self.event_msg)
        self.count = self.count + 0.01
        self.get_logger().info(f'executor_evaluator_msg:{self.executor_evaluator_msg.data}')


def main(args=None):
    rclpy.init(args=args)
    Lidar_evaluator_sub = evaluator()
    executor = MultiThreadedExecutor()
    executor.add_node(Lidar_evaluator_sub)
    try:
        #rclpy.spin(Lidar_evaluator_sub)
        Lidar_evaluator_sub .get_logger().info('Beginning LiDAR Evaluator subscriber, shut down with CTRL-C')
        executor.spin()
    except KeyboardInterrupt:
        Lidar_evaluator_sub.get_logger().info('Keyboard interrupt, shutting down.\n')
    Lidar_evaluator_sub.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()