#include <GL/glut.h>

#include "car.hpp"

CarPos::CarPos(const RoadRef r, const int l, const double d) : road (r), line(l), dist(d)
{}

CarPos::~CarPos()
{}

Car::Car(const RoadRef r, const int l, const double d) : pos(r, l, d)
{}

Car::~Car()
{}

void Car::render()
{
	glBegin(GL_QUADS);
	// Position p = l.carPos()[0];
	// p.x(p.x() + cos(l.ang()) * pos.dist);
	// p.y(p.y() + sin(l.ang()) * pos.dist);
	Line l = pos.road->lines()[pos.line];
	Position p = l.carPos()[0];
	p.x(p.x() + cos(l.ang()) * pos.dist);
	p.y(p.y() + sin(l.ang()) * pos.dist);
	glVertex2dv((p - Position(10, 10)).v());
	glVertex2dv((p - Position(-10, 10)).v());
	glVertex2dv((p - Position(-10, -10)).v());
	glVertex2dv((p - Position(10, -10)).v());
	glEnd();
}

bool Car::advance()
{
	if (pos.road->d()->roads().size() > 0 || pos.road->lines()[pos.line].len() - pos.dist > 5)
	{
		pos.dist += 5;
		if (pos.dist > pos.road->lines()[pos.line].len())
		{
			int a = rand() % pos.road->d()->roads().size();
			// int a = 0;
			pos.dist = 0;
			pos.road = pos.road->d()->roads()[a];
			pos.line = rand() % pos.road->lines().size();
			// pos.road = pos.road->d()->roads();
		}
		return false;
	}
	else
	{
		return true;
	}
}