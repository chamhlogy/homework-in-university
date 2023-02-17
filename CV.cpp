#include<opencv2/opencv.hpp>
using namespace cv;
void main() {
	VideoCapture cap;
	VideoCapture cap1;
	cap.open("F:\torrent\新痴汉日记.mp4"); //打开视频,以上两句等价于VideoCapture cap("E://2.avi");
	cap1.open("F:\torrent\新痴汉日记.mp4");
	if (!cap.isOpened())//如果视频不能正常打开则返回
		return;
	Mat frame;
	Mat pic;
	while (100)
	{
		cap >> frame;//等价于cap.read(frame);
		cap1 >> pic;
		if (frame.empty()||pic.empty())//如果某帧为空则退出循环
			break;
		Mat subimg;
		frame(Rect(0, 0, 200, 200)).setTo(255);
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < 200; j++)
			{
				frame.at<Vec3b>(i, j)[0] = j;
				frame.at<Vec3b>(i, j)[1] = i;
				frame.at<Vec3b>(i, j)[2] = i+j;
			}
		}
		//resize(pic, subimg, Size(400,400));
		//subimg.copyTo(frame(Rect(0, 0,400,400)));
		//imshow("video", frame);
		//imwrite("pic.jpg",frame);
		//imwrite("C:/Users/Chamh/Pictures/Chamh.jpg", frame);
		waitKey(20);//每帧延时20毫秒
	}
	cap.release();//释放资源
	
}