from setuptools import find_packages, setup

package_name = 'SmartCar_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='mohammed',
    maintainer_email='mo.adam@octopus.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'Pi_Ard_sub_node = SmartCar_pkg.Pi_Ard_sub:main',
            'Pi_Ard_pub_node = SmartCar_pkg.Pi_Ard_pub:main',
            'GPS_sub_node    = SmartCar_pkg.GPS_sub:main',
            'MPU_pub_node    = SmartCar_pkg.MPU_pub:main',
            'LIDAR_sub_node  = SmartCar_pkg.LIDAR_sub:main',
        ],
    },
)
