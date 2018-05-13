/*#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

using namespace std;

double goc = 0.005;
bool trangthai = false;

void init(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-7.0, 7.0, -7.0, 7.0, -1.0, 1.0);
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1, 0, 1);
glRotatef(goc,0,0,1);
glutWireShpere(1.0,20,16);

glutSwapBuffers();

glEnd();
glFlush();
}
void keyboard (unsigned char key, int x, int y) // an d de thang toc do quay , s de giam toc do quay
{
switch (key)
{
case 'd': goc = goc *2; glutPostRedisplay(); break;
case 's': goc = goc /2; glutPostRedisplay(); break;
default: break;
}
}
void spinDisplay(void) //ham  de chay lai ham display
{
if (goc > 360.0)
goc = goc - 360.0;
glutPostRedisplay();
}
void mouse(int button, int state, int x, int y) //an chuot trai de quay nguoc chieu kim dong ho, chuot phai de quay theo chieu kim dong ho
{
switch (button) {
case GLUT_LEFT_BUTTON:
if (state == GLUT_DOWN)
if(!trangthai){
glutIdleFunc(spinDisplay);
goc = abs(goc);
trangthai = true;
break;
}else{
glutIdleFunc(NULL);
trangthai = false;
break;
}
case GLUT_RIGHT_BUTTON:
if (state == GLUT_DOWN)
if(!trangthai){
glutIdleFunc(spinDisplay);
goc = -abs(goc);
trangthai = true;
break;
}else{
glutIdleFunc(NULL);
trangthai = false;
break;
}
default:
break;
}
}
int main(int argc, char** argv){
glutInit(&argc, argv);  //
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("");
init();
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
glutMouseFunc(mouse);
glutMainLoop();
return 0;
}
*/

#include "stdafx.h"
#include <GL/glut.h>

static int gocquay = 0;

void init(void)

{

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_FLAT);

}

void display(void)

{

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();



	glRotatef((GLfloat)gocquay, 0.0, 1.0, 0.0);/*quay tit*/
	glTranslatef(0.0, 0.0, -3.0); /*vi tri ban dau*/
	glutWireSphere(0.5, 30, 16); /* ve khoi cau */

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

	gluLookAt(0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);

}

void keyboard(unsigned char key, int x, int y)

{

	switch (key) {

	case 'n':
		gocquay = (gocquay) % 360;
		glTranslatef(0.1, 0.1, 0.05);
		glutPostRedisplay();
		break;
	case 'm':
		gocquay = (gocquay) % 360;
		glTranslatef(0. - 1, 0. - 1, 0.05);
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

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("");

	init();

	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;

}
