# Szinusz jel háromszög jellé alakítása.

## Packages and build

It is assumed that the workspace is `~/ros2_ws/`.

### Clone the packages
``` r
cd ~/ros2_ws/src
```
``` r
git clone https://github.com/gymr01/gyo_rhe_sintotriangle.git
```

### Build ROS 2 packages
``` r
cd ~/ros2_ws
```
``` r
colcon build --packages-select gyo_rhe_sintotriangle --symlink-install
```

<details>
<summary> Don't forget to source before ROS commands.</summary>

``` bash
source ~/ros2_ws/install/setup.bash
```
</details>

``` r
ros2 launch ros2_cpp_template launch_example1.launch.py
```

### Eredmény
![alt text]([src/img/img.png])
