#include<opencv2/opencv.hpp>
using namespace cv;
void main() {
	VideoCapture cap;
	VideoCapture cap1;
	cap.open("F:\torrent\�³պ��ռ�.mp4"); //����Ƶ,��������ȼ���VideoCapture cap("E://2.avi");
	cap1.open("F:\torrent\�³պ��ռ�.mp4");
	if (!cap.isOpened())//�����Ƶ�����������򷵻�
		return;
	Mat frame;
	Mat pic;
	while (100)
	{
		cap >> frame;//�ȼ���cap.read(frame);
		cap1 >> pic;
		if (frame.empty()||pic.empty())//���ĳ֡Ϊ�����˳�ѭ��
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
		waitKey(20);//ÿ֡��ʱ20����
	}
	cap.release();//�ͷ���Դ
	
}