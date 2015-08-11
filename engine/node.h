#ifndef __NODE_H__
#define __NODE_H__

#include <vector>
#include "position.h"

class Node;
class Edge;

typedef std::vector<Node>::iterator NodeRef;

#include "edge.h"

class Node
{
public:
	Node();
	Node(Position);
	~Node();

	void addRoad(NodeRef dest, int lines);

	void render();

	Position pos();

private:
	Position nodePos;
	double posvec[2];
};

#endif