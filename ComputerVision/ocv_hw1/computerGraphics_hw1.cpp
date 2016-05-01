
/* Okan Akdogan
	
	CV Homework 1	
	*/

#include "opencv2\opencv.hpp"
#include "iostream"


using namespace cv;
using namespace std;

void showHistogram(Mat& img,string windowName);
void MouseCallBackFunc(int event, int x, int y, int flags, void* userdata);
void myThreshold(const Mat & inp,Mat & out,int threshValue);

int main(int, char**)
{
	// Selection screen
	int funcnum;
	cout<<"Enter funct num: \n\t 1)Histogram \n\t 2)Threshold\n"<<endl;
	cin>>funcnum;

	if(funcnum<1 || funcnum>2){
		cout<< "It is not an option.!"<<endl;
		return 0;
	}

	VideoCapture cap(0); // open the camera
	if (!cap.isOpened())  // check if camera exist
		return -1;
	
	//windows' names
	string func1window="imgwindow";
	string func1threshResult="threswindow1";
	string func2window="threshwindow2";
	string histWindowName="Histogram";


	//common vars
	int threshold_value=60;

	//function 1 variables
	Point p; //for hold mosue position
	Mat thresh; //threshhold result
	p.x=threshold_value;	//initial threshold value


	if(funcnum==1){
		namedWindow(func1window,1);
		namedWindow(func1threshResult,1);
		namedWindow(histWindowName,1);
		setMouseCallback(histWindowName,MouseCallBackFunc,&p); //set mouse event function
	}
	else if(funcnum==2){
		namedWindow(func2window,1);
		createTrackbar( "Threshold Value",
		 func2window, &threshold_value,
                  255);
	}


	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		
		Mat gray_image;
		cvtColor( frame, gray_image, CV_BGR2GRAY );

		/*func 1*/
		if(funcnum==1){

			imshow("imgwindow", gray_image); // show  orginal gray frame
			showHistogram(gray_image,histWindowName); //count and show hist.
			
			myThreshold(gray_image,thresh,p.x); //apply threshold with mosue point x value
			imshow(func1threshResult,thresh);	//show threshold result

		}else if(funcnum==2){
			/*func 2*/
			//trackbar will change "threshold_value"
			threshold(gray_image,thresh,threshold_value,255,CV_THRESH_BINARY); //apply threshold with trackbar value
			
			imshow(func2window, thresh);//show thresh result
		}
		

		if (waitKey(30) == 27) break; // wait for ESC button
	}
	
	
	destroyAllWindows();
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}

void showHistogram(Mat& img,string windowName)
{
    int bins = 256;             // number of bins
	//int nc = img.channels();    // number of channels

	Mat hist;       // histogram arrays with 1 array

	// Initalize histogram array
	
	hist = Mat::zeros(1, bins, CV_32SC1);
		
	// Calculate the histogram of the image
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			
			uchar val = img.at<uchar>(i,j);
			hist.at<int>(val) += 1;
			
		}
	}

	//find max value for normalize
	int hmax = 0;
	
	for (int i = 0; i < bins-1; i++)
		hmax = hist.at<int>(i) > hmax ? hist.at<int>(i) : hmax;
	
	
	
	// Display each histogram in a canvas
	Mat canvas;
	canvas = Mat::ones(256, bins, CV_8UC3);

	for (int j = 0, rows = canvas.rows; j < bins-1; j++)
	{
		line(
			canvas, 
			Point(j, rows), 
			Point(j, rows - (hist.at<int>(j) * rows/hmax)), 
			Scalar(200,200,200),
			1, 8, 0
		);
			
	}

	imshow(windowName, canvas);
	
}

void MouseCallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == EVENT_LBUTTONDOWN )
     {
		 Point * p=((Point*)userdata);
		 p->x=x;
		 p->y=y;
		 //cout << "position (" << x << ", " << y << ")" << endl;
     }
     
}

void myThreshold(const Mat & inp,Mat & out,int threshValue){

	int r=inp.rows, c=inp.cols;
	inp.copyTo(out);
	for(int i=0; i<r;++i)
		for(int j=0;j<c;++j){
			uchar val = out.at<uchar>(i,j);
			if( val<threshValue )
				out.at<uchar>(i,j)=0;
			else
				out.at<uchar>(i,j)=255;
		}

}