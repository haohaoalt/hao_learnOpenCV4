/*
 * @Author: zhanghao
 * @Date: 2022-08-30 20:52:26
 * @LastEditTime: 2022-09-03 10:52:15
 * @FilePath: /hao_learnOpenCV4/code/chapter3/myCvColor.cpp
 * @Description: 不同颜色模型之间的相互转换
 */
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("lena.png");
	if (img.empty())
	{
		cout << "please check your file name" << endl;
		return -1;
	}
	Mat gray, HSV, YUV, Lab, img32;
	img.convertTo(img32, CV_32F, 1.0 / 255);  //convert CV_8U to CV_32F
	//img32.convertTo(img, CV_8U, 255);  //convert CV_32F to CV_8U
	cvtColor(img32, HSV, COLOR_BGR2HSV);
	cvtColor(img32, YUV, COLOR_BGR2YUV);
	cvtColor(img32, Lab, COLOR_BGR2Lab);
	cvtColor(img32, gray, COLOR_BGR2GRAY);
	imshow("原图", img32);
	imshow("HSV", HSV);
	imshow("YUV", YUV);
	imshow("Lab", Lab);
	imshow("gray", gray);
	waitKey(0);
	return 0;
}
