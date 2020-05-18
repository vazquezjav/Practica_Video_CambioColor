

#include <iostream>
#include <cstdlib>
#include <windows.h>

// Librerías de OpenCV 4
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/cvconfig.h>

using namespace std;
using namespace cv;

int valorTrackbar=0;
Mat original, copia,frame;

void eventTrack(int v, void* p) {
	cout << "Valor " << v << endl;

}
void cambiar(Mat cambiar) {
	if (valorTrackbar == 1) {
		cvtColor(cambiar, cambiar, CV_BGR2HSV);
		imshow("Copia", cambiar);
	}

	if (valorTrackbar == 2) {
		cvtColor(cambiar, cambiar, CV_BGR2Lab);
		imshow("Copia", cambiar);
	}

	if (valorTrackbar == 3) {
		cvtColor(cambiar, cambiar, CV_BGR2GRAY);
		imshow("Copia", cambiar);
	}
	if (valorTrackbar == 0) {
		
		imshow("Copia", cambiar);
	}
}
int main(int argc, char* argv[]) {

	VideoCapture video(0);

	if (video.isOpened()) {
		namedWindow("Video", WINDOW_AUTOSIZE);
		namedWindow("Copia", WINDOW_AUTOSIZE);
		createTrackbar("Espacio", "Video", &valorTrackbar, 3, eventTrack, NULL);
		while (3 == 3) {

			video >> frame;
			copia = frame;
			flip(frame, frame, 1);
			if (frame.rows > 0 && frame.cols > 0) {

				imshow("Video", frame);
				cambiar(copia);
				
			}
			if (waitKey(23) == 27)
				break;
		}
	}

	waitKey(0);

	return 0;
}