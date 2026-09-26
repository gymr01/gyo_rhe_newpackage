from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='gyo_rhe_sintotriangle',
            executable='sensor_publisher',
            name='sensor_publisher_node',
            output='screen'
        ),
        Node(
            package='gyo_rhe_sintotriangle',
            executable='sensor_subscriber',
            name='sensor_subscriber_node',
            output='screen'
        ),
    ])