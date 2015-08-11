#include <GL/glut.h>
#include "edge.h"

Edge::Edge()
{

}

Edge::Edge(NodeRef from, NodeRef to, int lineNum)
{
	start = from;
	dest = to;
	lines = lineNum;
}

Edge::~Edge()
{
	
}

#include <iostream>
void Edge::render()
{
	static const double PI = acos(-1);
	double angle = start->pos().angle(dest->pos()) - PI / 2;
	glBegin(GL_LINES);
	glVertex2d(start->pos().x(), start->pos().y());
	glVertex2d(dest->pos().x(), dest->pos().y());
	
	glVertex2d(start->pos().x() + cos(angle) * 15, start->pos().y() + sin(angle) * 15);
	glVertex2d(dest->pos().x() + cos(angle) * 15, dest->pos().y() + sin(angle) * 15);
	glEnd();
}