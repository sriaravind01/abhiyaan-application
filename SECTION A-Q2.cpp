#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc,char **argv)
{
 ros::init(argc,argv,"talker");
 ros::NodeHandle nh;
 ros::Publisher pub = nh.advertise<std_msgs::String>("welcome_message",1000);
 ros::Rate loop_rate(4);
 int msg_count=0;
 while (ros::ok())
 {
  std_msgs::String msg;
  
  std::stringstream ss;
  ss<<"welcome to abhiyaan  "<<msg_count;
  msg.data =ss.str();
  

  ROS_INFO("%s",msg.data.c_str());

 
  pub.publish(msg);
  
  ros::spinOnce();
  
  loop_rate.sleep();
  
  msg_count++;
  }
 return 0;
}
  
