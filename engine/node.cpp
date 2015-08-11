#include <GL/glut.h>
#include "node.h"

Node::Node()
{

}

Node::Node(Position pos)
{
	nodePos = pos;
	
}

Node::~Node()
{
	
}

void Node::addRoad(NodeRef, int lines)
{

}

Position Node::pos()
{
	return nodePos;
}

void Node::render()
{
	static const double PI = acos(-1);
	glBegin(GL_LINE_LOOP);
	for (double i = 0; i < 2 * PI; i += PI / 10)
	{
		glVertex2d(nodePos.x() + cos(i) * 15, nodePos.y() + sin(i) * 15);
	}
	glEnd();
}