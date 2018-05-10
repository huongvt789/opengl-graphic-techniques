// Cau2DDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Cau2Bresenham.cpp : Defines the entry point for the console application.
//


#include <GL/glut.h>
void DDA(int x1, int y1, int x2, int y2)
{
	int dx, dy, x, y; x = x1; y = y1;
	dx = x2 - x1; dy = y2 - y1;
	float k;
	k = (float)dy / (float)dx;
	if (k>1) {
		while (y <= y2)
		{
			glVertex2f(x, y);
			y++;
			x = x + 1 / k;
		}
	}
	else if (0 <= k <= 1) {
		while (x < x2)
		{
			glVertex2f(x, y);
			x++;
			y = y + k;
		}
	}
	else if (0 > k >= -1) {
		while (x<x2)
		{
			glVertex2f(x, y);
			x++;
			y = y - k;
		}
	}
	else {
		while (y < y2) {
			glVertex2f(x, y);
			y++;
			x = x - 1 / k;
		}
	}
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	DDA(10, 10, 50, 80);
	
	DDA(10, 10, -90, 50);
	glEnd();
	glFlush();
}
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 200.0, 0.0, 200.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);// Kh?i t?o Glut và x? lí m?i dòng l?nh d?i s?, glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);// s? d?ng mô hình RGBA
	glutInitWindowSize(250, 250);// kích c? c?a s? 
	glutInitWindowPosition(100, 100);// ch? ra v? trí màn hình góc trên bên trái
	glutCreateWindow("hello"); // T?o tiêu d? c?a s? “hello”
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


