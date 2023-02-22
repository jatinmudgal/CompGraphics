#include "./freeglut-3.2.1/include/GL/freeglut.h"
#include <GL/glut.h>

#include <iostream>
using namespace std;

int pntX1, pntY1;
int rx, ry;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}


void midPointEllipseAlgo()
{

  // for Region-1
	float x = 0;
  float y = ry;//(0,ry) ---
  float p1 = ry * ry - (rx * rx)* ry + (rx * rx) * (0.25) ;
  //slope
  float dx = 2 * (ry * ry) * x;
  float dy = 2 * (rx * rx) * y;

  while(dx < dy)
    {
      //plot (x,y)
         plot(x, y);
         plot(-x, y);
         plot(x  , -y );
         plot(-x  , -y);
    
        if(p1 < 0)
        {
            x = x + 1;
            dx = 2 * (ry * ry) * x;
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dx =  2 * (ry * ry) * x;
            dy =  2 * (rx * rx) * y;
             p1 = p1 + dx - dy +(ry * ry);
        }
    }

  // for Region-2
  float p2 = (ry * ry )* ( x +  0.5) * ( x +  0.5) +  ( rx * rx) * ( y - 1) * ( y - 1) - (rx * rx )* (ry * ry);


	while(y > 0)
    {
        //plot (x,y)
         plot(x, y);
         plot(-x, y);
         plot(x, -y );
         plot(-x, -y);     //glEnd();
        if(p2 > 0)
        {
            x = x;
            y = y - 1;
            dy = 2 * (rx * rx) * y;
            //dy = 2 * rx * rx *y;
            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dy = dy - 2 * (rx * rx) ;
            dx = dx + 2 * (ry * ry) ;
            p2 = p2 + dx -
            dy + (rx * rx);
        }
    }

}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	midPointEllipseAlgo();

	glFlush ();
}

void myInit(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv)
{	
	cout << "Enter the coordinates of the Ellipse:\n\n" << endl;

	cout << "X-coordinate   : "; cin >> pntX1;
	cout << "\nY-coordinate : "; cin >> pntY1;
  cout << "\nSemi-Major Axis   : "; cin >> rx;
	cout << "\nSemi-Minor Axis : "; cin >> ry;
  

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Mid-point Ellipse");
	glutDisplayFunc(display);
	myInit ();
	glutMainLoop();

}
