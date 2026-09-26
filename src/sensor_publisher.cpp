#include <chrono>
#include <cmath>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

using namespace std::chrono_literals;

class SinePublisher : public rclcpp::Node {
public:
  SinePublisher() : Node("sensor_publisher"), time_(0.0) {
    publisher_ = this->create_publisher<std_msgs::msg::Float64>("szinusz_jel", 10);
    
    timer_ = this->create_wall_timer(
      50ms, std::bind(&SinePublisher::timer_callback, this));
    
    RCLCPP_INFO(this->get_logger(), "Szinuszjel generáló elindult.");
  }

private:
  void timer_callback() {
    auto message = std_msgs::msg::Float64();
    
    message.data = std::sin(time_);
    
    RCLCPP_INFO(this->get_logger(), "Küldött Szinusz jel: %.3f", message.data);
    publisher_->publish(message);
    
    
    time_ += 0.1;
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
  double time_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SinePublisher>());
  rclcpp::shutdown();
  return 0;
}