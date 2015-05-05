#include <GL/glut.h>
#include<math.h>
GLsizei winWidth = 500, winHeight = 500;
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}
void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	/*glBegin(GL_POINTS);
	for(i=0;i<361;i++)
	{
			x=cx+r*cos(i*PI/180);
			y=cy+r*sin(i*PI/180);
			glVertex2f(x,y);
	} 
	glEnd();
	GLUquadricObj *cylinder;
	glPushMatrix();
	glTranslatef(0.0, 1.2, 0.8);
	cylinder = gluNewQuadric();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluCylinder(cylinder, 0.6, 0.6, 1.5, 6, 4);
	glPopMatrix();*/
	gluLookAt(5.0,5.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
	glScalef(1.5,2.0,1.0);
	glutWireCube(1.0);
	/*glScalef(0.8,0.8,1.0);
	glTranslatef(4.3,-2.0,0.5);
	glutWireIcosahedron();*/
	glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth,winHeight);
	glutCreateWindow("Samples");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
	return 0;
}