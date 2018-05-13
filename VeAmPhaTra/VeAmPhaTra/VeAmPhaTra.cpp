#include "stdafx.h"
// Bai3.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <GL/glut.h>

void Reshape(int width, int heigth) { //Tạo chế độ chiéu
	glViewport(0, 0, width, heigth);
	glMatrixMode(GL_PROJECTION); //Tao ma trận
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);//Phép chiếu trực giao
}
void Init() { //thiết lập thuộc tính ban đầu của đối tượng
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
//Hàm chuyên để vẽ. Hàm quan trọng nhất. 
void RendenScene() {
	glutWireTeapot(2.0);
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

