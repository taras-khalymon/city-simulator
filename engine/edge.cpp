#include <GL/glut.h>
#include "edge.h"

int Edge::w = 30;

Edge::Edge()
{
	backLines = 0;
}

Edge::Edge(NodeRef from, NodeRef to, int lineNum)
{
	start = from;
	dest = to;
	lines = lineNum;
	backLines = 0;
}

Edge::~Edge()
{
	
}

void Edge::render()
{
	static const double PI = acos(-1);
	double angle = start->pos().angle(dest->pos()) - PI / 2;
	int cor = 0; // correction from back lines
	if (backLines == 0)
	{
		cor = -1;
	}

	glColor3d(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2d(start->pos().x() - cos(angle + PI / 2) * w + cos(angle) * w * cor, start->pos().y() - sin(angle + PI / 2) * w + sin(angle) * w * cor);
	glVertex2d(dest->pos().x() + cos(angle + PI / 2) * w + cos(angle) * w * cor, dest->pos().y() + sin(angle + PI / 2) * w + sin(angle) * w * cor);
	glEnd();

	for (int i = 1; i <= lines; ++i)
	{
		glColor3d(0, 0, 0);
		glLineWidth(3);
		glBegin(GL_LINES);
		glVertex2d(start->pos().x() + cos(angle) * w * (i + cor) - cos(angle + PI / 2) * w, start->pos().y() + sin(angle) * w * (i + cor) - sin(angle + PI / 2) * w);
		glVertex2d(dest->pos().x() + cos(angle) * w * (i + cor) + cos(angle + PI / 2) * w, dest->pos().y() + sin(angle) * w * (i + cor) + sin(angle + PI / 2) * w);
		glEnd();

		glColor3d(0.5, 0.5, 0.5);
		glLineWidth(1);
		glBegin(GL_LINES);
		glVertex2d(start->pos().x() * 0.6 + dest->pos().x() * 0.4 + cos(angle) * w * ((i + cor) - 0.5), start->pos().y() * 0.6 + dest->pos().y() * 0.4 + sin(angle) * w * ((i + cor) - 0.5));
		glVertex2d(start->pos().x() * 0.4 + dest->pos().x() * 0.6 + cos(angle) * w * ((i + cor) - 0.5), start->pos().y() * 0.4 + dest->pos().y() * 0.6 + sin(angle) * w * ((i + cor) - 0.5));
		
		glVertex2d(start->pos().x() * 0.4 + dest->pos().x() * 0.6 + cos(angle) * w * ((i + cor) - 0.5), start->pos().y() * 0.4 + dest->pos().y() * 0.6 + sin(angle) * w * ((i + cor) - 0.5));
		glVertex2d(start->pos().x() * 0.4 + dest->pos().x() * 0.6 + cos(angle) * w * ((i + cor) - 0.5) + w / 3 * cos(angle + PI / 4), start->pos().y() * 0.4 + dest->pos().y() * 0.6 + sin(angle) * w * ((i + cor) - 0.5) + w / 3 * sin(angle + PI / 4));

		glVertex2d(start->pos().x() * 0.4 + dest->pos().x() * 0.6 + cos(angle) * w * ((i + cor) - 0.5), start->pos().y() * 0.4 + dest->pos().y() * 0.6 + sin(angle) * w * ((i + cor) - 0.5));
		glVertex2d(start->pos().x() * 0.4 + dest->pos().x() * 0.6 + cos(angle) * w * ((i + cor) - 0.5) + w / 3 * cos(angle + 3 * PI / 4), start->pos().y() * 0.4 + dest->pos().y() * 0.6 + sin(angle) * w * ((i + cor) - 0.5) + w / 3 * sin(angle + 3 * PI / 4));
		glEnd();
	}
}

bool Edge::isBackRoad(EdgeRef edge)
{
	if (*this->start == *edge->dest && *edge->start == *this->dest)
	{
		return true;
	}
	return false;
}

void Edge::initBackRoad(EdgeRef edge)
{
	this->backLines = edge->lines;
}