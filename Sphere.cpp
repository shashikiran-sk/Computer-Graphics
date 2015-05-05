#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>
#define TWOPI 2*3.142
#define PI 3.142
typedef struct {
  double x;
  double y;
  double z;
} XYZ;

int angle=0;
void update(int value) {
   glutPostRedisplay();      
   glutTimerFunc(20, update, 0); 
}
void CreateSphere(XYZ c,double r,int n)
{
   int i,j;
   double phi1,phi2,theta, s, t;
   XYZ e,p;

   if (r < 0)
      r = -r;
   if (n < 0)
      n = -n;
   if (n < 4 || r <= 0)
   {  glColor3f(1,1,0);
      glBegin(GL_POINTS);
      glVertex3f(c.x,c.y,c.z);
      glEnd();
      return;
   }

   for (j=0;j < n; j++) {
      phi1 = j * TWOPI / n;
      phi2 = (j + 1) * TWOPI / n;	//next phi
      glColor3f(1,1,0);
      glBegin(GL_QUAD_STRIP);
      for (i=0;i < n;i++) {
         theta = i * PI / n;

        e.x = sin ( theta ) * cos ( phi2 );
	      e.y = sin ( theta ) * sin ( phi2 );
        e.z = cos ( theta );
        p.x = c.x + r * e.x;
        p.y = c.y + r * e.y;
        p.z = c.z + r * e.z;

        glNormal3f(e.x,e.y,e.z);
        s = phi2 / TWOPI;          // column
        t = 1 - theta/PI;          // row
	      glTexCoord2f(s, t);
        glVertex3f(p.x,p.y,p.z);

        e.x = sin ( theta ) * cos ( phi1 );
	      e.y = sin ( theta ) * sin ( phi1 );
        e.z = cos ( theta );
        p.x = c.x + r * e.x;
        p.y = c.y + r * e.y;
        p.z = c.z + r * e.z;

        glNormal3f(e.x,e.y,e.z);
        s = phi1/TWOPI;        // column
        t = 1 - theta/PI;      // row
        glTexCoord2f(s, t);
 
	      glVertex3f(p.x,p.y,p.z);
      }
      glEnd();
   }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);   
    glMatrixMode(GL_MODELVIEW);     
    glLoadIdentity(); 
    glColor3f(1, 0, 1);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); 
     //float ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
     float diffuseLight[] = { 0.8f, 0.8f, 1.0f, 1.0f };
     //float specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f }; 
     //float position[] = { -1.5f, 1.0f, -4.0f, 1.0f }; 
     // Assign created components to GL_LIGHT0 
     //glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight); 
     glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight); 
     //glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight); 
     //glLightfv(GL_LIGHT0, GL_POSITION, position);
    glRotatef(angle,1.0f, 0.0f, 0.0f);          
    glRotatef(angle,1.0f, 0.0f, 0.0f);
    CreateSphere({0,0,0},400,100);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    
    //glPushMatrix();
    glFlush();
    for(int i=0;i<10000000;i++);
    angle+=5;
    if(angle>360)
      angle=0;
    
}
void Mouse(int button,int state,int x,int y)
{
 
    // x-axis rotation
    if (button == GLUT_LEFT_BUTTON && state==GLUT_DOWN) 
    {
      glRotatef(angle,1.0f, 0.0f, 0.0f);
    }
    // y-axis rotation
    else if (button == GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
      glRotatef(angle,0.0f, 1.0f, 0.0f);
    }
    // z-axis rotation
    else {
      glRotatef(angle,0.0f, 0.0f, 1.0f);
    }
  
}
void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500.0, 500.0, -500.0, 500.0, -500.0, 500.0);
    glColor3f(1,1,1);
}
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
    glOrtho(-4.0, 4.0, -4.0 * (GLfloat) h / (GLfloat) w,
            4.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt ( 5, 0, 0, 0, 0, 0, 0, 0, 1 );
}
int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Sphere");
  init();
  glutDisplayFunc(display);
  //glRotatef(angle, 1.0f, 0.0f, 0.0f);
  glutTimerFunc(40,update,0);
  //glutReshapeFunc(reshape);
  //glutMouseFunc(Mouse);
  glutMainLoop();
  
}