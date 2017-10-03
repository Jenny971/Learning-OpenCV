#include "stdafx.h"

//Example 2-3. Program to add a trackbar slider to the basic viewer window: when the slider is moved, 
//the function onTrackbarSlide() is called and then passed to the slider¡¯s new value
//This code does not update the slider position as the video plays
int g_slider_position = 0;
CvCapture* g_capture = NULL;
void onTrackbarSlide(int pos) {
	cvSetCaptureProperty(
	g_capture,
	CV_CAP_PROP_POS_FRAMES,
	pos);
}
int main( int argc, char** argv ) {
	cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE );
	//g_capture = cvCreateFileCapture( argv[1] );
	g_capture = cvCreateFileCapture("1.avi");
	int frames = (int) cvGetCaptureProperty(
		g_capture,
		CV_CAP_PROP_FRAME_COUNT
		);
	if( frames!= 0 ) {
		cvCreateTrackbar(
			"Position",
			"Example3",
			&g_slider_position,
			frames,
			onTrackbarSlide
		);
	}
	IplImage* frame;
// While loop (as in Example 2) capture & show video
	while(1) {
		frame = cvQueryFrame( g_capture );
		if( !frame ) break;
		cvShowImage("Example3", frame );
		char c = cvWaitKey(33);
		if( c == 27 ) break;
	}
// Release memory and destroy window
	cvReleaseCapture( &g_capture );
	cvDestroyWindow("Example3");
	return(0);
}