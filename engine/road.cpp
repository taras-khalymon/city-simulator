#include <GL/glut.h>
#include <iostream>
#include "road.hpp"

double Road::w = 30;

Road::Road(NodeRef s, NodeRef d, int lineNum) : start(s), dest(d), line(lineNum), backLines(0)
{}

Road::~Road()
{}

const std::vector<Line> Road::lines() const
{
	return line;
}

void Road::render()
{
	glColor3d(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2dv(midLineStart.v());
	glVertex2dv(midLineDest.v());
	glEnd();
	for (std::vector<Line>::iterator i = line.begin(); i < line.end(); ++i)
	{
		i->render();
	}

}

bool Road::isBackRoad(RoadRef road)
{
	if (*this->start == *road->dest && *road->start == *this->dest)
	{
		return true;
	}
	return false;
}

void Road::initBackRoad(RoadRef road)
{
	this->backLines = road->line.size();
}

void Road::initLines()
{
	static const double PI = acos(-1);
	double angle = start->pos().angle(dest->pos()) - PI / 2;

	double cor = (double)(line.size() - backLines) / 2;
	cor = 0;

	midLineStart.x(start->pos().x()/* - cos(angle + PI / 2) * w*/ - cos(angle) * w * cor);
	midLineStart.y(start->pos().y()/* - sin(angle + PI / 2) * w*/ - sin(angle) * w * cor);

	midLineDest.x(dest->pos().x()/* + cos(angle + PI / 2) * w*/ - cos(angle) * w * cor);
	midLineDest.y(dest->pos().y()/* + sin(angle + PI / 2) * w*/ - sin(angle) * w * cor);

	int num = 0;
	for (std::vector<Line>::iterator i = line.begin(); i != line.end(); ++i)
	{
		num++;
		i->init(start->pos(), dest->pos(), num, w, line.size(), backLines);
	}
}

void Road::initLLen()
{

	// RoadRef i = dest->roads().front();
	// for (std::vector<RoadRef>::iterator i = dest->roads().begin(); i < dest->roads().end(); ++i)
	{
		// std::cerr << i->midLineDest.x();
		// line.back().intersect((*i)->line.back());
		// std::cerr << "AAA ";
	}
}

const NodeRef& Road::s() const
{
	return start;
}

const NodeRef& Road::d() const
{
	return dest;
}