#include "stdafx.h"
#include <GL/glut.h>
#include <stdlib.h>

GLubyte rasters[40] = {
	0x70, 0x7c, 0x88, 0x42, 0x88, 0x52, 0x48, 0x52, 0x28, 0x5c, 0x8, 0x40, 0xa, 0x40, 0xe,
	0x40, 0xb, 0x40, 0x8, 0x40, 0x8, 0xe0, 0x68, 0x50, 0x88, 0x50, 0xfc,
	0x50, 0x8, 0x70 };
GLubyte rasters1[8] = {
	0x7e, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x03 };
GLubyte rasters2[8] = {
	0x38, 0x44, 0x82, 0x44, 0x38, 0x0c, 0x00, 0x3c };

GLubyte rasters3[8] = {
	0x43, 0x42, 0x42, 0x42, 0x42, 0x42, 0xfe, 0x00 };

GLubyte rasters4[8] = {
	0x18, 0x14, 0x0a, 0x06, 0x3e, 0x42, 0x42, 0x3c };
void init(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2i(20, 20);
	glBitmap(13, 14, 0.0, 0.0, 9.0, 0.0, rasters);
	glBitmap(8, 8, 0.0, 0.0, 9.0, 0.0, rasters1);
	glBitmap(8, 8, 0.0, 0.0, 9.0, 0.0, rasters2);
	glBitmap(8, 8, 0.0, 0.0, 9.0, 0.0, rasters3);
	glBitmap(8, 8, 0.0, 0.0, 9.0, 0.0, rasters4);
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(200, 200);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}