#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
GLsizei winWidth = 400, winHeight = 300;
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);

}
void displayFcn()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glFlush();

}
int size = 50;
void drawsquare(int x, int y)
{
	glBegin(GL_POLYGON);
	glVertex2f(x + size, y + size);
	glVertex2f(x - size, y + size);
	glVertex2f(x - size, y - size);
	glVertex2f(x + size, y - size);
	glEnd();
	glFlush();
}
void mymouse(int btn, int st, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && st == GLUT_DOWN)
		drawsquare(x, y);
	if (btn == GLUT_RIGHT_BUTTON && st == GLUT_DOWN)
		exit(0);
}
void myreshape(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
	glClear(GL_COLOR_BUFFER_BIT);
	winWidth = newWidth;
	winHeight = newHeight;
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Square");
	init();
	glutReshapeFunc(myreshape);
	glutDisplayFunc(displayFcn);
	glutMouseFunc(mymouse);
	glutMainLoop();
}