#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <vector>
#include "position.hpp"

class Node;
class Road;

typedef std::vector<Node>::iterator NodeRef;

#include "road.hpp"

class Node
{
public:
	Node(Position);
	~Node();

	void addRoad(RoadRef road);
	
	const std::vector<RoadRef>& roads() const;

	void render();

	Position pos();

	bool operator == (const Node& n);

private:
	Position nodePos;

	std::vector<RoadRef> road;

	double posvec[2];
	int id;

	static int curId;
};

#endif