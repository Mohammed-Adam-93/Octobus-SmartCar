import rclpy
from rclpy.node import Node
import time
import serial
from std_msgs.msg import String
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

class ARDUINO_COM(Node):
    def __init__(self):
        #Define the subscriber node, to which you send your messages
        super().__init__('ARDUINO_sub') 

        #Group your callback functions
        ARDUINO_callback_group = MutuallyExclusiveCallbackGroup()

        # Pass pararmeters to define the subscriber
        self.ArdPi_sub = self.create_subscription(
            String,
            'COM3_topic',
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
            timeout=2           # time for readline           
        )
        time.sleep(2)

        # The sender_timer timer 
        self.move_msg = String()
        self.move_msg_old = String()
        self.move_msg_timer = self.create_timer(0.01, self.sender_timer, callback_group = ARDUINO_callback_group)


    # Callback for the subscriber
    def COM3_callback(self, msg):
        if msg.data == None:
            return
        self.move_msg.data = msg.data
        self.get_logger().info(f'Recieved message: {self.move_msg.data}')

    # This will send your move_msg
    def sender_timer(self):
        if self.move_msg.data == None:
            self.get_logger().info('Waiting for move_msg...')
            return
        self.get_logger().info(f'the sender_timer captured the message: {self.move_msg.data}')
        if self.move_msg.data == self.move_msg_old.data:
            self.get_logger().info('Send new move_message')
            return
        else:
            self.send_command(self.move_msg.data)
            self.move_msg_old.data = self.move_msg.data

    # This function prepares the message to arduino
    def send_command(self,cmd):
        # send comand and wait ACK
        full_cmd = cmd.strip()+"\n"
        self.ser.write(full_cmd.encode())

        self.get_logger().info(f"Sent: {cmd}")

        ack = self.ser.readline().decode().strip()

        if ack == "":
            self.get_logger().info("ERROR: NO ACK recieved (timeout)")
            return None
        self.get_logger().info(f"Recieved ACK: {ack}")
        return ack

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