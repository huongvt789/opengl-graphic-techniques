// VeOTo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//=================================================================

#include <GL/glut.h>
static int day = 0;
float g_height = 5.0;
float g_width = 7.0;
 
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glRotatef(45, 0, 0, 1); //Độ nghiêng.
	glScalef(15, 0.6, 5);
	glutWireCube(1.0);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);

	glTranslatef(g_height, g_width, 0); //Xử lý vị trí tai đây.
	
	glTranslatef((GLfloat)day / 40, (GLfloat)day / 40, 0);
	glRotatef(((GLfloat)day)*(-1), 0, 0, 1);

	glutWireSphere(1.0, 30, 16); //Câu lệnh này là nơi để xử lý vẽ nên hình.

	glPopMatrix();
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
	case 'm':
		day = (day + 1) / 1.1;
		glutPostRedisplay();
		break;
	case 'n':
		day = (day - 1)*1.1;	
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
void MouseButton(int type_button, int state, GLint x, GLint y)
{

	if (type_button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			for (int i = 0; i < 10; i++)
			{
				glPushMatrix();
				glColor3f(1.0, 0.0, 1.0);
				glTranslatef(g_height, g_width, 0.0);
				glutPostRedisplay();
				glPopMatrix();
				g_height -= g_height;
				g_width -= g_width;
				i++;
			}

		}
		else
		{
			for (int i = 0; i < 10; i++)
			{
				glPushMatrix();
				glColor3f(1.0, 0.0, 1.0);
				glTranslatef(g_height, g_width, 0.0);
				glutPostRedisplay();
				glPopMatrix();
				g_height += g_height;
				g_width += g_width;
				i++;
			}
		}
	}
}
void MouseMove(int x, int y){
	int a = 5;
}
void init(void)
{
	glClearColor(0.0, 0.0, 1.0, 1.0);
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
	glutMouseFunc(MouseButton);
	glutMainLoop();
	return 0;
}



