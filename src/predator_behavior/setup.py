from setuptools import find_packages, setup

package_name = 'predator_behavior'

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
            "behavior_manager_node = predator_behavior.behavior_manager_node:main",
            "safety_supervisor_node = predator_behavior.safety_supervisor_node:main"
        ],
    },
)
