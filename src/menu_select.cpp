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
#include <iostream>

#include <cstdlib> //library fo exit()

/**
	*The function select() prints a menu and it waits for an input of one of the options
*/
char select(){
	std::string opt;
	
	std::cout << "Menu per la stampa:" << std::endl;
	std::cout << "\ta)Stampa l'intero messaggio" << std::endl;
	std::cout << "\tn)Stampa solo il nome" << std::endl;
	std::cout << "\te)Stampa solo l'eta'" << std::endl;
	std::cout << "\tc)Stampa solo il corso di laurea" << std::endl;
	std::cout << "\tq)Esci dal menu" << std::endl;
	std::cout << std::endl;

	std::getline(std::cin, opt);
	//repeat until the option is correct
	while(opt.length() != 1 || (opt != "a" && opt != "n" && opt != "e" && opt != "c" && opt != "q")){
		std::cout << "ERROR: Invalid Input!" << std::endl;
		std::getline(std::cin, opt);
	};

	if(opt[0] == 'q')
		std::exit(0);

	return opt[0];
}



int main(int argc, char **argv){

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
	ros::init(argc, argv, "menu_select");
	// %EndTag(INIT)%

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
	ros::Publisher menu_pub = n.advertise<std_msgs::String>("menu", 1000);
	// %EndTag(PUBLISHER)%

	// %Tag(ROS_OK)%
	while (ros::ok()){
	// %EndTag(ROS_OK)%
		//clears the terminal
		std::system("clear");

		/**
     			* This is a message object. The message contains the selected option.
     		*/
		// %Tag(FILL_MESSAGE)%
		std_msgs::String msg;

		std::stringstream ss;
		ss << select();
		
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
	    	menu_pub.publish(msg);
		// %EndTag(PUBLISH)%

		// %Tag(SPINONCE)%
	    	ros::spinOnce();
		// %EndTag(SPINONCE)%
		
		

	}



	return 0;
}
