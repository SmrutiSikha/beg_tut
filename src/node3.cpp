#include "ros/ros.h"
#include "std_msgs/Int32.h"
int n1,n2;
void chatterCallback(const std_msgs::Int32::ConstPtr& msg)
{
	n1=msg->data;
  std::cout<<n1;
}
void chatter1Callback(const std_msgs::Int32::ConstPtr& msg1)
{
	n2=msg1->data;
  std::cout<<" "<<n2<<std::endl;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "node3");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ros::Subscriber sub1 = n.subscribe("chatter1", 1000, chatter1Callback);
  ros::spin();

  return 0;
}
