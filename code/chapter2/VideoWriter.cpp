/*
 * @Author: zhanghao
 * @Date: 2022-08-30 20:52:26
 * @LastEditTime: 2022-09-02 20:27:05
 * @FilePath: /hao_learnOpenCV4/code/chapter2/VideoWriter.cpp
 * @Description: 
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img;
	VideoCapture video(0);  //使用某个摄像头

	//读取视频
	//VideoCapture video;
	//video.open("cup.mp4");  

	if (!video.isOpened())  // 判断调用是否成功
	{
		cout << "please check your camera fine";
		return -1;
	}

	video >> img;  //获取图像 检测是否成功获取图像
	if (img.empty())   //判断读取图像是否成功
	{
		cout << "no image obtained" << endl;
		return -1;
	}
	bool isColor = (img.type() == CV_8UC3);  //判断相机类型是否为彩色

	VideoWriter writer;
	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');  //选择编码格式
	//OpenCV 4.0版 设置编码格式
	//int codec = CV_FOURCC('M', 'J', 'P', 'G'); 

	double fps = 25.0;  //设置视频帧率
	string filename = "live.avi";  //保存的视频文件名称
	writer.open(filename, codec, fps, img.size(), isColor); // Create a video stream that holds the video file

	if (!writer.isOpened()) // Determines whether the video stream was created successfully
	{
		cout << "Failed to open the video file. Please check whether the input is valid" << endl;
		return -1;
	}

	while (1)
	{
		// Check whether the execution is complete
		if (!video.read(img)) // Determine whether to read another frame from the camera or video file
		{
			cout << "The camera is disconnected or the video is read" << endl;
			break;
		}
		writer.write(img); // Write the image to the video stream
		// writer << img;
		imshow("Live", img);  //????????
		char c = waitKey(50);
		if (c == 27)  //???ESC????????????????????
		{
			break;
		}
	}
	// ?????????????????????????????
	//video.release();
	//writer.release();	
	return 0;
}