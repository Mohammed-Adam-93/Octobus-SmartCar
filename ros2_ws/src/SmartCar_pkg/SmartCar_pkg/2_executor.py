import rclpy
from rclpy.node import Node
import time
import serial
from std_msgs.msg import String
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from octopus_interfaces.msg import MoveIntent

class ARDUINO_COM(Node):
    def __init__(self):
        #Define the subscriber node, to which you send your messages
        super().__init__('ARDUINO_sub') 

        #Group your callback functions
        ARDUINO_callback_group = MutuallyExclusiveCallbackGroup()

        # Pass pararmeters to define the subscriber
        self.ArdPi_sub = self.create_subscription(
            MoveIntent,
            'permit',
            self.COM3_callback, 
            10,
            callback_group=ARDUINO_callback_group)                # Moved the queue size to this line
        # Prevent unused variable warning
        self.ArdPi_sub
        self.get_logger().info('ARDUINO UNO Subscriber Node(ARDUINO_sub) Started. Send msg to "COM3_topic"')

        # Connect to the Ardunio
        self.ser = serial.Serial(
            '/dev/ttyACM0',
            115200,
            timeout=1          # time for readline           
        )
        #time.sleep(0.1)

        # The sender_timer timer 
        self.move_msg = MoveIntent()
        self.move_msg_old = MoveIntent()
        self.move_msg_timer = self.create_timer(0.05, self.sender_timer, callback_group = ARDUINO_callback_group)

        # This to communicate events to the evaluator
        self.execution_event_pub_ = self.create_publisher(String, 'execution_event', 1)
        execution_event_pub_period = 0.01
        self.execution_event_pub_timer = self.create_timer(execution_event_pub_period, self.execution_event_pub_timer, ARDUINO_callback_group)
        self.execution_event_msg = String()


    # Callback for the subscriber
    def COM3_callback(self, msg):
        if msg.permission == '' or msg.direction == '':
            return
        self.move_msg = msg
        self.get_logger().info(f'Recieved message: {self.move_msg.permission}')

    # This will send your move_msg
    def sender_timer(self):
        if self.move_msg.permission == 'YES':
            self.get_logger().info('Permission granted...')        
            if self.move_msg.direction == 'STOP':
                self.send_command(self.move_msg.direction)
                self.move_msg_old = self.move_msg            
            else:
                self.send_command(self.move_msg.direction + ' ' + str(self.move_msg.speed))
                self.move_msg_old = self.move_msg
            return
        else:
            self.get_logger().info('Permission denied ...')

    # This function prepares the message to arduino
    def send_command(self,cmd):
        # send comand and wait ACK
        full_cmd = cmd.strip()+"\n"
        self.ser.write(full_cmd.encode())

        self.get_logger().info(f"Sent: {cmd}")

        ack = self.ser.readline().decode().strip()
       
        if ack == "":        
            self.get_logger().info("ERROR: NO ACK recieved (timeout)")
            self.execution_event_msg.data = 'NOT_EXECUTED'
            return None
        self.get_logger().info(f"Recieved ACK: {ack}")
        self.execution_event_msg.data = 'EXECUTED'
        return ack

    def execution_event_pub_timer(self):
        #if self.execution_event_msg.data == '':
            #return
        self.execution_event_pub_.publish(self.execution_event_msg)

def main(args=None):
    rclpy.init(args=args)
    COM3_subscriber=ARDUINO_COM()
    executor = MultiThreadedExecutor()
    executor.add_node(COM3_subscriber)
    try:
        #rclpy.spin(DCM_subscriber)
        COM3_subscriber.get_logger().info('Beginning ARDUINO-Pi subscriber, shut down with CTRL-C')
        executor.spin()
    except KeyboardInterrupt:
        COM3_subscriber.get_logger().info('Keyboard interrupt, shutting down.\n')
    COM3_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()