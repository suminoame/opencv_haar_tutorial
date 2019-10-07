#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
	CascadeClassifier face_cascade;

	// �J�X�P�[�h�t�B���^�̏ꏊ���w��
	if(!face_cascade.load("./filter/haarcascade_frontalface_alt.xml"))
    {
        cout << "--(!)Error loading face cascade\n";
        return -1;
    };

	vector<Rect> faces;

	// �r�f�I�f�o�C�X��I��
	VideoCapture capture(0);
	if (!capture.isOpened())
	{
		cout << "--(!)Error opening video capture\n";
		return -1;
	}

	Mat frame;
	while (capture.read(frame))
	{
		capture >> frame;
		face_cascade.detectMultiScale(frame, faces, 1.1, 3, 0, Size(20, 20));

		// ���m�Ώۂ���`�\��
		for (int i = 0; i < faces.size(); i++)
		{
			rectangle(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 3, 16);
		}

		imshow("Capture - Face detection", frame);
		
		// escape�����Ń��[�v�I��
		if (waitKey(10) == 27)
		{
			break;
		}
	}
	destroyAllWindows();
	return 0;
}