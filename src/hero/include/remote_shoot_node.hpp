#pragma once 
#include "rclcpp/rclcpp.hpp"
#include "detect_bullet.hpp"
#include "do_reproj.hpp"
#include <image_transport/image_transport.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <cv_bridge/cv_bridge.h>
namespace armor{
    class Remote_shoot_node : public rclcpp::Node {
        public: 
            explicit Remote_shoot_node(const rclcpp::NodeOptions& options);

        private:
        
            std::unique_ptr<DoReproj> create_reprojector();
    }

















    
}