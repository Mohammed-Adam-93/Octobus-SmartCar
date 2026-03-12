import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

from mpu9250_jmdev.registers import *
from mpu9250_jmdev.mpu_9250 import MPU9250

class MPU_PUB(Node):
    def __init__(self):
        super().__init__('MPU_pub') 
        imu_pub_callback_group = MutuallyExclusiveCallbackGroup()
        self.mpu_pub_ = self.create_publisher(Imu, 'imu/data', 10)
        imu_pub_period = 0.01
        mpu_pub_timer = self.create_timer(imu_pub_period, self.imu_timer, imu_pub_callback_group)
        self.get_logger().info('MPU Sensor Publisher (MPU_pub) Node Started. Publishing to "/imu/data"')
        self.msg = Imu()
        self.mpu = MPU9250(
            address_ak=AK8963_ADDRESS, 
            address_mpu_master=MPU9050_ADDRESS_68, # In 0x68 Address
            address_mpu_slave=MPU9050_ADDRESS_68,
            bus=1,
            gfs=GFS_1000, 
            afs=AFS_8G, 
            mfs=AK8963_BIT_16, 
            mode=AK8963_MODE_C100HZ)
        self.mpu.configure() 
        
    def imu_timer(self): 
        self.msg.header.stamp = self.get_clock().now().to_msg()
        self.msg.header.frame_id     = "imu_link"
        self.msg.orientation_covariance[0] = -1.0
        self.msg.angular_velocity.x = float(self.mpu.readGyroscopeMaster()[0])
        self.msg.angular_velocity.y = float(self.mpu.readGyroscopeMaster()[1])
        self.msg.angular_velocity.z = float(self.mpu.readGyroscopeMaster()[2])
        self.msg.linear_acceleration.x = float(self.mpu.readAccelerometerMaster()[0])
        self.msg.linear_acceleration.y = float(self.mpu.readAccelerometerMaster()[1])
        self.msg.linear_acceleration.z = float(self.mpu.readAccelerometerMaster()[2])
        self.mpu_pub_.publish(self.msg)
        

def main(args=None):
    rclpy.init(args=args)
    MPU_publisher=MPU_PUB()
    executor = MultiThreadedExecutor()
    executor.add_node(MPU_publisher)
    try:
        #rclpy.spin(DCM_subscriber)
        MPU_publisher.get_logger().info('Beginning MPU publisher, shut down with CTRL-C')
        executor.spin()
    except KeyboardInterrupt:
        MPU_publisher.get_logger().info('Keyboard interrupt, shutting down.\n')
    MPU_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()



#while True:
    #print("|.....MPU9250 in 0x68 Address.....|")
    #print("Accelerometer", mpu.readAccelerometerMaster())
    #print("Gyroscope", mpu.readGyroscopeMaster())
    #print("Magnetometer", mpu.readMagnetometerMaster())
    #print("Temperature", mpu.readTemperatureMaster())
    #print("\n")
    #time.sleep(1)

#Accelerometer 	g (1g = 9.80665 m/s²)
#Gyroscope 	degrees per second (°/s)
#Magnetometer 	microtesla (μT)
#Temperature 	celsius degrees (°C)