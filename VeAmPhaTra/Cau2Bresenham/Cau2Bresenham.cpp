// Cau2Bresenham.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL/glut.h>


void bre(int x1, int y1, int x2, int y2, int n)
{
	unsigned long pattern = 0xff00ff00;
	unsigned long mask = 0x80000000;
	int dx, dy, x, y, d,dx1,dy1; x = x1; y = y1;
	dx = x2 - x1; dy = y2 - y1;
	float k;
	k = (float)dy / (float)dx; //k>1
	if (k > 1) {
		d = 2*dx-dy;
		while (y <= y2)
		{
			
			for (int i = -n / 2; i < n / 2; i++) {
				//mask = mask ? mask : 0x80000000;
				 if(x % 10 < 5) 
				 glVertex2f(x + i, y);

					if (d <= 0)
					{
						d = d + 2 * dx;
					}
					else { d = d + 2 * (dx - dy); x++; }	
					//if(pattern & mask)
					//glVertex2f(x + i, y);
					y++;
					//mask >> -1;
					i++;	
			}
		}
	}
	else  if (k<1){
		d = dx - 2 * dy;
		while (x <= x2)
		{
			glVertex2f(x, y);
			if (d>0) d = d - 2 * dy;
			else { d = d + 2 * dx - 2 * dy; y++; }
			x++;
		}
	}
	if(k<-1) {
		d = 2 * dx - dy;
		while (y <= y2)
		{
			x = -x;
			for (int i = -n / 2; i < n / 2; i++) {
				//mask = mask ? mask : 0x80000000;
				if (x % 10 < 5)
					glVertex2f(x + i, y);

				if (d <= 0)
				{
					d = d + 2 * dx;
				}
				else { d = d + 2 * (dx - dy); x--; }
				//if(pattern & mask)
				//glVertex2f(x + i, y);
				//mask >> -1;
				y++;
				i++;
			}
		}
	}
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	bre(10, 10, -80, 150, 8);
	glEnd();
	glFlush();
}
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-150.0, 150.0, -150.0, 150.0, -1.0, 1.0);
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
