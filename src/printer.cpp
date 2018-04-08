/**
*@author Amine Moustaghfir
*/

// %Tag(FULLTEXT)%
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <string>

int mode = -1;


void printCallback(const std_msgs::String::ConstPtr& msg){
	if(mode == 0){
		ROS_INFO("%s", msg->data.c_str());
	}else if(mode == 1){
		//STAMPA SOLO NOME
		int pos = msg->data.find_first_of("|");
		ROS_INFO("%s", msg->data.substr(0, pos).c_str());
	}else if(mode == 2){
		//STAMPA SOLO ETA'
		int pos = msg->data.find_first_of("|");			//recupero la prima posizione di '|' nella stringa
		int pos_second = msg->data.find_last_of("|");	//recupero la seconda posizione di '|' nella stringa

		ROS_INFO("%s", msg->data.substr(pos+1, pos_second - pos - 1).c_str()); //estraggo la substring
										 	//da pos + 1 con con lun. = pos_second - pos -1
	}else if(mode == 3){
		//STAMPA SOLO CORSO
		int pos_last = 	msg->data.find_last_of("|");	//recupero la seconda posizione di '|' nella stringa
		
		ROS_INFO("%s", msg->data.substr(pos_last+1).c_str());
	
	}
		
}

void task(char op){
	switch(op){
		case 'a':
							//TODO STAMPA TUTTO
							mode = 0;
							//sub_msg = n.subscribe("info", 1000, printCallback);		
							break;

		case 'n':
							//TODO STAMPA NOME
							mode = 1;							
							break;

		case 'e':
							//TODO STAMPA ETA'
							mode = 2;							
							break;

		case 'c':
							//TODO STAMPA CORSO
							mode = 3;							
							break;

		default:
							ROS_INFO("ERROR: [%c] => Command not reconized!", op);
							break;
						
	}
}


// %Tag(CALLBACK)%
void menuCallback(const std_msgs::String::ConstPtr& msg)
{
	char * cstr = new char [msg->data.length()+1];
  	std::strcpy (cstr, msg->data.c_str());

  	ROS_INFO("Received option: [%s]", cstr);
	
	task(cstr[0]);

	
}
// %EndTag(CALLBACK)%

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
 	 ros::init(argc, argv, "printer");

  	/**
	   * NodeHandle is the main access point to communications with the ROS system.
	   * The first NodeHandle constructed will fully initialize this node, and the last
	   * NodeHandle destructed will close down the node.
   	*/
 	ros::NodeHandle n;

	/**
	   * The subscribe() call is how you tell ROS that you want to receive messages
	   * on a given topic.  This invokes a call to the ROS
	   * master node, which keeps a registry of who is publishing and who
	   * is subscribing.  Messages are passed to a callback function, here
	   * called chatterCallback.  subscribe() returns a Subscriber object that you
	   * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
	   * object go out of scope, this callback will automatically be unsubscribed from
	   * this topic.
	   *
	   * The second parameter to the subscribe() function is the size of the message
	   * queue.  If messages are arriving faster than they are being processed, this
	   * is the number of messages that will be buffered up before beginning to throw
	   * away the oldest ones.
   	*/
	// %Tag(SUBSCRIBER)%
	ros::Subscriber sub = n.subscribe("menu", 1000, menuCallback);
	ros::Subscriber sub_msg = n.subscribe("info", 1000, printCallback);
	// %EndTag(SUBSCRIBER)%


	/**
	   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
	   * callbacks will be called from within this thread (the main one).  ros::spin()
	   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   	*/
	// %Tag(SPIN)%
  	ros::spin();
	// %EndTag(SPIN)%


	return 0;
}
// %EndTag(FULLTEXT)%
