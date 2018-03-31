/**
*@author Amine Moustaghfir
*/


// %Tag(FULLTEXT)%
// %Tag(ROS_HEADER)%
#include "ros/ros.h"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "std_msgs/String.h"
// %EndTag(MSG_HEADER)%

#include <sstream>
#include <string>
//Dependency for generating random numbers
#include <cstdlib>
#include <iostream>
#include <ctime>

#define SIZE_NAMES 6
#define SIZE_DEGREES 3
#define MAX_AGE 60

//functions used for creating the message to send
std::string rand_name(std::string[]);
int rand_age();
std::string rand_degree(std::string[]);


int main(int argc, char **argv){
	//An array of names for the message to send	
	std::string name[SIZE_NAMES] = {"Mario", "Roberto", "Mike", "Francesca", "Valentina", "Giorgio"};
	//An array of degrees for the message to send
	std::string degree[SIZE_DEGREES] = {"Informatica", "Economia", "Medicina"};
	
	/**
	   * The ros::init() function needs to see argc and argv so that it can perform
	   * any ROS arguments and name remapping that were provided at the command line.
	   * For programmatic remappings you can use a different version of init() which takes
	   * remappings directly, but for most command-line programs, passing argc and argv is
	   * the easiest way to do it.  The third argument to init() is the name of the node.
	   *
	   * You must call one of the versions of ros::init() before using any other
	   * part of the ROS system.
   	*/
	// %Tag(INIT)%
	ros::init(argc, argv, "talker");
	// %EndTag(INIT)%

		
	//setting the seed to current time
	std::srand(std::time(NULL));


	/**
	   * NodeHandle is the main access point to communications with the ROS system.
	   * The first NodeHandle constructed will fully initialize this node, and the last
	   * NodeHandle destructed will close down the node.
   	*/
	// %Tag(NODEHANDLE)%
	ros::NodeHandle n;
	// %EndTag(NODEHANDLE)%
	
	/**
	   * The advertise() function is how you tell ROS that you want to
	   * publish on a given topic name. This invokes a call to the ROS
	   * master node, which keeps a registry of who is publishing and who
	   * is subscribing. After this advertise() call is made, the master
	   * node will notify anyone who is trying to subscribe to this topic name,
	   * and they will in turn negotiate a peer-to-peer connection with this
	   * node.  advertise() returns a Publisher object which allows you to
	   * publish messages on that topic through a call to publish().  Once
	   * all copies of the returned Publisher object are destroyed, the topic
	   * will be automatically unadvertised.
	   *
	   * The second parameter to advertise() is the size of the message queue
	   * used for publishing messages.  If messages are published more quickly
	   * than we can send them, the number here specifies how many messages to
	   * buffer up before throwing some away.
   	*/
	// %Tag(PUBLISHER)%
	ros::Publisher info_pub = n.advertise<std_msgs::String>("info", 1000);
	// %EndTag(PUBLISHER)%

	//it sends messages with frequency of 1Hz (every second)
	// %Tag(LOOP_RATE)%
	ros::Rate loop_rate(1); 
	// %EndTag(LOOP_RATE)%

	// %Tag(ROS_OK)%
	while (ros::ok()){
	// %EndTag(ROS_OK)%

		/**
     			* This is a message object. The message contains name|age|degree_course.
     		*/
		// %Tag(FILL_MESSAGE)%
		std_msgs::String msg;

		std::stringstream ss;
		ss << rand_name(name) << "|" << rand_age() << "|" << rand_degree(degree);
		msg.data = ss.str();
		// %EndTag(FILL_MESSAGE)%

		// %Tag(ROSCONSOLE)%
		ROS_INFO("%s", msg.data.c_str());
		// %EndTag(ROSCONSOLE)%

		/**
		     * The publish() function is how you send messages. The parameter
		     * is the message object. The type of this object must agree with the type
		     * given as a template parameter to the advertise<>() call, as was done
		     * in the constructor above.
    		*/
		// %Tag(PUBLISH)%
	    	info_pub.publish(msg);
		// %EndTag(PUBLISH)%

		// %Tag(SPINONCE)%
	    	ros::spinOnce();
		// %EndTag(SPINONCE)%

		// %Tag(RATE_SLEEP)%
	    	loop_rate.sleep();
		// %EndTag(RATE_SLEEP)%


	}

	return 0;
}


/**
* The function returns a random name from the array of string names
*/
std::string rand_name(std::string names[]){
	int index = std::rand() % SIZE_NAMES;

	return names[index];
}

/**
* The function returns a random integer age from 19 to MAX_AGE years old.
*/
int rand_age(){
	return std::rand() % (MAX_AGE - 19 + 1) + 19;
}

/**
* The function returns a random degree from the array of string degrees
*/
std::string rand_degree(std::string degrees[]){
	int index = std::rand() % SIZE_DEGREES;

	return degrees[index];
}


