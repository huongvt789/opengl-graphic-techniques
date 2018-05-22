
#include "stdafx.h"
#include <GL/glut.h>
static int day = 0;
float g_height = 5.0;
float g_width = 7.0;
void setMaterial(GLfloat ambientR, GLfloat ambientG, GLfloat ambientB,
	GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
	GLfloat specularR, GLfloat specularG, GLfloat specularB,
	GLfloat shininess) {
	GLfloat ambient[] = { ambientR, ambientG, ambientB };
	GLfloat diffuse[] = { diffuseR, diffuseG, diffuseB };
	GLfloat specular[] = { specularR, specularG, specularB };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}
void display(void)
{
	/* draw scene 
	glPushMatrix();
	
	glPushMatrix();
	glTranslatef(0.0, 0.0, -3.0);
	glutWireTeapot(1.0);                // middle teapot
	glTranslatef(0.0, 2.0, 0.0);
	
	glutSolidTeapot(1.0);               // top teapot
	glPopMatrix();

	glTranslatef(0.0, -2.0, -1.0);
	glutSolidTeapot(1.0);               // bottom teapot

	glPopMatrix();
	glFlush(); */
	/* clear window */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* future matrix manipulations should affect the modelview matrix */
	glMatrixMode(GL_MODELVIEW);
	/* draw scene 
	//YourSefl:
	//B1. tính tiến vị trí xuất phát của Oto:
	glPushMatrix();
	glTranslatef(0.5, 0.65, 0.0);
	//B2: Vẽ phần thân của Oto:
	glPushMatrix();
	//B2.1 Vẽ thân trên của OTO.
	glPushMatrix();                   // body
	glScalef(1, .5, 2);
	glutSolidCube(0.5);
	glPopMatrix();
	//B2.2. Vẽ bánh xe
	//B2.2.1 Tính tiến vị trí của các bánh xe.
	glTranslatef(0, 0, .23);
	//B2.2.2 . Vẽ bánh xe.
	glPushMatrix();
	//glScalef(2, -0.5, 1);
	glRotatef(-90, 0, 1.0, 0);
	glTranslatef(-.4, -.2, 0);

	glutSolidTorus(.05, .15, 9, 9);       // wheel
	glTranslatef(.45, .05, -.2);  //Tính tiến lại gần thân xe
	glutSolidTorus(.05, .15, 9, 9);       // wheel
	glPopMatrix();
	glTranslatef(0, 0, -.6);

	glPushMatrix();
	glTranslatef(-.4, -.2, 0);
	glRotatef(300, 1.0, .0, 0.0);
	glutSolidTorus(.05, .15, 9, 9);       // wheel
	glTranslatef(.6, 0, 0); //Tính tiến lại gần thân xe

	glutSolidTorus(.05, .15, 9, 9);       // wheel
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	// house
	 /*glPushMatrix();
	glutSolidCube(2);                 // building

	glTranslatef(0, 1, 0);
	glPushMatrix();                   // roof
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(1.5, 1, 16, 8);
	glPopMatrix();

	glTranslatef(.75, .5, -.75);
	glPushMatrix();                   // chimney
	glScalef(1, 3, 1);
	glutSolidCube(.25);
	glPopMatrix();
	glPopMatrix();
	//car.
	glTranslatef(0, -.65, 2);
	glPushMatrix();
	glPushMatrix();                   // body
	glScalef(2, .5, 1);
	glutSolidCube(.5);
	glPopMatrix();
	glTranslatef(0, 0, .25);
	glPushMatrix();
	glTranslatef(-.4, -.2, 0);
	glutSolidTorus(.05, .1, 8, 8);       // wheel
	glTranslatef(.8, 0, 0);
	glutSolidTorus(.05, .1, 8, 8);       // wheel
	glPopMatrix();
	glTranslatef(0, 0, -.5);
	glPushMatrix();
	glTranslatef(-.4, -.2, 0);
	glutSolidTorus(.05, .1, 8, 8);       // wheel
	glTranslatef(.8, 0, 0);
	glutSolidTorus(.05, .1, 8, 8);       // wheel
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	*/
	setMaterial(1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 50);
	glPushMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glRotatef(45, 0, 0, 1); //Độ nghiêng.
	glScalef(15, 0.6, 5);
	glutWireCube(1.0);
	glPopMatrix();

	//glTranslatef(g_height, g_width, 0); //Xử lý vị trí tai đây.

	glTranslatef((GLfloat)day / 40, (GLfloat)day / 40, 0);
	//glRotatef(((GLfloat)day)*(-1), 0, 0, 1);

	glPushMatrix();                   // body

	glScalef(1, .5, 2);
	glutSolidCube(.5);

	glTranslatef(0.42,1.2,0.15);
	glutSolidCube(.35);
	glPopMatrix();

	glTranslatef(0.0, 0, 0.25);

	glPushMatrix();
	glTranslatef(-.4, -.2, 0);
	glutSolidTorus(.05, .1, 9, 9);       // wheel
	glTranslatef(.6, 0, 0);
	glutSolidTorus(.05, .1, 9, 9);       // wheel
	glPopMatrix();
	
	glTranslatef(0, 0, -.5);
	
	glPushMatrix();
	glTranslatef(-.4, -.2, 0);
	glutSolidTorus(.05, .1, 9, 9);       // wheel
	glTranslatef(.6, 0, 0);
	glutSolidTorus(.05, .1, 9, 9);       // wheel
	glPopMatrix();
	
	glPopMatrix();
	glFlush();
	glutSwapBuffers();

}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
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
void MouseMove(int x, int y) {
	int a = 5;
}
void init(void)
{
	glClearColor(0.0, 0.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}
int main(int argc, char** argv)
{
	/* initialize GLUT, using any commandline parameters passed to the
	program */
	glutInit(&argc, argv);
	init();
	/* setup the size, position, and display mode for new windows */
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

	/* create and set up a window */
	glutCreateWindow("hello, car!");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	/* set up depth-buffering */
	glEnable(GL_DEPTH_TEST);

	/* turn on default lighting */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	/* define the projection transformation */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 4, 20);

	/* define the viewing transformation */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutKeyboardFunc(keyboard);

	/* tell GLUT to wait for events */
	glutMainLoop();
}



