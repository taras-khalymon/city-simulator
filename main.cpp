#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include "engine/graph.h"

Graph graph;

void initGLUT(int argc, char** argv);
void display();
void timer(int);
void mousePressed(int button, int state, int x, int y);
void mouseMove(int x, int y);
void mousePressedMove(int x, int y);
void keyboard(unsigned char key, int x, int y);
void specialKeyboard(int key, int x, int y);

int main(int argc, char *argv[])
{
	initGLUT(argc, argv);
	graph.load("graph.txt");
	glutMainLoop();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	graph.render();
	glutSwapBuffers();
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(20, timer, 0);
}

void mousePressed(int button, int state, int x, int y)
{

}

void mouseMove(int x, int y)
{

}

void mousePressedMove(int x, int y)
{

}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 27:
		glutDestroyWindow(1);
		exit(0);
		break;
	}
}

void specialKeyboard(int key, int x, int y)
{

}

void initGLUT(int argc, char** argv)
{
	glutInit(&argc, argv);
	int w = glutGet(GLUT_SCREEN_WIDTH);
	int h = glutGet(GLUT_SCREEN_HEIGHT);
	// int w = 800;
	// int h = 600;
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(150, 50);
	glutCreateWindow("city-simulator v0.1");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glLoadIdentity();
	glOrtho(0, w, h, 0, -2, 2);
	glMatrixMode(GL_MODELVIEW);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutTimerFunc(20, timer, 0);
	glutDisplayFunc(display);
	glutMouseFunc(mousePressed);
	glutPassiveMotionFunc(mouseMove);
	glutMotionFunc(mousePressedMove);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);

	// glutFullScreen();
}