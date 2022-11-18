/*
 * @Author: zhanghao
 * @Date: 2022-08-30 20:52:26
 * @LastEditTime: 2022-11-04 09:54:14
 * @FilePath: /hao_learnOpenCV4/code/chapter1/install_test.cpp
 * @Description: 
 */
#include <opencv2/opencv.hpp>  
#include <iostream>

using namespace std;
using namespace cv;  

int main(int argc, char ** argv) 
{
	Mat img;
	img = imread("lena.png");
	if(img.empty())
	{
		cout << "test" << endl;
		return -1;
	}
	imshow("test", img); 
	waitKey(0);
	return 0;  
}