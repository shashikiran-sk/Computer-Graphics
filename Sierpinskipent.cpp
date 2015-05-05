#include <GL/glut.h>
#include <cstdlib>

// A simple two-dimensional point class to make life easy.  It allows you to
// reference points with x and y coordinates instead of array indices) and
// encapsulates a midpoint function.
struct Point {
	GLfloat x, y;
	Point(GLfloat x = 0, GLfloat y = 0) : x(x), y(y) {}
	Point midpoint(Point p) { return Point((x + p.x) / 2.0, (y + p.y) / 2.0); }
};

// Draws a Sierpinski triangle with a fixed number of points. (Note that the
// number of points is kept fairly small because a display callback should
// NEVER run for too long.
void display() {

	glClear(GL_COLOR_BUFFER_BIT);

	static Point vertices[] = { Point(0, 0), Point(250, 433), Point(500, 0) };
	static Point vertices2[] = { Point(0, 0), Point(250, -433), Point(500, 0) };
	static Point vertices3[] = { Point(-250, 433), Point(0, 0), Point(250, 433) };
	static Point vertices4[] = { Point(-250, -433), Point(0, 0), Point(250, -433) };
	static Point vertices5[] = { Point(-500, 0), Point(-250, 433), Point(0, 0) };
	static Point vertices6[] = { Point(-500, 0), Point(-250, -433), Point(0, 0) };

	// Compute and plot 100000 new points, starting (arbitrarily) with one of
	// the vertices. Each point is halfway between the previous point and a
	// randomly chosen vertex.
	static Point p = vertices[0];
	glBegin(GL_POINTS);
	for (int k = 0; k < 50000; k++) {
		p = p.midpoint(vertices[rand() % 3]);
		glVertex2f(p.x, p.y);
	}
	for (int k = 0; k < 50000; k++) {
		p = p.midpoint(vertices2[rand() % 3]);
		glVertex2f(p.x, p.y);
	}
	for (int k = 0; k < 50000; k++) {
		p = p.midpoint(vertices3[rand() % 3]);
		glVertex2f(p.x, p.y);
	}
	for (int k = 0; k < 50000; k++) {
		p = p.midpoint(vertices4[rand() % 3]);
		glVertex2f(p.x, p.y);
	}
	for (int k = 0; k < 50000; k++) {
		p = p.midpoint(vertices5[rand() % 3]);
		glVertex2f(p.x, p.y);
	}
	for (int k = 0; k < 50000; k++) {
		p = p.midpoint(vertices6[rand() % 3]);
		glVertex2f(p.x, p.y);
	}
	glEnd();
	glFlush();
}

// Performs application-specific initialization. Sets colors and sets up a
// simple orthographic projection.
void init() {

	// Set a deep purple background and draw in a greenish yellow.
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0);

	// Set up the viewing volume: 500 x 500 x 1 window with origin lower left.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500.0, 500.0, -500.0, 500.0, 0.0, 1.0);
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(40, 40);
	glutCreateWindow("Sierpinski Triangle");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}