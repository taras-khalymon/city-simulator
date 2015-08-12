#include <GL/glut.h>
#include "node.hpp"

int Node::curId = 0;

Node::Node()
{
	curId++;
	id = curId;
}

Node::Node(Position pos)
{
	nodePos = pos;
	curId++;
	id = curId;
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

bool Node::operator == (const Node& n)
{
	return id == n.id ? true : false;
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