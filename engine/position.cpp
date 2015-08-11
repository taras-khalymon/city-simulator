#include "position.h"

const double PI = acos(- 1);

Position::Position()
{
	_x = 0;
	_y = 0;
}

Position::Position(const int& x, const int& y)
{
	_x = x;
	_y = y;
}

Position::~Position()
{

}

double Position::x()
{
	return _x;
}

double Position::y()
{
	return _y;
}

void Position::x(const double& x)
{
	_x = x;
}

void Position::y(const double& y)
{
	_y = y;
}

double Position::distance()
{
	return sqrt(_x * _x + _y * _y);
}

double Position::distance(const Position& other)
{
	return sqrt((_x - other._x) * (_x - other._x) + (_y - other._y) * (_y - other._y));
}

double Position::angle()
{
	if (_y > 0)
		return acos(_x / distance());
	else
		return 2 * PI - acos(_x / distance());
}

double Position::angle(const Position& other)
{
	if (_y - other._y > 0)
		return acos((_x - other._x) / distance(other));
	else
		return 2 * PI - acos((_x - other._x) / distance(other));
}

Position Position::operator - (const Position& other)
{
	return Position (this->_x - other._x, this->_y - other._y);
}