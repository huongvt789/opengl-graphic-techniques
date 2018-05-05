// Bresenham2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <GL/glut.h>

void bre(int x1, int y1, int x2, int y2,int n)
{
	int dx, dy, x, y, d; 
	x = x1; y = y1;
	dx = x2 - x1; dy = y2 - y1; d = dx - 2 * dy;
	float k = (float)dx /(float) dy;
	if (k = 0)
	{
		d = 2 * dy - dx;
		while (x <= x2)
		{
			glVertex2f(x, y);
			glVertex2f(n*x, n*y);

			if ((d >= 0) && (d < 1))
			{
				y++;
				d = d + (2 * dy - 2 * dx);
			}
			else { d = d + 2 * dy; }
			x++;
			n--;
		}
	}
	if((k>= -1) && (k<0)){
		d = 2 * dy + dx;
		while (x <= x2)
		{
			glVertex2f(x, y);
			glVertex2f(n*x, n*y);
			if (d < 0) {
				y--;
				d = d + (2 * dy + 2 * dx);
			}
			else {
				d = d + 2 * dy;
			}
			x++;
			n--;
		}
	}
	if (k > 1) {
		d = 2 * dx - dy;
		while (y < y2)
		{
			glVertex2f(x, y);
			glVertex2f(n*x, n*y);
			if (d >= 0) {
				x++;
				d = d + (2 * dx - 2 * dy);
			}
			else {
				d = d + 2 * dx;
			}
			y++;
			n--;
		}
	}
	if (k <= -1) {
		d = 2 * dx + dy;
		while (y < y2)
		{
			glVertex2f(x, y);
			glVertex2f(n*x, n*y);
			if (d < 0) {
				d = d + (2 * dx + 2 * dy);
				x--;
			}
			else {
				d = d + 2 * dx;
			}
			y++;
			n--;
		}
	}
	
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Xoa bo dem đưa về trang thái ban đầu.
	glColor3f(2.0, 2.0, 2.0);
	glBegin(GL_POINTS);
	bre(10, 10, 100, 80, 3);
	glEnd();
	glFlush();
}
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 640.0, 0.0, 200.0,0.0,0.0);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);;// Kh?i t?o Glut và x? lí m?i dòng l?nh d?i s?, glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);// s? d?ng mô hình RGBA
	glutInitWindowSize(250, 250);// kích c? c?a s? 
	glutInitWindowPosition(100, 100);// ch? ra v? trí màn hình góc trên bên trái
	glutCreateWindow("hello"); // T?o tiêu d? c?a s? “hello”
	init();
	glutDisplayFunc(display);
	glutMainLoop();
    return 0;
}

