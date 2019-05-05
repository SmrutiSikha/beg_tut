#include "ros/ros.h"
#include "std_msgs/Int32.h"

#include <sstream>
int main(int argc, char **argv)
{
  ros::init(argc, argv, "node1");
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("chatter", 1000);

  ros::Rate loop_rate(10);
  int count = 1;
  while (ros::ok())
  {
    std_msgs::Int32 msg;

 
    msg.data = count;

    std::cout<<msg.data<<std::endl;
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
