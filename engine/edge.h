#ifndef __EDGE_H__
#define __EDGE_H__

#include <vector>

class Node;
class Edge;

typedef std::vector<Edge>::iterator EdgeRef;

#include "node.h"

class Edge
{
public:
	Edge();
	Edge(NodeRef start, NodeRef dest, int lines);
	~Edge();

	void render();

	bool isBackRoad(EdgeRef edge);
	void initBackRoad(EdgeRef edge);

private:
	NodeRef start;
	NodeRef dest;
	int lines;
	int backLines;

	static int w;
};

#endif