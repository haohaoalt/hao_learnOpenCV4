/*
 * @Author: zhanghao
 * @Date: 2022-08-30 20:52:26
 * @LastEditTime: 2022-09-04 15:32:46
 * @FilePath: /hao_learnOpenCV4/code/chapter3/myConcat.cpp
 * @Description: 
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	//��������ĺ�������
	Mat matArray[] = { Mat(1, 2, CV_32FC1, cv::Scalar(1)),
		Mat(1, 2, CV_32FC1, cv::Scalar(2)) };
	Mat vout, hout;
	vconcat(matArray, 2, vout);
	cout << "ͼ�������������ӣ�" << endl << vout << endl;
	hconcat(matArray, 2, hout);
	cout << "ͼ������������ӣ�" << endl << hout << endl;

	//����ĺ���ƴ��
	Mat A = (cv::Mat_<float>(2, 2) << 1, 7, 2, 8);
	Mat B = (cv::Mat_<float>(2, 2) << 4, 10, 5, 11);
	Mat vC, hC;
	vconcat(A, B, vC);
	cout << "���ͼ���������ӣ�" << endl << vC << endl;
	hconcat(A, B, hC);
	cout << "���ͼ��������ӣ�" << endl << hC << endl;

	//��ȡ4����ͼ��00��ʾ���Ͻǡ�01��ʾ���Ͻǡ�10��ʾ���½ǡ�11��ʾ���½�
	Mat img00 = imread("lena00.png");
	Mat img01 = imread("lena01.png");
	Mat img10 = imread("lena10.png");
	Mat img11 = imread("lena11.png");
	if (img00.empty() || img01.empty() || img10.empty() || img11.empty())
	{
		cout << "��ȷ��ͼ���ļ������Ƿ���ȷ" << endl;
		return -1;
	}
	//��ʾ4����ͼ��
	imshow("img00", img00);
	imshow("img01", img01);
	imshow("img10", img10);
	imshow("img11", img11);

	//ͼ������
	Mat img, img0, img1;
	//ͼ���������
	hconcat(img00, img01, img0);
	hconcat(img10, img11, img1);
	//�������ӽ���ٽ�����������
	vconcat(img0, img1, img);

	//��ʾ����ͼ��Ľ��
	imshow("img0", img0);
	imshow("img1", img1);
	imshow("img", img);
	waitKey(0);
	return 0;
}
