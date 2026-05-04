from setuptools import find_packages, setup

package_name = 'predator_perception'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    package_data={'': ['py.typed']},
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ken-lbv',
    maintainer_email='ken-lbv@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            "target_tracker_node = predator_perception.target_tracker_node:main",
            "camera_to_map_transform_node = predator_perception.camera_to_map_transform_node:main",
            "zone_monitor_node = predator_perception.zone_monitor_node:main",
            "velocity_estimator_node = predator_perception.velocity_estimator_node:main"
        ],
    },
)
