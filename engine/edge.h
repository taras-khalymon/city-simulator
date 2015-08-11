#ifndef __EDGE_H__
#define __EDGE_H__

#include <vector>

class Node;
class Edge;

#include "node.h"

class Edge
{
public:
	Edge();
	Edge(NodeRef start, NodeRef dest, int lines);
	~Edge();

	void render();

private:
	NodeRef start;
	NodeRef dest;
	int lines;
};

#endif