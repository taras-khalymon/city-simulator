#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <fstream>
#include "node.hpp"

class Graph
{
public:
	Graph();
	~Graph();

	bool load(const char* filename);
	void generate();
	void render();
	void openMapEditor();

private:
	std::vector<Node> node;
	std::vector<Edge> edge;
};

#endif