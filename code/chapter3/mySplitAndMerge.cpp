/*
 * @Author: zhanghao
 * @Date: 2022-08-30 20:52:26
 * @LastEditTime: 2022-09-03 12:18:28
 * @FilePath: /hao_learnOpenCV4/code/chapter3/mySplitAndMerge.cpp
 * @Description: 通道分离与合并
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
		cout << "check file name" << endl;
		return -1;
	}
	Mat HSV;
	cvtColor(img, HSV, COLOR_RGB2HSV);
	Mat imgs0, imgs1, imgs2;  // Holds the result of an array type
	Mat imgv0, imgv1, imgv2;  // Holds the result of a vector type
	Mat result0, result1, result2; // The result of multichannel merging
	// Multichannel separation and merging of input array parameters
	Mat imgs[3];
	split(img, imgs);
	imgs0 = imgs[0];
	imgs1 = imgs[1];
	imgs2 = imgs[2];
	imshow("RGB-B channel", imgs0);	 // Display the pixel value of B channel after separation
	imshow("RGB-G channel", imgs1);	 // Display the pixel value of G channel after separation
	imshow("RGB-R channel", imgs2);	 //  Display the pixel value of R channel after separation
	imgs[2] = img;					 // Change the number of channels in the array to inconsistent
	merge(imgs, 3, result0);  // merge image
							  //imshow("result0", result0);  //imshow 最多显示4个通道
	Mat zero = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
	imgs[0] = zero;
	imgs[2] = zero;
	merge(imgs, 3, result1);  //���ڻ�ԭGͨ������ʵ������ϲ����Ϊ��ɫ
	imshow("result1", result1);  //��ʾ�ϲ����

								 //����vector�����Ķ�ͨ��������ϲ�
	vector<Mat> imgv;
	split(HSV, imgv);
	imgv0 = imgv.at(0);
	imgv1 = imgv.at(1);
	imgv2 = imgv.at(2);
	imshow("HSV-Hͨ��", imgv0);  //��ʾ�����Hͨ��������ֵ
	imshow("HSV-Sͨ��", imgv1);  //��ʾ�����Sͨ��������ֵ
	imshow("HSV-Vͨ��", imgv2);  //��ʾ�����Vͨ��������ֵ
	imgv.push_back(HSV);  //��vector�е�ͼ��ͨ������ɲ�ͳһ
	merge(imgv, result2);  //�ϲ�ͼ��
						   //imshow("result2", result2);  /imshow�����ʾ4��ͨ������˽����Image Watch�в鿴
	waitKey(0);
	return 0;
}