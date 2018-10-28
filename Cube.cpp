


#ifdef __APPLE__
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
// For VS only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
#include "glew.h"
#include "freeglut.h"
#include <stdio.h>
#include <math.h>
#include "../hCube.h"

float scale_x = 1;
float scale_y = 1;
float scale_z = 1;
float pos_x = 0;
float pos_y = 0;
float pos_z = 0;
float r = .1f;
float g = .1f;
float b = .1f;
Cube::Cube()
{
}
void Cube::setColor(float _r, float _g, float _b) {
	r = _r / 255.0f;
	g = _g / 255.0f;
	b = _b / 255.0f;
}
void Cube::setScale(float x, float y, float z) {
	scale_x = x;
	scale_y = y;
	scale_z = z;
}
void Cube::setPosition(float x, float y, float z) {
	pos_x = x;
	pos_y = y;
	pos_z = z;
}
void Cube::setRotation(float x, float y, float z) {
	rot_x = x;
	rot_y = y;
	rot_z = z;
}
void Cube::update() {

}
void Cube::draw() {
	glPushMatrix();
	{
		glColor3f(r, g, b);
		glTranslatef(pos_x, pos_y, pos_z);
		glScalef(scale_x, scale_y, scale_z);
		//glutWireCylinder(2,5,20,10);
		glutWireCube(2);
	}
	glPopMatrix();
}
#endif