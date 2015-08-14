#ifndef __EDGE_HPP__
#define __EDGE_HPP__

#include <vector>

class Node;
class Road;

typedef std::vector<Road>::iterator RoadRef;

#include "node.hpp"
#include "line.hpp"

class Road
{
public:
	Road(NodeRef start, NodeRef dest, int lines);
	~Road();

	const std::vector<Line> lines() const;

	void render();

	bool isBackRoad(RoadRef road);
	void initBackRoad(RoadRef road);
	void initLines();

	const NodeRef& s() const;
	const NodeRef& d() const;

private:
	NodeRef start;
	NodeRef dest;
	std::vector<Line> line;
	Position midLineStart;
	Position midLineDest;
	int backLines;
	static double w;
};

#endif