import rclpy
from rclpy.node import Node
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from octopus_interfaces.msg import ObjectDistance
from octopus_interfaces.msg import MoveIntent
from std_msgs.msg import String

class supervisorNode(Node):

    def __init__(self):
        super().__init__('supervisor_node')
        supervisor_execution_group = MutuallyExclusiveCallbackGroup()
        custom_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            durability=DurabilityPolicy.VOLATILE
        )
        self.movePermit_sub = self.create_subscription(
            MoveIntent,
            'intent',
            self.movePermit_listener_callback,
            custom_qos ,
            callback_group=supervisor_execution_group)
        self.movePermit_sub # prevent unused variable warning
        self.movePermit_msg = MoveIntent()

        self.permit_pub_ = self.create_publisher(MoveIntent, 'permit', 10)
        permit_pub_period = 0.1
        self.permit_pub_timer = self.create_timer(permit_pub_period, self.permit_pub_timer, supervisor_execution_group)
        
        self.event_sub = self.create_subscription(
            String,
            'event',
            self.event_listener_callback,
            custom_qos ,
            callback_group=supervisor_execution_group)
        self.event_sub # prevent unused variable warning
        self.event_msg = String()

        self.state_machine = String()

        self.intent_sub = self.create_subscription(
            MoveIntent,
            'intent',
            self.intent_listener_callback,
            custom_qos ,
            callback_group=supervisor_execution_group)
        self.intent_sub # prevent unused variable warning
        self.intent_msg = MoveIntent()

    def movePermit_listener_callback(self, msg):
        self.movePermit_msg = msg
        #self.get_logger().info(f'I heard: {msg}')

    def event_listener_callback(self, msg):
        self.event_msg= msg
        #self.get_logger().info(f'I heard event: {msg}')

    def intent_listener_callback(self, msg):
        self.intent_msg = msg
        #self.get_logger().info(f'I heard intent: {msg}')
        
    def permit_pub_timer(self):
        #self.movePermit_msg.permission = 'YES'
        if self.event_msg.data == 'INIT_STATE':
            self.state_machine.data = 'INIT'
            self.movePermit_msg.permission = 'NO'
        else:
             
            if self.event_msg.data == 'INIT_DONE':
                self.state_machine.data = 'IDLE'
                self.movePermit_msg.permission = 'YES' 
            if self.event_msg.data == 'EXECUTION_FAILURE':
                self.state_machine.data = 'ERROR'
                self.movePermit_msg.permission = 'NO'            
            if self.event_msg.data == 'EXECUTION_SUCCESS':
                if self.intent_msg.direction != 'STOP':
                    self.state_machine.data = 'EXECUTING_COMMAND' 
                else:
                    self.state_machine.data = 'IDLE'
                self.movePermit_msg.permission = 'YES'   
            else:
                self.state_machine.data = 'UNDEFINED'
                self.movePermit_msg.permission = 'YES'       
        self.permit_pub_.publish(self.movePermit_msg)
        self.get_logger().info(f'Permit being published: {self.movePermit_msg.direction} at speed {self.movePermit_msg.speed}, msg permission: {self.movePermit_msg.permission}')
        self.get_logger().info(f'current state machine: {self.state_machine.data}')


def main(args=None):
    rclpy.init(args=args)
    behavior_subPub = supervisorNode()
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