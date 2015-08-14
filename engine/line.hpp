#ifndef __LINE_H__
#define __LINE_H__

#include "position.hpp"

class Line
{
public:
	Line();
	~Line();

	void init(const Position& start, const Position& dest, int num, double roadWidth, int lines, int backLines);
	const Position* carPos() const;
	const double& ang() const;
	const double& len() const;
	void render();
private:
	Position start;
	Position dest;

	double angle;
	double lenth;

	Position carPlace[2];

	// line start, dest, arrow parts
	Position arrow[4];
};

#endif