
/* Okan Akdogan
	
	CV Homework 2	
	*/

#include "opencv2\opencv.hpp"
#include <iostream>

#include <sstream>
#include <time.h>
#include <stdio.h>

using namespace cv;
using namespace std;

class Marker{
private:
	int countour_index;
	int type;

public:
	int c;
	Marker(int ci,int t) {countour_index=ci; type=t;}
	void setType(int t){ type=t;}
	int getType(){ return type;}
	void setContourIndex(int ci){ countour_index = ci; }
	int getContourIndex(){return countour_index;}
};

vector<Marker>findMarkers(vector<vector<Point>> contours,vector<Vec4i> hierarchy);


int main(int, char**)
{
	
	VideoCapture cap(0); // open the camera
	if (!cap.isOpened())  // check if camera exist
		return -1;
	
	//camera settings
	cap.set(CAP_PROP_FPS,5);
	//cap.set(CAP_PROP_FRAME_HEIGHT,240);
	//cap.set(CAP_PROP_FRAME_WIDTH,320);
	
	//windows' names
	string camwindow="Camgray";
	namedWindow(camwindow,CV_WINDOW_AUTOSIZE);
	char* corners_window = "markers detected";
	//namedWindow( corners_window, WINDOW_AUTOSIZE );

	//common vars
	Mat dst, dst_norm, dst_norm_scaled;
	Mat frame;
	int thresh = 75;
	Mat gray_image;
	int max_thresh = 255;
	RNG rng(12345);
	char key;
	

	for (;;)
	{
		key=waitKey(30);
		//cout<<"key pressed"<<endl;
		if(key == 27)
			break;
		if (key!= 32);

		cap >> frame; // get a new frame from camera
		cap >> frame; // get a new frame from camera

		cvtColor( frame, gray_image, CV_BGR2GRAY );
		int blur_size=3;

		//blur( gray_image, gray_image, Size(blur_size,blur_size) );
		GaussianBlur(gray_image,gray_image,Size(blur_size,blur_size),0);

		Mat canny_output;
		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;
		Mat threshRes;
		//threshold( gray_image, threshRes, 100, 255, THRESH_BINARY );

		/// Detect edges using canny
		Canny( gray_image, canny_output, thresh, thresh*2, 3 );

		/// Find contours
		findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

		vector<vector<Point> > contours_poly( contours.size() );

		for( int i = 0; i < contours.size(); i++ )
		  approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );


		//find markers
		vector<Marker>markers=findMarkers(contours,hierarchy);
		
		/// Draw polygonal contour + bonding rects + circles
		
		//Mat drawing = Mat::zeros( gray_image.size(), CV_8UC3 );

		//draw markers
		for( int i = 0; i< markers.size(); i++ )
		 {
		   //Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
		   Scalar color = Scalar( 255, 255,255);
		   drawContours( gray_image, contours_poly, markers[i].getContourIndex(), color, 1, 8, vector<Vec4i>(), 0, Point() );
		  // drawContours( drawing, contours, markers[i].getContourIndex(), color, 2, 8, vector<Vec4i>(), 0, Point() );

		   if(contours_poly[markers[i].getContourIndex()].size()==4){
			  
				String text;
			   for(int j=0; j<4; ++j){
					circle( gray_image, contours_poly[markers[i].getContourIndex()][j], 5,  Scalar(255,255,0), 2, 8, 0 );
					text=text +"x: "+ to_string(contours_poly[markers[i].getContourIndex()][j].x)+" y: "+to_string(contours_poly[markers[i].getContourIndex()][j].y) ;
			   }
			   text=text+ " type "+ to_string(markers[i].getType()) +" c: "+ to_string(markers[i].c) ;
			   int y= gray_image.rows - 15*(markers.size()+i);
				putText(gray_image, text, Point(0,y) , FONT_HERSHEY_SIMPLEX, 0.4, Scalar(0,200,200), 1);
			   
		   }
		}

		//imshow( corners_window, drawing );
		imshow(camwindow,gray_image);
		
	}
		
	destroyAllWindows();
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}

vector<Marker>findMarkers(vector<vector<Point>> contours,vector<Vec4i> hierarchy){

	vector<Marker> markers;
	//vector<int>outIndex;
	

	for( int i = 0; i < contours.size(); i++ )
		{
			int k=i;
			int c=0;
			vector<int>nestedIndex;
			while(hierarchy[k][2] != -1)
			{
				k = hierarchy[k][2] ;
				nestedIndex.push_back(k);
				c = c+1;

			}
			if(hierarchy[k][2] != -1){
			c = c+1;
			nestedIndex.push_back(k);
			}
			if (c >= 6)
			{	
				if(markers.empty()){

					Marker m(i,0);
					m.c=c;
					
					markers.push_back(m);
				}
				else
					if( abs(i-markers[markers.size()-1].getContourIndex())>3){						
						Marker m(i,0);
						m.c=c;
						
						markers.push_back(m);
						
					}
					else{	
						
						if(c>6){
							markers[markers.size()-1].setType(c-6);
							markers[markers.size()-1].c=c;
						}
					}
							
			}
		} 
	//cout<< "marker count"<<markers.size()<<endl;
	return markers;
	
}
