
/* Okan Akdogan
	
	CV Homework 3	
	*/

#include "opencv2\opencv.hpp"
#include <iostream>
/*
#include <sstream>
#include <time.h>
#include <stdio.h>
*/
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
vector<Point2f> sortPoints( vector<Point> points);
vector<Point2f> sortPoints( vector<Point2f> points);

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
	

	//camera Matrix define
	Mat cameraMatrix = Mat::eye(3, 3, CV_64F);
	
	cameraMatrix.at<double>(0,0)=6.0796370297663680e+002;
	cameraMatrix.at<double>(0,1)=0.;
	cameraMatrix.at<double>(0,2)=3.3418031030685819e+002;
	cameraMatrix.at<double>(1,0)=0.;
	cameraMatrix.at<double>(1,1)=6.1320316779481846e+002;
	cameraMatrix.at<double>(1,2)= 3.0017976670594362e+002;
	cameraMatrix.at<double>(2,0)=0.;
	cameraMatrix.at<double>(2,1)=0.;
	cameraMatrix.at<double>(2,2)=1.;

	//distCoff
	Mat dist =Mat::zeros(8, 1, CV_64F);
	dist.at<double>(0)=1.6690584451797194e-001;
	dist.at<double>(1)=-9.5098281732363232e-001;
	dist.at<double>(2)=1.7061365151738762e-003;
	dist.at<double>(3)=2.9513188358906710e-003;
	dist.at<double>(4)=1.1139035965832051e+000;
	
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
		   //drawContours( gray_image, contours_poly, markers[i].getContourIndex(), color, 1, 8, vector<Vec4i>(), 0, Point() );
		   drawContours( frame, contours_poly, markers[i].getContourIndex(), color, 1, 8, vector<Vec4i>(), 0, Point() );

		  // drawContours( drawing, contours, markers[i].getContourIndex(), color, 2, 8, vector<Vec4i>(), 0, Point() );

		   if(contours_poly[markers[i].getContourIndex()].size()==4){
			  
				String text;
			   for(int j=0; j<4; ++j){
					//circle( gray_image, contours_poly[markers[i].getContourIndex()][j], 5,  Scalar(255,255,0), 2, 8, 0 );
					text=text +"x: "+ to_string(contours_poly[markers[i].getContourIndex()][j].x)+" y: "+to_string(contours_poly[markers[i].getContourIndex()][j].y) ;
			   }
			   text=text+ " type "+ to_string(markers[i].getType()) +" c: "+ to_string(markers[i].c) ;
			   int y= gray_image.rows - 15*(markers.size()+i);
				putText(gray_image, text, Point(0,y) , FONT_HERSHEY_SIMPLEX, 0.4, Scalar(0,200,200), 1);
			   
		   }

		   vector<Point3f> objectPoints(4);

		   objectPoints[0]=Point3f(0,0,0);
		   objectPoints[1]=Point3f(1,0,0);
		   objectPoints[2]=Point3f(0,1,0);
		   objectPoints[3]=Point3f(1,1,0);

		   vector<Point2f> imagePoints(4);

		   //sort points
		   vector<Point> points = contours_poly[markers[i].getContourIndex()];
		   imagePoints=sortPoints(points);
			
		   cv::Mat rvec(3,1,cv::DataType<double>::type);
			cv::Mat tvec(3,1,cv::DataType<double>::type);

		   solvePnP(objectPoints,imagePoints,cameraMatrix,dist,rvec,tvec);

		   //find cube corners with z=1
		   objectPoints[0]=Point3f(0,0,-1);
		   objectPoints[1]=Point3f(1,0,-1);
		   objectPoints[2]=Point3f(0,1,-1);
		   objectPoints[3]=Point3f(1,1,-1);

		   vector<cv::Point2f> projectedPoints;
			projectPoints(objectPoints, rvec, tvec, cameraMatrix, dist, projectedPoints);

			projectedPoints= sortPoints(projectedPoints);

			Mat * drawFrame= &frame;
			Scalar cubeColor(0,255,0);
			int thickness=3;
			for(int j=0;j<4;j++){
				line(*drawFrame,projectedPoints[j],imagePoints[j],cubeColor,thickness);
			}
			
			line(*drawFrame,projectedPoints[0],projectedPoints[1],cubeColor,thickness);
			line(*drawFrame,projectedPoints[0],projectedPoints[2],cubeColor,thickness);
			line(*drawFrame,projectedPoints[1],projectedPoints[3],cubeColor,thickness);
			line(*drawFrame,projectedPoints[2],projectedPoints[3],cubeColor,thickness);
		}

		//imshow( corners_window, drawing );
		imshow(camwindow,frame);
		
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

vector<Point2f> sortPoints( vector<Point> points){


			vector<Point2f> imagePoints(4);
			double sumx=0,sumy=0;

		   for(int j=0; j<4; ++j){
			   sumx+=points[j].x;
			   sumy+=points[j].y;
			}
		   Point center(sumx/points.size(),sumy/points.size());
		   
		   for(int j=0; j<4; ++j){
			   
			   if( points[j].x < center.x && points[j].y < center.y ){
				   imagePoints[0]=points[j];
			   }else if(points[j].x > center.x && points[j].y < center.y){
					imagePoints[1]=points[j];
			   }else if(points[j].x < center.x && points[j].y > center.y){
					imagePoints[2]=points[j];
			   }else if(points[j].x > center.x && points[j].y > center.y){
					imagePoints[3]=points[j];
			   }else{
					cout<<"somthing wrong about corner positions"<<endl;
			   }
			}
		   return imagePoints;
}

vector<Point2f> sortPoints( vector<Point2f> points){


			vector<Point2f> imagePoints(4);
			double sumx=0,sumy=0;

		   for(int j=0; j<4; ++j){
			   sumx+=points[j].x;
			   sumy+=points[j].y;
			}
		   Point center(sumx/points.size(),sumy/points.size());
		   
		   for(int j=0; j<4; ++j){
			   
			   if( points[j].x < center.x && points[j].y < center.y ){
				   imagePoints[0]=points[j];
			   }else if(points[j].x > center.x && points[j].y < center.y){
					imagePoints[1]=points[j];
			   }else if(points[j].x < center.x && points[j].y > center.y){
					imagePoints[2]=points[j];
			   }else if(points[j].x > center.x && points[j].y > center.y){
					imagePoints[3]=points[j];
			   }else{
					cout<<"somthing wrong about corner positions"<<endl;
			   }
			}
		   return imagePoints;
}