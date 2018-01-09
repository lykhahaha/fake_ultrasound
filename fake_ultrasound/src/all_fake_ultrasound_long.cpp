#include "ros/ros.h"
#include "sensor_msgs/Range.h"
#include "std_msgs/Header.h"
#include <time.h>
#include <sstream>
#include <tf/transform_broadcaster.h>

int main(int argc, char **argv)
{ 
  ros::init(argc, argv, "talkerUltraSound");
  ros::NodeHandle n;
  ros::Publisher ultrasound_pub_after = n.advertise<sensor_msgs::Range>("AfterUltraSoundPublisher", 20);
  ros::Publisher ultrasound_pub_front = n.advertise<sensor_msgs::Range>("FrontUltraSoundPublisher", 20);
  ros::Publisher ultrasound_pub_left = n.advertise<sensor_msgs::Range>("LeftUltraSoundPublisher", 20);
  ros::Publisher ultrasound_pub_right = n.advertise<sensor_msgs::Range>("RightUltraSoundPublisher", 20);
    
  ros::Rate loop_rate(10);
  int count = 0;
  while (ros::ok())
  {

    sensor_msgs::Range after_msg;
    std_msgs::Header after_header;
    after_header.stamp = ros::Time::now();
    after_header.frame_id = "/after_ultrasound";
    after_msg.header = after_header;
    after_msg.field_of_view = 0.6;
    after_msg.min_range = 0;
    after_msg.max_range = 10;
//    msg.range = rand()%3;//rand()%3;
//   after_msg.range = rand()%3+1.5;
//    after_msg.range = rand()%3+7;
    after_msg.range = 10;
    
    sensor_msgs::Range front_msg;
    std_msgs::Header front_header;
    front_header.stamp = ros::Time::now();
    front_header.frame_id = "/front_ultrasound";
    front_msg.header = front_header;
    front_msg.field_of_view = 0.6;
    front_msg.min_range = 0;
    front_msg.max_range = 10;
//    msg.range = rand()%3;//rand()%3;
//    front_msg.range = rand()%3+1.5;
//    front_msg.range = rand()%3+7;
    front_msg.range = 10;
    
    sensor_msgs::Range left_msg;
    std_msgs::Header left_header;
    left_header.stamp = ros::Time::now();
    left_header.frame_id = "/left_ultrasound";
    left_msg.header = left_header;
    left_msg.field_of_view = 0.6;
    left_msg.min_range = 0;
    left_msg.max_range = 10;
//    msg.range = rand()%3;//rand()%3;
//    left_msg.range = rand()%3+1.5;
//    left_msg.range = rand()%3+7;
    left_msg.range = 10;
    
    sensor_msgs::Range right_msg;
    std_msgs::Header right_header;
    right_header.stamp = ros::Time::now();
    right_header.frame_id = "/right_ultrasound";
    right_msg.header = right_header;
    right_msg.field_of_view = 0.6;
    right_msg.min_range = 0;
    right_msg.max_range = 10;
//    msg.range = rand()%3;//rand()%3;
//    right_msg.range = rand()%3+1.5;
//    right_msg.range = rand()%3+7;
    right_msg.range = 10;
/*
    tf::TransformBroadcaster broadcaster;
      broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.1, 0.0, 0.2)),
        ros::Time::now(),"base_link", "after_ultrasound"));

*/

    ultrasound_pub_after.publish(after_msg);
    ultrasound_pub_front.publish(front_msg);
    ultrasound_pub_left.publish(left_msg);
    ultrasound_pub_right.publish(right_msg);    
    loop_rate.sleep();
    ++count;
  }
  return 0;
}
