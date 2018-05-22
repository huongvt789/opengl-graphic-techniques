#include "stdafx.h"
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
static GLfloat spin = 0.0f;
static float tt = 0.0;
static float cd = 0.0;
GLfloat step = 3.14 / 6.0;
GLfloat angle, r;
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0);
	glTranslatef(25.0, 25.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(25.0, 25.0, 0.0);

	/*register int i;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < 12; ++i) {
		r = (i % 2 == 0 ? 50 : 100);
		angle = i * step;

		glVertex3f(r*cos(angle), r*sin(angle), 0.0);
	}
	glEnd(); */
	glRectf(-25.0, -25.0, 25.0, 25.0);// Lenh ve hinh chu nhat.
	glPopMatrix();
	glutSwapBuffers();
}
void spinDisplay(void) {
	spin = spin + 0.02;
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void mouse(int type_button, int state, GLint x, GLint y)
{
	switch (type_button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;

	case GLUT_RIGHT_BUTTON: //Quay mot goc 15 do.
		if (state == GLUT_DOWN)
			glRotatef(15, 0.0, 0.0, 1.0);
			glutIdleFunc(NULL);
	default:
		break;
	}
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 's':
		spin = spin + 2;
		if (spin > 360.0)
			spin = spin - 360.0;
		glutPostRedisplay();
		break;
	case 'a': //Phong to gap doi.
		glScalef(2.0 , 2.0, 2.0);
		glutPostRedisplay();
		break;
	case 'y':
		//glTranslatef(0.0, 1.0, 0.0);
		glRotatef(360, 1.0, 1.0, 0.0); ///quay theo truc X
		//glTranslatef(0.0, 1.0, 0.0);

		glutPostRedisplay();
		break;
	default:
		break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}