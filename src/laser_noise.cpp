#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include <stdio.h>


sensor_msgs::LaserScan noise;
ros::Publisher noise_pub;

int NoiseLength;
int NoiseRange;
int NoisePos;
void chatterCallback(const sensor_msgs::LaserScanConstPtr&  msg)
{
		ros::NodeHandle nh("~");
//	  ROS_INFO("Sonar Seq: [%d]", msg->header.seq);
	//   ROS_INFO("Range: [%f]", msg->range_max);
	    nh.getParam("NoiseLength",NoiseLength); 
//          ROS_INFO("Test");
	    noise.angle_min=msg->angle_min;
	    noise.angle_max=msg->angle_max;
	    noise.angle_increment=msg->angle_increment;
	    noise.scan_time=msg->scan_time;
	    noise.range_min=msg->range_min;
	    noise.range_max=msg->range_max;
	    noise.header.frame_id=msg->header.frame_id;
	    noise.header=msg->header;
	    noise.ranges=msg->ranges;
	   	noise.intensities=msg->intensities;
	    NoiseRange=rand()%20;
		NoisePos=rand()%1300;
		for (int i=NoisePos;i<=NoisePos+NoiseLength;i++)
		{

		noise.ranges[i]=NoiseRange;
		}
	    
		noise_pub.publish(noise);	   
}


int main(int argc, char **argv)
{
	  
	  ros::init(argc, argv, "laser_noise");
	  ros::NodeHandle n;
	  noise_pub=n.advertise<sensor_msgs::LaserScan>("/scan_noise",1000);
	  ros::Subscriber sub = n.subscribe("scan", 1000,chatterCallback);
	  noise_pub.publish(noise);
	  ros::spin();
	  return 0;
}
