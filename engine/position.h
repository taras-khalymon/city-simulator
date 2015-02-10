#ifndef __DECART_H__
#define __DECART_H__

#include <math.h>

class Position
{
public:
	Position();
	Position(const int& x, const int& y);
	~Position();

	double x();
	double y();
	
	void x(const double& x);
	void y(const double& y);

	double distance();
	double distance(const Position& other);

	double angle();
	double angle(const Position& other);

private:
	double _x;
	double _y;
};

#endif
