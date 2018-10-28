/*
 * Sergio Ruiz.
 *
 * TC3022. Computer Graphics Course.
 * Basic template OpenGL project.
 */

// Please don't change lines 9-22 (It helps me to grade)
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

#endif

Cube* base;


float up_down;
float axis;

void MenuHandler(char key) {
	switch (key)
	{
	case 'w':
		up_down -= 10;
		break;
	case 's':
		up_down += 10;
		break;
	case 'a':
		axis += 10;
		
		break;
	case 'd':
		axis -= 10;
		break;
	case 'i':
		
		break;
	case 'k':
		
		break;
	};
}
void keyPressed(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'w': MenuHandler('w'); break;
	case 's': MenuHandler('s'); break;
	case 'a': MenuHandler('a'); break;
	case 'd': MenuHandler('d'); break;
	case 'k': MenuHandler('i'); break;
	case 'i': MenuHandler('k'); break;
	case '1': MenuHandler('k'); break;
	case '2': MenuHandler('k'); break;
	case '3': MenuHandler('k'); break;
	};
}
void init() // FOR GLUT LOOP
{
	base = new Cube();
	axis = 0.0f;
	up_down = 0.0f;

	base->setColor(255, 255, 255);//blanco
	base->setScale(1.0f, 3.0f, 1.0f);
	base->setPosition(0, 0.0f, 0);
	base->setRotation(0, 0, 0);

	
	glutKeyboardFunc(keyPressed);
	glEnable(GL_DEPTH_TEST);			// Enable check for close and far objects.
	glClearColor(0.0, 0.0, 0.0, 0.0);	// Clear the color state.
	glMatrixMode(GL_MODELVIEW);			// Go to 3D mode.
	glLoadIdentity();					// Reset 3D view matrix.
}

void drawAxis() {
	glPushMatrix();
	// draw our axes
	glBegin(GL_LINES);
	// draw line for x axis
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	// draw line for y axis
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	// draw line for Z axis
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();
	// load the previous matrix
	glPopMatrix();
}

void display()							// Called for each frame (about 60 times per second).
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);				// Clear color and depth buffers.
	glLoadIdentity();												// Reset 3D view matrix.
	gluLookAt(0.0, 15.0,15.0,										// Where the camera is.
		      0.0, 2.0, 0.0,										// To where the camera points at.
		      0.0, 1.0, 0.0);										// "UP" vector.

	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutWireSphere(0.2, 50, 50);
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(0.0f, 2.0f, -1.0f);
		glPushMatrix();//Moves the axis of the thingy
			glRotatef(axis, 0, 1, 0);
			glPushMatrix();//moves up and down arm
			{
				glTranslatef(0.0f, -1.0f, 0.0f);
				glRotatef(up_down, 0, 0, 1);
				glTranslatef(0.0f, 1.0f, 0.0f);
				base->draw();
			}
			glPopMatrix();
		glPopMatrix();
	}
	glPopMatrix();
	
	drawAxis();

	glutSwapBuffers();												// Swap the hidden and visible buffers.
																	// save previous matrix
	
}

void idle()															// Called when drawing is finished.
{
	glutPostRedisplay();											// Display again.
}

void reshape(int h, int v)											// Called when the window geometry changes.
{
	glMatrixMode(GL_PROJECTION);									// Go to 2D mode.
	glLoadIdentity();												// Reset the 2D matrix.
	gluPerspective(40.0, (GLdouble)h / (GLdouble)v, 0.5, 50.0);		// Configure the camera lens aperture.
	glMatrixMode(GL_MODELVIEW);										// Go to 3D mode.
	glViewport(0, 0, h, v);											// Configure the camera frame dimensions.
	gluLookAt(0.0, 1.0, 4.0,
		      0.0, 0.0, 0.0,
		      0.0, 1.0, 0.0);
	display();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);											// Init GLUT with command line parameters.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);		// Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
	glutInitWindowSize(800, 600);
	glutCreateWindow("CG TEST");
	
	init();
	glutReshapeFunc(reshape);										// Reshape CALLBACK function.
	glutDisplayFunc(display);										// Display CALLBACK function.
	glutIdleFunc(idle);												// Idle CALLBACK function.
	glutMainLoop();													// Begin graphics program.
	return 0;														// ANSI C requires a return value.
}
