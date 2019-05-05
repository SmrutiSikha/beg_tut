#include "ros/ros.h"
#include "std_msgs/Int32.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
int num;
void chatterCallback(const std_msgs::Int32::ConstPtr& msg)
{
  num=msg->data;
  std::cout<<num<<std::endl;
  
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "node2");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
   ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("chatter1", 1000);
  ros::Rate loop_rate(10);
 // int count = 0;
  while (ros::ok())
  {
    std_msgs::Int32 msg1;
    msg1.data = num*num;

    std::cout<<msg1.data<<std::endl;
    chatter_pub.publish(msg1);

    ros::spinOnce();

    loop_rate.sleep();
   // ++count;
  }


  return 0;
  ros::spin();

  return 0;
}
