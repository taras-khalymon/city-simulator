#include <GL/glut.h>

#include "line.hpp"

Line::Line()
{}

Line::~Line()
{}

void Line::init(const Position& start, const Position& dest, int num, double w, int lines, int backLines)
{
	double cor = (double)(lines - backLines) / 2;
	static const double PI = acos(-1);
	angle = start.angle(dest) - PI / 2;
	Position a;
	
	this->start.x(start.x() - cos(angle + PI / 2) * w + cos(angle) * w * (num - cor));
	this->start.y(start.y() - sin(angle + PI / 2) * w + sin(angle) * w * (num - cor));

	this->dest.x(dest.x() + cos(angle + PI / 2) * w + cos(angle) * w * (num - cor));
	this->dest.y(dest.y() + sin(angle + PI / 2) * w + sin(angle) * w * (num - cor));

	carPlace[0] = Position(this->start.x() - cos(angle) * w / 2, this->start.y() - sin(angle) * w / 2);
	carPlace[1] = Position(this->dest.x() - cos(angle) * w / 2, this->dest.y() - sin(angle) * w / 2);

	arrow[0].x(this->start.x() * 0.6 + this->dest.x() * 0.4 - cos(angle) * w / 2);
	arrow[0].y(this->start.y() * 0.6 + this->dest.y() * 0.4 - sin(angle) * w / 2);

	arrow[1].x(this->start.x() * 0.4 + this->dest.x() * 0.6 - cos(angle) * w / 2);
	arrow[1].y(this->start.y() * 0.4 + this->dest.y() * 0.6 - sin(angle) * w / 2);

	arrow[2].x(this->start.x() * 0.4 + this->dest.x() * 0.6 - cos(angle) * w / 2 + w / 3 * cos(angle + 1 * PI / 4));
	arrow[2].y(this->start.y() * 0.4 + this->dest.y() * 0.6 - sin(angle) * w / 2 + w / 3 * sin(angle + 1 * PI / 4));

	arrow[3].x(this->start.x() * 0.4 + this->dest.x() * 0.6 - cos(angle) * w / 2 + w / 3 * cos(angle + 3 * PI / 4));
	arrow[3].y(this->start.y() * 0.4 + this->dest.y() * 0.6 - sin(angle) * w / 2 + w / 3 * sin(angle + 3 * PI / 4));

	angle -= PI / 2;
	lenth = this->start.distance(this->dest);
}

const Position* Line::carPos() const
{
	return carPlace;
}

const double& Line::ang() const
{
	return angle;
}

const double& Line::len() const
{
	return lenth;
}

void Line::render()
{
	glBegin(GL_LINES);
	glVertex2d(start.x(), start.y());
	glVertex2d(dest.x(), dest.y());
	glEnd();
	glBegin(GL_LINES);
	glVertex2dv(arrow[0].v());
	glVertex2dv(arrow[1].v());

	glVertex2dv(arrow[1].v());
	glVertex2dv(arrow[2].v());
	
	glVertex2dv(arrow[1].v());
	glVertex2dv(arrow[3].v());
	glEnd();
}