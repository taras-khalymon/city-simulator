#ifndef __NODE_H__
#define __NODE_H__

#include <vector>
#include "position.hpp"

class Node;
class Edge;

typedef std::vector<Node>::iterator NodeRef;

#include "edge.hpp"

class Node
{
public:
	Node();
	Node(Position);
	~Node();

	void addRoad(NodeRef dest, int lines);

	void render();

	Position pos();

	bool operator == (const Node& n);

private:
	Position nodePos;
	double posvec[2];
	int id;

	static int curId;
};

#endif