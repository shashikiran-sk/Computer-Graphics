#include <GL\glut.h>
#include<stdlib.h>
#include<stdio.h>
#define sq 10
void init()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(-200,200,-200,200);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glNewList(sq, GL_COMPILE);
	glBegin(GL_POLYGON);
	glVertex2f(-50, -50);
	glVertex2f(-50, 50);
	glVertex2f(50, 50);
	glVertex2f(50, -50);
	glEnd();
	glEndList();
	glCallList(sq);
	glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("Display List");
	init();
	glutDisplayFunc(display);
	//glutKeyboardFunc(keyboard);
	glutMainLoop();
}
