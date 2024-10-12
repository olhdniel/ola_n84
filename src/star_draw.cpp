#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "turtlesim/msg/pose.hpp"

class StarDraw : public rclcpp::Node
{
public:
    StarDraw() : Node("star_draw"), count_(0)
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(1), std::bind(&StarDraw::loop, this)); 
        RCLCPP_INFO_STREAM(this->get_logger(), "Drawing a star to turtlesim.");
        loop();
    }

private:
    void publish_message(double fwd, double turn)
    {
        auto message = geometry_msgs::msg::Twist();
        message.linear.x = fwd;
        message.angular.z = turn;
        count_++;
        RCLCPP_INFO(this->get_logger(), "Step %ld. speed: '%.1f' turn: '%.1f'", count_, message.linear.x, message.angular.z);
        publisher_->publish(message);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    void loop()
    {
        RCLCPP_INFO_STREAM(this->get_logger(), "Loop started.");
        std::this_thread::sleep_for(std::chrono::seconds(2));
        for (int i = 0; i < 10; i++)
        {
            publish_message(1.0, 0.0); // move forward
            
            if (i%2==0)
            {
                publish_message(0.0, M_PI-M_PI*0.6 ); // turn 180-108 degrees left
            }
            else
            {
                publish_message(0.0, -1*(M_PI-M_PI*0.2) ); // turn 180-36 degrees right
            }
        }
        /* publish_message(1.0, 0.0); // move forward
        publish_message(0.0,  M_PI*0.2 ); // turn
        publish_message(1.0, 0.0); // move forward
        publish_message(0.0, -1* M_PI*0.6 ); // turn
        publish_message(1.0, 0.0); // move forward
        publish_message(0.0,  M_PI*0.2 ); // turn
        publish_message(1.0, 0.0); // move forward
        publish_message(0.0, -1* M_PI*0.6 ); // turn
        publish_message(1.0, 0.0); // move forward
        publish_message(0.0,  M_PI*0.2 ); // turn
        publish_message(1.0, 0.0); // move forward
        publish_message(0.0, -1* M_PI*0.6 ); // turn
        publish_message(1.0, 0.0); // move forward
        publish_message(0.0,  M_PI*0.2 ); // turn
        publish_message(1.0, 0.0); // move forward
        publish_message(0.0, -1* M_PI*0.6 ); // turn
        publish_message(1.0, 0.0); // move forward
        publish_message(0.0,  M_PI*0.2 ); // turn
        publish_message(1.0, 0.0); // move forward
        publish_message(0.0, -1* M_PI*0.6 ); // turn */

        RCLCPP_INFO_STREAM(this->get_logger(), "Program finished");
        rclcpp::shutdown();
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    size_t count_;
};  

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<StarDraw>());
    //rclcpp::shutdown();
    return 0;
}