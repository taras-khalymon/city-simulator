#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>

#include "node.h"

enum graphInputType
{
	adjacencyMatrix,	// adjacency matrix
	edgeList,			// edge list
	incidenceMatrix		// incidence matrix
};

class Graph
{
public:
	Graph();
	~Graph();

	bool loadGraph(graphInputType type, const char* filename);
	void render();
	void openMapEditor();

private:
	std::vector<Node> node;
};

#endif