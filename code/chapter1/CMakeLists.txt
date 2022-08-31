cmake_minimum_required(VERSION 2.6)
#创建工程
project(testopencv)
#C++版本为 11
set(CMAKE_CXX_FLAGS "-std=c++11")
set(OpenCV_DIR "/home/hao007/haolib/opencv4.6/install/lib/cmake/opencv4")
find_package(OpenCV 4.6.0 REQUIRED) #找 OpenCV 4.0 安装路径
include_directories(${OpenCV_INCLUDE_DIRS}) #加载 OpenCV 4.0 的头文件
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

add_executable(testopencv install_test.cpp) #将程序生成可执行文件
target_link_libraries(testopencv ${OpenCV_LIBS}) #链接 lib 文件到可执行文件中

add_executable(test_edge edge.cpp) #将程序生成可执行文件
target_link_libraries(test_edge ${OpenCV_LIBS}) #链接 lib 文件到可执行文件中

add_executable(kmeans_demo kmeans.cpp) #将程序生成可执行文件
target_link_libraries(kmeans_demo ${OpenCV_LIBS}) #链接 lib 文件到可执行文件中

add_executable(qrcode qrcode.cpp) #将程序生成可执行文件
target_link_libraries(qrcode ${OpenCV_LIBS}) #链接 lib 文件到可执行文件中

add_executable(videocapture_starter videocapture_starter.cpp) #将程序生成可执行文件
target_link_libraries(videocapture_starter ${OpenCV_LIBS}) #链接 lib 文件到可执行文件中


add_executable(camshiftdemo camshiftdemo.cpp) #将程序生成可执行文件
target_link_libraries(camshiftdemo ${OpenCV_LIBS}) #链接 lib 文件到可执行文件中