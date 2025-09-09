add_library(RobotArmUtilities STATIC Src/TcpServer.cpp)

target_include_directories(RobotArmUtilities
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Src
)