#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
//#include <imageio.h>
int angle=0;
void Sphere()
{	
	GLUquadricObj* Sphere;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
    glTranslatef(0,0,0);
    glPushMatrix();
    Sphere=gluNewQuadric();
    glColor3f(1, 0, 1);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); 
     //float ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
     float diffuseLight[] = { 0.8f, 0.8f, 1.0f, 1.0f };
     //float specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f }; 
     float position[] = { -1.5f, 1.0f, -4.0f, 1.0f }; 
     // Assign created components to GL_LIGHT0 
     //glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight); 
     glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight); 
     //glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight); 
     glLightfv(GL_LIGHT0, GL_POSITION, position);
    glRotatef(angle,0.0f, 1.0f, 0.0f); 
	//glRotatef(angle,0.0f,1.0f,0.0f);
    gluSphere(Sphere,0.5f,32,32);
    //glPopMatrix(); 
    glutSwapBuffers();
    glPopMatrix(); 
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glFlush();
     angle+=2.0f;
    if(angle>360.f)
    {
        angle=0;
    }
}
void init() {

  
  glClearColor(0,0,0.8,0);
  glColor3f(0, 0, 0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1000.0, 1000.0, -1000.0, 1000.0, 1000.0, 1000.0);
}
void update(int value)
{
	
    glutPostRedisplay();
    glutTimerFunc(40,update,0);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Sphere");
	init();
	glutDisplayFunc(Sphere);
	glRotatef(angle, 1.0f, 0.0f, 0.0f);
	glutTimerFunc(40,update,0);
	glutMainLoop();
	
}