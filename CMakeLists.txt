cmake_minimum_required(VERSION 2.6)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET( XSlamSDK_DIR /usr/include )
FIND_PACKAGE( XSlamSDK REQUIRED )

function(BUILD_EXAMPLE)
  foreach(arg IN LISTS ARGN)
	add_executable(${arg} ${arg}.cpp)
	target_link_libraries(${arg} ${XSlamSDK_LIBRARIES} )
  endforeach()
endfunction()

BUILD_EXAMPLE(
  print_6dof
)
