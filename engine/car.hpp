#ifndef __CAR_HPP__
#define __CAR_HPP__

#include "road.hpp"

class CarPos
{
public:
	CarPos(const RoadRef r, const int l, const double d);
	~CarPos();

	RoadRef road;
	int line;
	double dist;
};

class Car
{
public:
	Car(const RoadRef r, const int l, const double d);
	~Car();

	void render();
	bool advance();

private:

	CarPos pos;
	// just a reference
	// const Line& l = pos.road->lines()[pos.line];
};

#endif