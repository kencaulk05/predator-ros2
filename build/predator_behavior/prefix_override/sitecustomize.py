import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/roboticslab/Ros2_predator-project_WS/install/predator_behavior'
