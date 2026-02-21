# SmartCar- ROS2 Autonomous Mobile Platform under active development

![Octobus_The_SmartCar](SmartCar_3.jpeg)

# System Architecture
![Octobus_The_SmartCar](SystemArch_1.png)

# HardWare LayOut
![Octobus_The_SmartCar](HW_LayOut.png)

# Goals
- Develop a modular ROS2-based autonomous platform
- Implement multi-sensor fusion (LiDAR + IMU + GPS)
- Design scalable software architecture
- Enable reproducible hardware-software integration

# Current Capabilities
- Motor control via Arduino + ROS2 interface
- Encoder-based velocity estimation
- LiDAR integration (YDLIDAR Tmini Plus)
- IMU data publishing
- GPS integration
- Basic obstacle detection

# In Progress
- Sensor fusion (EKF)
- Robust obstacle avoidance logic
- Nav2 integration
- Autonomous waypoint navigation
  
# Installations
1. Install Ubuntu 22.04
2. Install ROS2 Humble
3. Clone repository:
   git clone ...
4. Build workspace:
   colcon build
5. Source:
   source install/setup.bash
