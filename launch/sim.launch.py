from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='turtlesim',
            
            executable='turtlesim_node',
            name='sim'
        ),
        
         Node(
             package='ola_n84',
             executable='star_draw',
             output='screen',
         ),
    ])