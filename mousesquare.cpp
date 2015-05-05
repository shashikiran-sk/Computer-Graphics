#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
int  w = 400, h = 300;
int side = 40;
void init(void)
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(0.0, w, 0.0, h);
	glMatrixMode(GL_MODELVIEW);

}
void displayFcn()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glFlush();

}
void drawsquare(int x, int y)
{
	float t;
	y = h - y;
	t = side / 2.0;
	glBegin(GL_POLYGON);
	glVertex2f(x + t, y + t);
	glVertex2f(x + t, y - t);
	glVertex2f(x - t, y - t);
	glVertex2f(x - t, y + t);
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
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(w,h);
	glutCreateWindow("Square");
	init();
	glutDisplayFunc(displayFcn);
	glutMouseFunc(mymouse);
	glutMainLoop();
}