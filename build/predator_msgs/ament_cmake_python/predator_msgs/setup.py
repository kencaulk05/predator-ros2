from setuptools import find_packages
from setuptools import setup

setup(
    name='predator_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('predator_msgs', 'predator_msgs.*')),
)
