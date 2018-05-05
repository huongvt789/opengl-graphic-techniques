// Bai3.cpp : Defines the entry point for the console application.
//

//#include "DrawPlay.h"

#include <stdlib.h>
#include <GL/glut.h>
#include "stdafx.h"

//#include "DrawPlay"

GLfloat b_box;
//THIẾT LẬP PHÉP CHIẾU.
void Reshape(int width, int heigth) { //Tạo chế độ chiéu
	glViewport(0, 0, width, heigth); //Vùng để mô phỏng đồ họa OpenGL.
	glMatrixMode(GL_PROJECTION); //Tao ma trận. Sử dụng đồ họa.
	glLoadIdentity(); //Reset lại hệ tọa độ.
	float ratin = (float)width / (float)heigth;
	gluPerspective(45.0, ratin, 1.0, 100.0); //phép chiếu phối cảnh.
   //glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);//Phép chiếu trực giao

	glMatrixMode(GL_MODELVIEW); //Thiết lập view.
}

GLuint MakeCube()
{
	GLuint boxDisplay;
	boxDisplay = glGenLists(1);         // Bắt đầ thực hiện Display List
	glNewList(boxDisplay, GL_COMPILE);

	glBegin(GL_QUADS);                 // Render Đối tượng trong vùng Display List
	glNormal3f(0.0, 0.0, 1.0f);								   // Front Face
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	// Back Face
	glNormal3f(0.0, 0.0, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Top Face
	glNormal3f(0.0, -1.0, 0.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	// Bottom Face
	glNormal3f(1.0, 0.0, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	// Right face
	glNormal3f(1.0, 0.0, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	// Left Face
	glNormal3f(-1.0, 0.0, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glEndList(); // Kết thúc quá trình Dislay list
	return boxDisplay;
}
//KHỞI TẠO THUỘC TÍNH.
void Init() { //thiết lập thuộc tính ban đầu của đối tượng
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST); //Thiết lập chế độ nhìn chiều sâu.
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); //Chọn nguồn sáng.
						 //Chọn ví trí chiếu sáng.
	GLfloat light_pos[] = { 0.0, 0.0 ,1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	//Thay đổi màu của vật, pha trộn. (màu hồng).

	GLfloat ambient[] = { 1.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	b_box = MakeCube();
}
//VẼ TỌA ĐỘ ĐOẠN THẲNG 2 CHIỀU.
void DrawToado2chieu() {
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();

}

//Hàm chuyên để vẽ. Hàm quan trọng nhất. 
void RendenScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Xoa bo dem đưa về trang thái ban đầu.
	glLoadIdentity();

	gluLookAt(5.0, 5.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //đi kèm phép chiếu phối cảnh

	glPushMatrix();
	DrawToado2chieu();
	glCallList(b_box);
	glPopMatrix();
	glFlush();

}
int main(int argc, char **argv)
{
	//Tạo cửa sổ window chạy opengl.
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	Init();
	glutReshapeFunc(Reshape);
	glutDisplayFunc(RendenScene);
	glutMainLoop();
	return 0;
}

