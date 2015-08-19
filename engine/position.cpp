#include "position.hpp"

const double PI = acos(- 1);

Position::Position() : c {0, 0}
{}

Position::Position(const double& x, const double& y) : c {x, y}
{}

Position::~Position()
{}

const double& Position::x() const
{
	return c[0];
}

const double& Position::y() const
{
	return c[1];
}

void Position::x(const double& x)
{
	c[0] = x;
}

void Position::y(const double& y)
{
	c[1] = y;
}

double Position::distance() const
{
	return sqrt(c[0] * c[0] + c[1] * c[1]);
}

double Position::distance(const Position& other) const
{
	return sqrt((c[0] - other.c[0]) * (c[0] - other.c[0]) + (c[1] - other.c[1]) * (c[1] - other.c[1]));
}

double Position::angle() const
{
	if (c[1] > 0)
		return acos(c[0] / distance());
	else
		return 2 * PI - acos(c[0] / distance());
}

double Position::angle(const Position& other) const
{
	if (c[1] - other.c[1] > 0)
		return acos((c[0] - other.c[0]) / distance(other));
	else
		return 2 * PI - acos((c[0] - other.c[0]) / distance(other));
}

const double* Position::v() const
{
	return c;
}

const bool Position::operator == (const Position& other) const
{
	if (c[0] == other.c[0] && c[1] == other.c[1]) return true;
	return false;
}

const Position Position::operator - (const Position& other) const
{
	return Position (this->c[0] - other.c[0], this->c[1] - other.c[1]);
}