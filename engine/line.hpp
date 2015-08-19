#ifndef __LINE_H__
#define __LINE_H__

#include "position.hpp"

#include <vector>
class Line;
typedef std::vector<Line>::iterator LineRef;

#include "road.hpp"

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
	double intersect(Line l);
private:


	Position start;
	Position dest;

	double angle;
	double lenth;

	double stDist;
	double dsDist;


	Position carPlace[2];

	// line start, dest, arrow parts
	Position arrow[4];
	RoadRef left;
	RoadRef strait;
	RoadRef right;

	bool edgeLine;
};

#endif