cmake_minimum_required(VERSION 3.5)
#创建工程
project(chapter3)
#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")
set(OpenCV_DIR "/home/hao007/haolib/opencv4.6/install/lib/cmake/opencv4")
find_package(OpenCV 4.6.0 REQUIRED) #找 OpenCV 4.0 安装路径
include_directories(${OpenCV_INCLUDE_DIRS}) #加载 OpenCV 4.0 的头文件

message(STATUS "${Red}OpenCV library status:${ColourReset}")
message(STATUS "    config: ${Blue}${OpenCV_DIR}${ColourReset}")
message(STATUS "    version: ${Blue}${OpenCV_VERSION}${ColourReset}")
message(STATUS "    libraries: ${Blue}${OpenCV_LIBS}${ColourReset}")
message(STATUS "    include path: ${Blue}${OpenCV_INCLUDE_DIRS}${ColourReset}")

add_executable(myCvColor myCvColor.cpp) #将程序生成可执行文件
target_link_libraries(myCvColor ${OpenCV_LIBS}) #链接 lib 文件到可执行文件中

add_executable(mySplitAndMerge mySplitAndMerge.cpp) #将程序生成可执行文件
target_link_libraries(mySplitAndMerge ${OpenCV_LIBS}) #链接 lib 文件到可执行文件中


add_executable(myfindMinAndMax myfindMinAndMax.cpp) #将程序生成可执行文件
target_link_libraries(myfindMinAndMax ${OpenCV_LIBS}) #链接 lib 文件到可执行文件中


add_executable(myWarpPerspective myWarpPerspective.cpp) #将程序生成可执行文件
target_link_libraries(myWarpPerspective ${OpenCV_LIBS}) #链接 lib 文件到可执行文件中