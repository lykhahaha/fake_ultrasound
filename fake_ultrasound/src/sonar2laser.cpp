
#include "ros/ros.h" 
#include <sensor_msgs/Range.h> 
#include <sensor_msgs/LaserScan.h>
#include <signal.h>
using namespace std;

class Sonar2laser{

public:
    Sonar2laser();
//  ~Sonar2laser();
    
private:
    ros::NodeHandle n;
    ros::Publisher laser_pub;
    ros::Subscriber sonar_sub;
    void sonarCallback(const sensor_msgs::Range::ConstPtr& msg);
}; 

Sonar2laser::Sonar2laser()    
{
    laser_pub = n.advertise<sensor_msgs::LaserScan>("/fake_sacn",1);
    sonar_sub = n.subscribe<sensor_msgs::Range>("/FrontUltraSoundPublisher",1,&Sonar2laser::sonarCallback,this);     
}
/*
Sonar2laser::~Sonar2laser()
    {
    }
*/ 
void Sonar2laser::sonarCallback(const sensor_msgs::Range::ConstPtr& msg)
    {
    sensor_msgs::LaserScan scan;
    scan.header.stamp = ros::Time::now();
//  scan.header.frame_id = "/base_laser";
    scan.header.frame_id = "/FrontUltraSoundPublisher";
    scan.ranges.resize(1);
    scan.angle_min = 0;
    scan.angle_max = 3;
    scan.range_min = 0;
    scan.range_max = 10;
    scan.ranges[0]= msg->range;   
    laser_pub.publish(scan);
}

int main(int argc, char** argv)

{
	ros::init(argc, argv, "sonar_laser_publisher");
	Sonar2laser ar;
	ros::spin();

}
   
