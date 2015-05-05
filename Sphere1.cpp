#include <GL/glut.h>
GLsizei winWidth = 500, winHeight = 500;
void init()
{
	glClearColor(0,0,0.0, 0.0);
}
void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-500.0, 500.0, -500.0, 500.0, -500.0, 500.0);
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);

}
void display()
{
	glPushMatrix();
	GLUquadricObj *qObj = gluNewQuadric();
	gluQuadricNormals(qObj, GLU_SMOOTH);
	gluQuadricTexture(qObj, GL_TRUE);
	//glTranslatef(0, translation, 0);
	gluSphere(qObj, 1.0f, 24, 24);
	glPopMatrix();
	glFlush();
	
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(winWidth,winHeight);
	glutCreateWindow("Solid Sphere");
	init();
	glutReshapeFunc(winReshapeFcn);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}