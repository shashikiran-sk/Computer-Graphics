#include <GL\glut.h>
#include<stdio.h>
float xm, ym, xmm, ymm;
int first = 0, w = 600, h = 600;
void init()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
}
void disp()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glLineWidth(5);
	glFlush();
}
void mouse(int b, int s, int x, int y)
{
	glColor3f(0, 0, 1);
	y = h - y;
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
	{
		xm = x;
		ym = y;
		first = 0;
	}
	if (b == GLUT_LEFT_BUTTON && s == GLUT_UP)
	{
		glLogicOp(GL_XOR);
		glBegin(GL_LINES);
		glVertex2f(xm, ym);
		glVertex2f(xmm, ymm);
		glEnd();
		glFlush();
		glLogicOp(GL_COPY);
		glBegin(GL_LINES);
		glVertex2f(xm, ym);
		glVertex2f(xmm, ymm);
		glEnd();
		glFlush();

	}
	if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();

	}
	glFlush();
}
void move(int x,int y)
{
	y = h - y;
	if (first == 1)
	{
		glLogicOp(GL_XOR);
		glBegin(GL_LINES);
		glVertex2f(xm, ym);
		glVertex2f(xmm, ymm);
		glEnd();
	}
	xmm = x;
	ymm = y;
	glLogicOp(GL_XOR);
	glBegin(GL_LINES);
	glVertex2f(xm, ym);
	glVertex2f(xmm, ymm);
	glEnd();
	glFlush();
	first = 1;
}
int main(int argc,char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("Rubberband Technique");
	init();
	glEnable(GL_COLOR_LOGIC_OP);
	glutDisplayFunc(disp);
	glutMouseFunc(mouse);
	glutMotionFunc(move);
	glutMainLoop();
}