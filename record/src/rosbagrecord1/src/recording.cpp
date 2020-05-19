
/* 
   Desc: a Node Allows to programmatically use rosbag_record :
	 start a record --> initialize some options & give them to recorder --> run 
*/


//#include <ros/ros.h>
//#include <rosbag/recorder.h>
#include <rosbagrecord/recorder.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rosbag_record_cam1");
  ros::NodeHandle n;

  rosbag::RecorderOptions options;
  
  // Set the options for this recording
  options.append_date = true;
  options.trigger = false;
  options.publish = true; // publish a topic /begin_write --> later for LED 
  options.min_space = 0; // If the minimum free space (in bytes) on disk is below this threshold, the recorder terminates.
  //options.verbose = true; //Outputs a log when a message is received.
  //options.compression = rosbag::compression::LZ4; // or BZ2
  options.split = true; //Split the bag file and continue recording when maximum duration reached
  options.regex = false; //If true, topics is expected to be a list of regular expressions.
 // options.buffer_size = 15000; //Use an internal buffer of SIZE MB (Default: 256)
  options.topics.push_back("/ir/flir_tau2/image1");
 // options.topics.push_back("/chatter");
  options.max_duration = ros::Duration(600.0);//Record a bag of maximum duration in seconds
  //path
  std::string bag_path="/media/ubuntu/demo/";
  options.prefix = bag_path + "Cam1_";

  rosbag::Recorder recorder(options);
  recorder.run();
  
}
