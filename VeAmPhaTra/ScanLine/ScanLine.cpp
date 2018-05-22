#include "stdafx.h"
// Bai3.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include <GL/glut.h>

//khai báo ra Font F.
 GLubyte rasters[24] = {
0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
0xc0, 0x00, 0xff, 0x00, 0xff, 0x00, 0xc0, 0x00,
0xc0, 0x00, 0xc0, 0x00, 0xff, 0xc0, 0xff, 0xc0 }; 

GLubyte d[36] = // chữ Đ
{ 0x73, 0xC0,
0xDF,  0xE0,
0xDE,  0x60,
0x78, 0x30,
0x28, 0x30,
0x08, 0x18,
0x1C, 0x1C,
0x3E, 0x0C,
0x1C, 0x1C,
0x08, 0x38,
0x08, 0x10,
0x88, 0x30,
0xC8, 0xF0,
0x6B, 0xE0,
0x3F, 0x80,
0x1C, 0x00,
0x02, 0x00,
0x01, 0x00 }; // từ trái qua phải và từ dưới lên trên // dòng 1

GLubyte i[26] = // chữ i
{};

// GLubyte e[16] = // chữ ê
// {};

// GLubyte n[16] = // chữ n
// {};

// GLubyte huyen[16] = // dấu `
// {};


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 50.0, 0.0, 50.0, -1.0, 1.0);

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //xóa mọi pixel 
	glColor3f(1.0, 1.0, 1.0); // màu nền trắng 

	glRasterPos2i(25, 25); // Tọa độ hiển thị của F trên màn hình 

						   // glBitmap(rộng, cao, tọa độ X0 = 0.0, tọa độ Y0 = 0.0, tọa độ Xi = ..., tọa độ Yi= ...; tên mảng chữ mà ta viết)

	glBitmap(14, 17, 0.0, 0.0, 10.0, 0.0, d);
	// Hiển thị chiều cao và chiều rộng chữ D
											  // glBitmap(10, 10, 0.0, 0.0, 13.0, 0.0, i); // Hiển thị chiều cao và chiều rộng chữ i

											  // glBitmap(10, 10, 0.0, 0.0, 13.0, 0.0, e); // Hiển thị chiều cao và chiều rộng chữ ê
											  // glBitmap(10, 10, 0.0, 0.0, 13.0, 0.0, n); // Hiển thị chiều cao và chiều rộng chữ n
											  // glBitmap(10, 10, 0.0, 0.0, 13.0, 0.0, huyen); // Hiển thị chiều cao và chiều rộng dấu huyền 

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);  // 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// khởi tạo chế độ vẽ single buffer và hệ màu RGB
	glutInitWindowSize(200, 200);// khởi tạo cửa sổ hiển thị-window có kích thước 200x200
	glutInitWindowPosition(100, 100);// khởi tạo window tại vị trí (100,100) trên screen
	glutCreateWindow(""); // Tên của cửa sổ hiển thị
	init(); //khởi tạo 1 số chế độ đồ họa
	display();
	glutDisplayFunc(display); // thiết lập hàm vẽ là hàm display()
	glutMainLoop();  // bắt đầu chu trình lặp thể hiện vẽ
	return 0;
	// 
}


