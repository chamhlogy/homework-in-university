#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string.h>

using namespace cv;
using namespace std;

void Read()
{
	VideoCapture capture("1.mp4");
	VideoCapture capture1("2.mp4");
	if (!capture.isOpened())
	{
		cout << "fail to open!" << endl;
		return;
	}
	if (!capture1.isOpened())
	{
		cout << "fail to open!" << endl;
		return;
	}

	Mat frame;
	Mat img;
	while (true)
	{
		if (!capture.read(frame))
			break;
		if (!capture1.read(img))
			break;
		capture >> frame;
		capture1 >> img;
		Mat subing;
		//imshow("读取视频信息", frame);
		resize(img, subing, Size(round(300), round(300)), 0, 0, INTER_AREA);
		subing.copyTo(frame(Rect(0, 0, 300, 300)));
		imshow("画中画", frame);
		if (waitKey(20) > 0)
			break;
	}
	capture.release();
	return;
}

void Show() {
	VideoCapture cap("1.mp4");
	if (!cap.isOpened())
	{
		cout << "视频文件打开失败" << endl;
	}
	cout << "宽度：" << cap.get(CV_CAP_PROP_FRAME_WIDTH) << endl;
	cout << "高度：" << cap.get(CV_CAP_PROP_FRAME_HEIGHT) << endl;
	cout << "总帧数：" << cap.get(CV_CAP_PROP_FRAME_COUNT) << endl;
	cout << "帧率（fps）：" << cap.get(CV_CAP_PROP_FPS) << endl;
	cout << "编码格式" << cap.get(CV_CAP_PROP_FOURCC) << endl;
	Mat frame;
	while (1)
	{
		cap >> frame;
		if (frame.empty())
		{
			break;
		}
		imshow("readvideo", frame);
		waitKey(20);//win10 vs2015返回值-1
	}
	getchar();
	return;
}

void Write()
{
	//读取视频或摄像头
	VideoCapture capture(0);
	VideoWriter videooutput;
	string outfile = "3.avi";
	Size S(320,240);
	videooutput.open(outfile, CV_FOURCC('M','J','P','G'), 5.0, S);
	if (!videooutput.isOpened())
	{
		cout << "fail to open!" << endl;
		return;
	}
	Mat frame;
	Mat img;
	while (true)
	{
		if (!capture.read(frame))
			break;
		capture >> frame;
		resize(frame, img, S, 0, 0, INTER_AREA);
		imshow("读取视频信息", img);
		videooutput << img;
		if (waitKey(20) > 0)
			break;
	}
	capture.release();
	videooutput.release();
	return;
}

int Com() {
	int r,num;
	Mat frame;
	char outfile[50000];
	VideoCapture cap("s1.mp4");
	if (!cap.isOpened())
	{
		cout << "视频文件打开失败" << endl;
		return -1;
	}
	int totalFrame = cap.get(CV_CAP_PROP_FRAME_COUNT);
	

	for (int i = 1; i <= totalFrame; i++)
	{
		cap >> frame;
		if (frame.empty())
		{
			break;
		}
		
		imwrite("F:\\C++\\openCV2\\opencv\\opencv\\s\\"+ to_string(i) +".jpg",frame);
		waitKey(15);
		r = i;
	}
	cap.release();
	Mat frame1;
	VideoCapture cap1("s2.mp4");
	if (!cap1.isOpened())
	{
		cout << "视频文件打开失败" << endl;
		return -1;
	}
	int totalFrame1 = cap1.get(CV_CAP_PROP_FRAME_COUNT);


	for (int i = r+1; i <= r+totalFrame1; i++)
	{
		cap1 >> frame1;
		if (frame1.empty())
		{
			break;
		}

		imwrite("F:\\C++\\openCV2\\opencv\\opencv\\s\\" + to_string(i) + ".jpg", frame1);
		waitKey(15);
		num = i;
	}
	cap1.release();

	char image_name[50000];
	string s_image_name;
	VideoWriter writer;
	int isColor = 1;//不知道是干啥用的
	int frame_fps = 30;
	int frame_width = 640;
	int frame_height = 480;
	string video_name = "naive.avi";
	writer = VideoWriter(video_name, CV_FOURCC('M', 'J', 'P', 'G'), frame_fps, Size(frame_width, frame_height));
	cout << "frame_width is " << frame_width << endl;
	cout << "frame_height is " << frame_height << endl;
	cout << "frame_fps is " << frame_fps << endl;
	namedWindow("image to video", CV_WINDOW_AUTOSIZE);
	int i = 0;
	Mat img2;
	while (i <= 385/*num*/)
	{
		s_image_name = "F:\\C++\\openCV2\\opencv\\opencv\\s\\" + to_string(++i) + ".jpg";
		img2 = imread(s_image_name);//读入图片
		if (!img2.data)//判断图片调入是否成功
		{
			return 0;
		}
		imshow("image to video", img2);
		//写入
		waitKey(20);
		writer.write(img2);
		//if (waitKey(30) == 27 || i == 160)
		//{
		//	cout << "按下ESC键" << endl;
		//	break;
		//}
	}


	destroyAllWindows();
}
int main(int argc, char *argv[])
{
	cout << "输入操作编号：{1}显示参数  {2}读取视频 {3} 摄像头写入视频 {4}合成两段视频"<<endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
		Show();
		break;
	case 2:
		Read();
		break;
	case 3:
		Write();
		break;
	case 4:
		Com();
		break;
	default:
		break;
	}
	system("pause");
	return 0;
}