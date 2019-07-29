// add this file to the CMakeLists.txt to compile
// outputs: "timestamp x y z pitch yaw roll"

#include <iostream>
// include the XSLAM sdk
#include <xslam/xslam_sdk.hpp>
// Display the time and the 6 dof pose in the world coordinate frame
void show_6dof(xslam_pose* pose)
{
  std::cout
    << pose->timestamp << " "
    << pose->x << " " << pose->y << " " << pose->z << " "
    << pose->pitch << " " << pose->yaw << " " << pose->roll << std::endl;
}
int main(int argc, char** argv)
{
    std::cerr << "[main] entered" << std::endl;
//    xslam_set_sdk_mode(SDK_EDGE);
//    std::cerr << "[main] set sdk mode" << std::endl;
    // set the function to call for each 6 dof pose, the protopy must be "(void)(xslam_pose*)"
    xslam_6dof_callback(&show_6dof);
    std::cerr << "[main] set 6dof callback" << std::endl;
    // start visual odometry
    xslam_start_vo();
    std::cerr << "[main] VO started" << std::endl;
    std::cerr << " Press Enter to stop the process" << std::endl;
    std::cin.get();
    std::cerr << " Stop process ..." << std::endl;
    // stop visual odometry
    xslam_stop();
    // free ressources
    std::cerr << "[main] xslam stopped" << std::endl;
    return xslam_free() == xslam_status::failure ? EXIT_FAILURE : EXIT_SUCCESS;
}
