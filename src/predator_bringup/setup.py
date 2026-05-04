from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'predator_bringup'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # Install all launch files
        (os.path.join('share', package_name, 'launch'),
            glob('launch/*.launch.py')),
        # Install all config files
        (os.path.join('share', package_name, 'config'),
            glob('config/*.yaml')),
        # Install maps (if any)
        (os.path.join('share', package_name, 'maps'),
            glob('maps/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ken-lbv',
    maintainer_email='ken-lbv@todo.todo',
    description='Launch files, parameters and maps for the predator system',
    license='TODO: License declaration',
    extras_require={
        'test': ['pytest'],
    },
    entry_points={
        'console_scripts': [],
    },
)
