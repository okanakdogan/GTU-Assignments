

/*
	Okan Akdogan 19/03/2016

	DDA and Bresenham Line Draw Algorithms Compare

	Brssenham Alg ref: http://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C.2B.2B
*/


#include<windows.h>       // for MS Windows
#include<GL\glut.h>       // GLUT, include glu.h and gl.h

#include <iostream>

using namespace std;


void LineDDA();
void LineBresenham();
void benchmark();

class MyColor{
public:
	float r;
	float g;
	float b;

	MyColor(float r,float g,float b){
		this->r=r;
		this->g=g;
		this->b=b;
	}
};

class MyPoint{
public:
	int x;
	int y;
};

// encapsulate algorithm and lines
class MyDrawAlg{
private:
	int drawAlgorithm;
	
public:
	MyDrawAlg(){}
	void setDrawAlgorithm(int val){
		if(val==1 || val==2 || val==3){
			drawAlgorithm=val;
		}
	}
	int getDrawAlgorithm(){
		return drawAlgorithm;
	}

};

int color = 0;
GLint width = 800;
GLint height = 800;
 //global vars
MyDrawAlg drawAlg;
int clickCount=0;
MyPoint screenPoint1,screenPoint2;
bool drawit=false;

void init()
{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(1, 1, 1, 0);


    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);
    
        
}
 
void drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4)
{
	/*
    // if color is 0 then draw white box and change value of color = 1
    if (color == 0)
    {
        glColor3f(1, 1, 1); // white color value is 1 1 1
        color = 1;
    }
    // if color is 1 then draw black box and change value of color = 0
    else
    {
        glColor3f(0, 0, 0); // black color value is 0 0 0
        color = 0;
    }*/
	
	glColor3f(0, 0, 0); // black color value is 1 1 1
    // Draw Square
    glBegin(GL_LINE_LOOP);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x4, y4);
    glEnd();
}

MyPoint findSquareOrigin(MyPoint screenPoint){
	MyPoint r;

	r.x = (screenPoint.x/4)*4;
	r.y = ((800-screenPoint.y)/4)*4;
	
	return r;
}

void drawSquareFill(MyPoint squareOrigin,MyColor color)
{
	//find origin
	
	//MyPoint squareOrigin=findSquareOrigin(screenPoint);
	//cout<<"drawSqureFill:"<<endl;
	//cout<<"drawSqureFill: square origin:"<< squareOrigin.x <<" "<< squareOrigin.y<<endl; 

	
	glColor3f(color.r, color.g, color.b); 
    // Draw Square
	glBegin(GL_POLYGON);
	glVertex2i(squareOrigin.x, squareOrigin.y);
    glVertex2i(squareOrigin.x+4, squareOrigin.y);
    glVertex2i(squareOrigin.x+4, squareOrigin.y-4);
    glVertex2i(squareOrigin.x, squareOrigin.y-4);
    glEnd();
}
void drawGrid()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window
    GLint x, y;
    GLint squareWidthInPixel = 4;
    GLint squareHightInPixel = 4;
    for (x = 0; x <= width; x += squareWidthInPixel)
    {
        for (y = 0; y <= height; y += squareHightInPixel)
        {
            drawSquare(x, y + squareHightInPixel, x + squareWidthInPixel, y + squareHightInPixel, x + squareWidthInPixel, y, x, y);
        }
    }
    // Process all OpenGL routine s as quickly as possible
	if (drawAlg.getDrawAlgorithm()==1 && drawit){
		//dda

		/*info :http://stackoverflow.com/questions/14337278/precise-time-measurement */
		LARGE_INTEGER frequency;        // ticks per second
		LARGE_INTEGER t1, t2;           // ticks
		double elapsedTime;
		// get ticks per second
		QueryPerformanceFrequency(&frequency);

		// start timer
		QueryPerformanceCounter(&t1);

		LineDDA();


		// stop timer
		QueryPerformanceCounter(&t2);

		// compute and print the elapsed time in millisec
		elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

		cout<<"DDA Algorithm elapsed time: " << elapsedTime <<endl; 
	}else if(drawAlg.getDrawAlgorithm()==2 && drawit){
		
		LARGE_INTEGER frequency;        // ticks per second
		LARGE_INTEGER t1, t2;           // ticks
		double elapsedTime;
		// get ticks per second
		QueryPerformanceFrequency(&frequency);

		// start timer
		QueryPerformanceCounter(&t1);
		
		//bre
		LineBresenham();

		// stop timer
		QueryPerformanceCounter(&t2);

		// compute and print the elapsed time in millisec
		elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

		cout<<"Bresenham Algorithm elapsed time: " << elapsedTime <<endl; 

	}else if(drawAlg.getDrawAlgorithm()==3){

		benchmark();

	}
	else{
		//nothing to draw
	}
	

    glFlush();
}

float round_value(float v)
{
  return floor(v + 0.5);
}

void LineDDA()
{

	MyPoint squareOrigin1=findSquareOrigin(screenPoint1);
	MyPoint squareOrigin2=findSquareOrigin(screenPoint2);
	double dx=(squareOrigin2.x-squareOrigin1.x);
	double dy=(squareOrigin2.y-squareOrigin1.y);
  double steps;
  float xInc,yInc, x=squareOrigin1.x,y=squareOrigin1.y;
  /* Find out whether to increment x or y */
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;
  

  /* Plot the points */
  glBegin(GL_POINTS);
  
  int k;
  /* For every step, find an intermediate vertex */
  for(k=0;k<steps;k++)
  {
    x+=xInc;
    y+=yInc;


	MyPoint p;
	p.x=(int)(x/4)*4;
	p.y=(int)(y/4)*4;
	drawSquareFill(p,MyColor(1,0,0));
  }
  glEnd();

  glFlush();
}

