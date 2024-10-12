# `ola_n84` package
ROS 2 C++ package.  [![Static Badge](https://img.shields.io/badge/ROS_2-Humble-34aec5)](https://docs.ros.org/en/humble/)

A package egy node-ból áll, ez a turtlesim szimulátorban képes a trajektóra kirajzolásával egy "Csillag alakzat" előállítására. A hirdetett topic `geometry_msgs/twist` típusú. Megvalósítás `ROS 2 Humble` alatt.

This package consist of one node. The aim of the node is to draw a simplified "Star shape". The type of the published topic is `geometry_msgs/twist`. This package builds in `ROS 2 Humble`.
## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/olhdniel/ola_n84
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select ola_n84 --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r
ros2 launch ola_n84 sim.launch.py
```
``` r
ros2 run ola_n84 star_draw
```
![](img/stardraw.gif)

## Graph

The `/star_draw` node publishes a `/turtle1/cmd_vel` topic (type: `geometry_msgs/Twist`) and ths simulator node (`/sim`) subscribes to the command topic.

```mermaid
flowchart TD

U([/star_draw]):::red -->  CMD[ /turtle1/cmd_vel<br/>geometry_msgs/Twist]:::light --> S([/sim]):::red

classDef light fill:#34aec5,stroke:#152742,stroke-width:2px,color:#152742  
classDef dark fill:#152742,stroke:#34aec5,stroke-width:2px,color:#34aec5
classDef white fill:#ffffff,stroke:#152742,stroke-width:2px,color:#152742
classDef red fill:#ef4638,stroke:#152742,stroke-width:2px,color:#fff

```

``` r 
ros2 topic type /turtle1/cmd_vel

geometry_msgs/msg/Twist
```