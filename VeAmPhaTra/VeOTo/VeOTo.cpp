// VeOTo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//=================================================================

#include <GL/glut.h>
static int day = 0;
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(45, 0, 0, 1);
	glScalef(15, 0.6, 5);
	glutWireCube(1.0);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(5, 7, 0);
	glTranslatef((GLfloat)day / 40, (GLfloat)day / 40, 0);
	glRotatef(((GLfloat)day)*(-1), 0, 0, 1);
	glutWireSphere(1, 20, 15);					glPopMatrix();
	glutSwapBuffers();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 20, 0.0, 0.0, 0.0, 0, 1, 0);
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'a':
		day = (day + 1) / 1.1;					glutPostRedisplay();
		break;
	case ',':
		day = (day - 1)*1.1;				glutPostRedisplay();
		break;
	default:
		break;
	}
}
void init(void)
{
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(1, 0);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}



