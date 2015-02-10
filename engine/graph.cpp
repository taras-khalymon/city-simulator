#include <iostream>
#include <fstream>
#include "graph.h"

Graph::Graph()
{

}

Graph::~Graph()
{

}

bool Graph::loadGraph(graphInputType type, const char* filename)
{
	std::ifstream input;
	input.open(filename, std::ios::out);
	if (!input)
	{
		openMapEditor();
	}

	switch (type)
	{
	case adjacencyMatrix:
		return false;
		break;
	case edgeList:
		// int tmp;

		return false;
		break;
	case incidenceMatrix:
		return false;
		break;
	}
}

void Graph::render()
{

}