void LineBresenham()
{
	MyPoint squareOrigin1=findSquareOrigin(screenPoint1);
	MyPoint squareOrigin2=findSquareOrigin(screenPoint2);

	float x1 = squareOrigin1.x,y1=squareOrigin1.y;
	float x2 = squareOrigin2.x, y2 = squareOrigin2.y;
	MyColor mcolor(1,0,0);
        // Bresenham's line algorithm
  const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
  if(steep)
  {
    std::swap(x1, y1);
    std::swap(x2, y2);
  }
 
  if(x1 > x2)
  {
    std::swap(x1, x2);
    std::swap(y1, y2);
  }
 
  const float dx = x2 - x1;
  const float dy = fabs(y2 - y1);
 
  float error = dx / 2.0f;
  const int ystep = (y1 < y2) ? 1 : -1;
  int y = (int)y1;
 
  const int maxX = (int)x2;
 
  for(int x=(int)x1; x<maxX; x++)
  {
    if(steep)
    {
        
		MyPoint p;
		p.x=(int)(y/4)*4;
		p.y=(int)(x/4)*4;
		drawSquareFill(p,MyColor(1,0,0));
    }
    else
    {
       // SetPixel(x,y, color);
		MyPoint p;
		p.x=(int)(x/4)*4;
		p.y=(int)(y/4)*4;
		drawSquareFill(p,MyColor(1,0,0));
    }
 
    error -= dy;
    if(error < 0)
    {
        y += ystep;
        error += dx;
    }
  }
}

void bench_Line( MyPoint artCenter, int h, int w ,int algIndex){

	int axisIndex=1;
	int dist=h;
	int limit=w;

	screenPoint1=artCenter;
	MyPoint targetP;

	for(int i=0; i<limit; ++i){
		if(axisIndex==1){
			if( i<limit/2){
				targetP.x = artCenter.x-4*(limit/4) + i*4;
				targetP.y = artCenter.y +  dist*4;
			}
			else{
				targetP.x = artCenter.x-4*(limit/4) + (i-(limit/2))*4;
				targetP.y = artCenter.y +  (-dist)*4;
			}
			screenPoint2=targetP;
			if(algIndex ==1)
				LineDDA();
			else if (algIndex==2)
				LineBresenham();
		}

	}

}

void benchmark(){

	//wait a input to start with first algorithm

	int algIndex=1;
	
	//Draw ArtWork
	int axisIndex=1;
	int dist=20;
	int limit=100;

	double ddaTime,bresenTime;

	for(int i=1; i<=2;++i){

		LARGE_INTEGER frequency;        // ticks per second
		LARGE_INTEGER t1, t2;           // ticks
		double elapsedTime;
		// get ticks per second
		QueryPerformanceFrequency(&frequency);

		// start timer
		QueryPerformanceCounter(&t1);

		//Draw for 4 times with Alg
		MyPoint artCenter;

		artCenter.x=150;
		artCenter.y=150;

		bench_Line(artCenter,dist,limit,i);
	
		//change center and draw again
		artCenter.x=650;
		artCenter.y=150;
		bench_Line(artCenter,dist,limit,i);

		artCenter.x=150;
		artCenter.y=650;
		bench_Line(artCenter,dist,limit,i);

		artCenter.x=650;
		artCenter.y=650;
		bench_Line(artCenter,dist,limit,i);

		
		// stop timer
		QueryPerformanceCounter(&t2);
		elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
		if(i==1){
			cout<<"DDA Algorithm elapsed time: " << elapsedTime <<endl;
			ddaTime=elapsedTime;
		}
		else if(i ==2){
			cout<<"Bresenham Algorithm elapsed time: " << elapsedTime <<endl;
			bresenTime = elapsedTime;
		}
	}

	if(ddaTime < bresenTime){
		cout << "DDA Algorithm wins: " << ddaTime <<endl; 
	}else{
		cout << "Bresenham Algorithm wins: " << bresenTime <<endl;
	}
}

void mouseEvent(int button, int state,int x, int y){

	if(button ==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		if (clickCount==0)
		{
			screenPoint1.x=x;
			screenPoint1.y=y;
			clickCount++;
			drawit=false;
		}else if( clickCount==1){
			screenPoint2.x=x;
			screenPoint2.y=y;
			clickCount=0;
			drawit=true;
		}else{
			clickCount=0;
		}
		
		//cout<<"m click"<<clickCount<<endl;
		//cout<<screenPoint1.x<<"  "<<screenPoint1.y<<endl;
		glutPostRedisplay();
	}
}


void resize(int width, int height) {
    // we ignore the params and do:
	 glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
		gluOrtho2D(0.0,width,0.0,height);
		 glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glViewport(0,0,width,height);
    glutReshapeWindow( 800, 800);
}

int main(int agrc, char ** argv)
{

	int algorithCode=1;
	//console input
	cout << "Enter a option to test it"<<endl;
	cout << "1. DDA Line Algorithm test" << endl;
	cout << "2. Bresenham Line Algorithm test" <<endl;
	cout << "3. Benchmark for two algorithms" << endl;
	cout << ">";
	cin>> algorithCode;

	drawAlg.setDrawAlgorithm(algorithCode);

    // Initialize GLUT
    glutInit(&agrc, argv);
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set top - left display window position.
    glutInitWindowPosition(50, 50);
    // Set display window width and height
    glutInitWindowSize(800, 800);
	
    // Create display window with the given title
    glutCreateWindow("Draw Board using OpenGL in C++");
	glutReshapeFunc(resize);
    // Execute initialization procedure
    init();
    // Send graphics to display window
	glutDisplayFunc(drawGrid);
	//mouse event
	glutMouseFunc(mouseEvent);
    // Display everything and wait.
    glutMainLoop();
}