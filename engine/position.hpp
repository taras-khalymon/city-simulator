#ifndef __DECART_HPP__
#define __DECART_HPP__

#include <math.h>

class Position
{
public:
	Position();
	Position(const double& x, const double& y);
	~Position();

	const double& x() const;
	const double& y() const;
	
	void x(const double& x);
	void y(const double& y);

	double distance() const;
	double distance(const Position& other) const;

	double angle() const;
	double angle(const Position& other) const;

	const double* v() const;

	const bool operator == (const Position&) const;

	const Position operator - (const Position&) const;

private:
	// coordinates
	double c[2];
};

#endif
