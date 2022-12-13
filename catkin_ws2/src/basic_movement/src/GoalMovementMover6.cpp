#include <ros/ros.h>
#include "std_msgs/String.h"
#include "control_msgs/JointJog.h"
#include "sensor_msgs/JointState.h"

#include <sstream>
/* Create node */
float joint1, joint2, joint3, joint4, joint5, joint6;
bool know_states;

void jointsCallback(const sensor_msgs::JointState::ConstPtr& msg) {
	int i=0;

	for(std::vector<double>::const_iterator it = msg->position.begin(); it != msg->position.end(); ++it) {
		if(i==0) {
			joint1=*it;
		}
		if(i==1) {
			joint2=*it;
		}
		if(i==2) {
			joint3=*it;
		}
		if(i==3) {
			joint4=*it;
		}
		if(i==4) {
			joint5=*it;
		}
		if(i==5) {
			joint6=*it;
		}
		i++;
	}
	know_states=true;
	ROS_INFO("Received State %f\t%f\t%f\t%f\t%f\t%f", joint1, joint2, joint3, joint4, joint5, joint6);
}


int main(int argc, char **argv) {
	know_states=false;
	ros::init(argc, argv, "goal_movement_example");
	ros::NodeHandle n;

	/* Create publisher to attach to JointJog */
	ros::Publisher chatter_pub = n.advertise<control_msgs::JointJog>("/JointJog",1);

	ros::Subscriber chatter_sub = n.subscribe("/joint_states", 1000, jointsCallback);

	ros::Rate loop_rate(10);

	int counter = 0;

	ros::Duration(2.0).sleep();
	while(ros::ok()) {
		if(know_states) {
			float joint1_demand=0.9;
		  float joint2_demand=0.4;
		  float joint3_demand=0.4;
		  float joint4_demand=0.4;
		  float joint5_demand=0.4;
		  float joint6_demand=0.4;

		  float joint1_diff = joint1_demand-joint1;
		  float joint2_diff = joint2_demand-joint2;
		  float joint3_diff = joint3_demand-joint3;
		  float joint4_diff = joint4_demand-joint4;
		  float joint5_diff = joint5_demand-joint5;
		  float joint6_diff = joint6_demand-joint6;
		  
			if(abs(joint1_diff)>0.04) {

				ROS_INFO("Setting message");
				control_msgs::JointJog msg_start;
				std::stringstream ss;
				ss << "joint1";

				msg_start.joint_names.push_back(ss.str());
				msg_start.velocities.push_back(0.25*(joint1_diff)/abs(joint1_diff));
				msg_start.duration=5; //Unfortunately duration isn't implemented...

				ROS_INFO("Sending message");
				chatter_pub.publish(msg_start);
			}
			if(abs(joint1_diff)<0.04) {

				ROS_INFO("Setting message");
				control_msgs::JointJog msg_start;
				std::stringstream ss;
				ss << "joint1";

				msg_start.joint_names.push_back(ss.str());
				msg_start.velocities.push_back(0);
				msg_start.duration=5; //Unfortunately duration isn't implemented...

				ROS_INFO("Sending message");
				chatter_pub.publish(msg_start);
			}
			
			// JOINT 2
			
			if(abs(joint2_diff)>0.04) {
			  
			  ROS_INFO("Setting message");
			  control_msgs::JointJog msg_start;
			  std::stringstream ss;
			  ss << "joint2";
			  
			  msg_start.joint_names.push_back(ss.str());
			  msg_start.velocities.push_back(0.25*(joint2_diff)/abs(joint2_diff));
			  msg_start.duration=5; //Unfortunately duration isn't implemented...
			  
			  ROS_INFO("Sending message");
			  chatter_pub.publish(msg_start);
			}
			if(abs(joint2_diff)<0.04) {
			  
			  ROS_INFO("Setting message");
			  control_msgs::JointJog msg_start;
			  std::stringstream ss;
			  ss << "joint2";
			  
			  msg_start.joint_names.push_back(ss.str());
			  msg_start.velocities.push_back(0);
			  msg_start.duration=5; //Unfortunately duration isn't implemented...
			  
			  ROS_INFO("Sending message");
			  chatter_pub.publish(msg_start);
			}
			
			// JOINT 3
			
			if(abs(joint3_diff)>0.04) {
			  
			  ROS_INFO("Setting message");
			  control_msgs::JointJog msg_start;
			  std::stringstream ss;
			  ss << "joint3";
			  
			  msg_start.joint_names.push_back(ss.str());
			  msg_start.velocities.push_back(0.25*(joint3_diff)/abs(joint3_diff));
			  msg_start.duration=5; //Unfortunately duration isn't implemented...
			  
			  ROS_INFO("Sending message");
			  chatter_pub.publish(msg_start);
			}
			if(abs(joint3_diff)<0.04) {
			  
			  ROS_INFO("Setting message");
			  control_msgs::JointJog msg_start;
			  std::stringstream ss;
			  ss << "joint3";
			  
			  msg_start.joint_names.push_back(ss.str());
			  msg_start.velocities.push_back(0);
			  msg_start.duration=5; //Unfortunately duration isn't implemented...
			  
			  ROS_INFO("Sending message");
			  chatter_pub.publish(msg_start);
			}
			
			// JOINT 4
			
			if(abs(joint4_diff)>0.04) {
			  
			  ROS_INFO("Setting message");
			  control_msgs::JointJog msg_start;
			  std::stringstream ss;
			  ss << "joint4";
			  
			  msg_start.joint_names.push_back(ss.str());
			  msg_start.velocities.push_back(0.25*(joint4_diff)/abs(joint4_diff));
			  msg_start.duration=5; //Unfortunately duration isn't implemented...
			  
			  ROS_INFO("Sending message");
			  chatter_pub.publish(msg_start);
			}
			if(abs(joint4_diff)<0.04) {
			  
			  ROS_INFO("Setting message");
			  control_msgs::JointJog msg_start;
			  std::stringstream ss;
			  ss << "joint4";
			  
			  msg_start.joint_names.push_back(ss.str());
			  msg_start.velocities.push_back(0);
			  msg_start.duration=5; //Unfortunately duration isn't implemented...
			  
			  ROS_INFO("Sending message");
			  chatter_pub.publish(msg_start);
			}
			
			// JOINT 5
			
			if(abs(joint5_diff)>0.04) {
			  
			  ROS_INFO("Setting message");
			  control_msgs::JointJog msg_start;
			  std::stringstream ss;
			  ss << "joint5";
			  
			  msg_start.joint_names.push_back(ss.str());
			  msg_start.velocities.push_back(0.3*(joint5_diff)/abs(joint5_diff));
			  msg_start.duration=5; //Unfortunately duration isn't implemented...
			  
			  ROS_INFO("Sending message");
			  chatter_pub.publish(msg_start);
			}
			if(abs(joint5_diff)<0.04) {
			  
			  ROS_INFO("Setting message");
			  control_msgs::JointJog msg_start;
			  std::stringstream ss;
			  ss << "joint5";
			  
			  msg_start.joint_names.push_back(ss.str());
			  msg_start.velocities.push_back(0);
			  msg_start.duration=5; //Unfortunately duration isn't implemented...
			  
			  ROS_INFO("Sending message");
			  chatter_pub.publish(msg_start);
			}
			
			// JOINT 6
			
			if(abs(joint6_diff)>0.04) {
			  
			  ROS_INFO("Setting message");
			  control_msgs::JointJog msg_start;
			  std::stringstream ss;
			  ss << "joint6";
			  
			  msg_start.joint_names.push_back(ss.str());
			  msg_start.velocities.push_back(0.15*(joint6_diff)/abs(joint6_diff));
			  msg_start.duration=5; //Unfortunately duration isn't implemented...
			  
			  ROS_INFO("Sending message");
			  chatter_pub.publish(msg_start);
			}
			if(abs(joint6_diff)<0.04) {
			  
			  ROS_INFO("Setting message");
			  control_msgs::JointJog msg_start;
			  std::stringstream ss;
			  ss << "joint6";
			  
			  msg_start.joint_names.push_back(ss.str());
			  msg_start.velocities.push_back(0);
			  msg_start.duration=5; //Unfortunately duration isn't implemented...
			  
			  ROS_INFO("Sending message");
			  chatter_pub.publish(msg_start);
			}
		}

		ros::spinOnce();
		loop_rate.sleep();

	}
	return 0;
}
