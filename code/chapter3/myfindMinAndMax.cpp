/*
 * @Author: zhanghao
 * @Date: 2022-08-30 20:52:26
 * @LastEditTime: 2022-09-04 15:30:41
 * @FilePath: /hao_learnOpenCV4/code/chapter3/myfindMinAndMax.cpp
 * @Description: 
 */
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
	system("color F0");  //�������������ɫ
	float a[12] = { 1, 2, 3, 4, 5, 10, 6, 7, 8, 9, 10, 0 };
	Mat img = Mat(3, 4, CV_32FC1, a);  //��ͨ������
	Mat imgs = Mat(2, 3, CV_32FC2, a);  //��ͨ������
	double minVal, maxVal;  //���ڴ�ž����е����ֵ����Сֵ
	Point minIdx, maxIdx;  ////���ڴ�ž����е����ֵ����Сֵ�ھ����е�λ��

	/*Ѱ�ҵ�ͨ�������е���ֵ*/
	minMaxLoc(img, &minVal, &maxVal, &minIdx, &maxIdx);
	cout << "img�����ֵ�ǣ�" << maxVal << "  " << "�ھ����е�λ��:" << maxIdx << endl;
	cout << "img����Сֵ�ǣ�" << minVal << "  " << "�ھ����е�λ��:" << minIdx << endl;

	/*Ѱ�Ҷ�ͨ�������е���ֵ*/
	Mat imgs_re = imgs.reshape(1, 4);  //����ͨ�������ɵ�ͨ������
	minMaxLoc(imgs_re, &minVal, &maxVal, &minIdx, &maxIdx);
	cout << "imgs�����ֵ�ǣ�" << maxVal << "  " << "�ھ����е�λ��:" << maxIdx << endl;
	cout << "imgs����Сֵ�ǣ�" << minVal << "  " << "�ھ����е�λ��:" << minIdx << endl;
	return 0;
}