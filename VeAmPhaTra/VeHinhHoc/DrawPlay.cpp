#include "DrawPlay.h"



DrawPlay::DrawPlay(void)
{
}


DrawPlay::~DrawPlay(void)
{
}
GLuint DrawPlay::Display(const float& radio)
{
	GLint db_list;
	db_list = glGenLists(1);
	glNewList(db_list, GL_COMPILE);
	glutSolidSphere(radio, 64, 64);
	glEndList();
	return db_list;
}