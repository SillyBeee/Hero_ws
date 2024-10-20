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
        
            /**
            *
            * @brief 用于创建一个重投影器对象       
            * */
            std::unique_ptr<DoReproj> create_reprojector();
            
            /** 
            *
            * @brief 用于创建一个子弹检测器对象
            */
            std::unique_ptr<DetectBullet> create_ballet_dectector();
            
            /** 
            *
            * @brief 用于订阅图像消息，并调用检测器进行检测
            */
            void ImageCallback(const sensor_msgs::msg::Image::SharedPtr msg);
            
            /** 
            * @brief 创建一个调试发布者，用于发布标有子弹位置的图像
            */
            void CreateDebugPublishers();
            
            /** 
            * @brief 销毁调试发布者
            */
            void DestroyDebugPublishers();
            
            bool debug_;
            

            
            
            
    };



}













    
