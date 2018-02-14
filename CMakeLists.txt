cmake_minimum_required(VERSION 2.8.3)
project(laser_noise)

find_package(catkin REQUIRED COMPONENTS
	geometry_msgs
	sensor_msgs
	roscpp
	)

find_package(Boost REQUIRED COMPONENTS system)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
	
add_executable(
	laser_noise
	src/laser_noise.cpp
	)

target_link_libraries(laser_noise
	${catkin_LIBRARIES}
	)


