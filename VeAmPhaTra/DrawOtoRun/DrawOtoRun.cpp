#include "stdafx.h"
#include <GL/glut.h>
#include <stdlib.h>
GLubyte a[40] ={
	 0x00,  0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18
};
GLubyte rasters[24] = 
{ 
	0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xff, 0x00, 0xff, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 
	0xff, 0xc0, 0xff, 0xc0 };
GLubyte d[36] = // chữ Đ
{ 0x73, 0xC0,
0xDF,  0xE0,
0xDE,  0x60,
0x78, 0x30,
0x28, 0x30,
0x08, 0x18, // 
0x1C, 0x1C,
0x3E, 0x0C,
0x1C, 0x1C,
0x08, 0x38, //
0x08, 0x10,
0x88, 0x30, //
0xC8, 0xF0,
0x6B, 0xE0,
0x3F, 0x80,
0x1C, 0x00,
0x02, 0x00,
0x01, 0x00 }; // từ trái qua phải và từ dưới lên trên // dòng 1

GLubyte i[26] = // chữ i
{};

 GLubyte e[16] = // chữ ê
 {};

 GLubyte n[16] = // chữ n
 {};

 GLubyte huyen[16] = // dấu `
 {};

void init(void) {
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); 
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2i(20, 20); 

	glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, rasters); 
	glBitmap(14, 17, 0.0, 0.0, 10.0, 0.0, d); // Hiển thị chiều cao và chiều rộng chữ D
	
											  //glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
	//glBitmap(10, 12, 0.0, 0.0, 11.0, 0.0, rasters);
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW); }
void keyboard(unsigned char key, int x, int y)
{ 
	switch (key) {
	case 27:     
	exit(0); }
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);  
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300, 300);  
	glutInitWindowPosition(100, 100); 
	glutCreateWindow(argv[0]); 
	init();  
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard); 
	glutDisplayFunc(display);
	glutMainLoop(); 
	return 0;
}
