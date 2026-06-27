from setuptools import find_packages
from setuptools import setup

setup(
    name='octopus_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('octopus_interfaces', 'octopus_interfaces.*')),
)
