cmake_minimum_required(VERSION 3.10)

project(RobotArm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_subdirectory(Utilities)

add_executable(RobotArm Application/main.cpp)

target_link_libraries(RobotArm PRIVATE RobotArmUtilities)

target_compile_options( RobotArm PRIVATE 
-Werror 
-Wall 
-Wpedantic
)