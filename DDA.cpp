#include "./freeglut-3.2.1/include/GL/freeglut.h"
#include <GL/glut.h>
#include <iostream>
using namespace std;

float x1, x2, y1, y2;

void display(void)
{
  float dy, dx, step, x, y, k, Xin, Yin;
  dx = x2 - x1;
  dy = y2 - y1;
  if (abs(dx) > abs(dy)) {
    step = abs(dx);
  } else
    step = abs(dy);
  Xin = dx / step;
  Yin = dy / step;
  x = x1;
  y = y1;
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
  for (k = 1; k <= step; k++) {
    x = x + Xin;
    y = y + Yin;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
  }
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
  
  printf("Value of x1 : ");
  scanf("%f", & x1);
  printf("Value of y1 : ");
  scanf("%f", & y1);
  printf("Value of x2 : ");
  scanf("%f", & x2);
  printf("Value of y2 : ");
  scanf("%f", & y2);
  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(200,300);
  glutInitWindowPosition(500,100);
  glutCreateWindow("Meow");
   glutDisplayFunc(display);
  myInit();
 glutMainLoop();
}
