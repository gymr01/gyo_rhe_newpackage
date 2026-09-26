#include <memory>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

class TriangleConverter : public rclcpp::Node {
public:
  TriangleConverter() : Node("sensor_subscriber") {
    subscription_ = this->create_subscription<std_msgs::msg::Float64>(
      "szinusz_jel", 10, 
      std::bind(&TriangleConverter::topic_callback, this, std::placeholders::_1));
    publisher_ = this->create_publisher<std_msgs::msg::Float64>("haromszog_jel", 10);
    
    RCLCPP_INFO(this->get_logger(), "Szinusz -> Háromszög átalakító és publikáló készenlétben.");
  }

private:
  void topic_callback(const std_msgs::msg::Float64::SharedPtr msg) const {
    double sine_val = msg->data;
    
    double triangle_val = (2.0 / M_PI) * std::asin(std::sin(std::asin(sine_val)));

    RCLCPP_WARN(this->get_logger(), 
      "Szinusz: %.3f ➔ Háromszög: %.3f", 
      sine_val, triangle_val);

    auto triangle_msg = std_msgs::msg::Float64();
    triangle_msg.data = triangle_val;
    publisher_->publish(triangle_msg);
  }

  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscription_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TriangleConverter>());
  rclcpp::shutdown();
  return 0;
}