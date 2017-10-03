#include "stdafx.h"

//Example 2-1. A simple OpenCV program that loads an image from disk and displays
int main(int argc, char** argv ) {
	//IplImage* img = cvLoadImage( argv[1] );
	IplImage* img = cvLoadImage("1.jpg");
	cvNamedWindow( "Example1", CV_WINDOW_AUTOSIZE );
	cvShowImage("Example1", img );
	cvWaitKey(0);
	cvReleaseImage( &img );
	cvDestroyWindow("Example1");
	return 0;
}