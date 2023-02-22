#include "./freeglut-3.2.1/include/GL/freeglut.h"
#include <GL/glut.h>
#include <iostream>
using namespace std;
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
  
  glPointSize(10);
  glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 3.0);
    glVertex2i(10, 40);
    glVertex2i(10, 60);
  glEnd();

  glLineWidth(10.0);
  glBegin(GL_LINES);
    glColor3f(0.0, 2.0, 0.0);
    glVertex2f(20.0, 20.0);
    glVertex2f(100.0, 100.0);
  glEnd();
  
  glBegin(GL_TRIANGLES);

    glColor3f(12.0,0.0,0.0);

    glVertex2f(40.0,210.0);
    glVertex2f(340.0,215.0);
    glVertex2f(320.0,250.0);

  glEnd();

  
  glFlush();
}

void myInit(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glColor3f(1.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,400.0,0.0,400.0);
}

int main(int argc, char **argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(200,300);
  glutInitWindowPosition(500,100);
  glutCreateWindow("Hello Students");
   glutDisplayFunc(display);
  myInit();
 glutMainLoop();
}
