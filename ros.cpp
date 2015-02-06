/**
 * FILE: ros.cpp 
 * AUTHOR: avadendas
 * DESCRIPTION: The most vanilla ros template. 
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

#include <ros/ros.h>

// motors
#include <irat_msgs/IRatVelocity.h>

// for keyboard input 
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

using namespace std;

/**
 * Example callback 
 */
void example_callback(messageConstPtr ptr, other params) {
  return;
}

int main(int argc, char** argv) {
  // Get the iRat name 
  const char * irat_id_const_char_star = getenv("IRAT_ID");
  string irat_id;
  string topic;

  if(!irat_id_const_char_star) {
    std::cout << "IRAT_ID not set, setting to" << " irat_red" << endl;
    irat_id = "irat_red";
  } else {
    irat_id = irat_id_const_char_star;
  }
  
  // Initialise node 
  ros::init(argc, argv, irat_id+"name");
  ros::NodeHandle node("~");
  
  // set topic root from launch file/command line
  node.param("topic", topic, string("/irat_red"));

  // Example publisher 
  ros::Publisher pub_cmdvel = node.advertise<irat_msgs::IRatVelocity>("",1);
  // Example message
  irat_msgs::IRatVelocity cmdvel_msg;

  // Rate limiter 
  ros::Rate rate(30.0);

  while(node.ok()) {
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}
