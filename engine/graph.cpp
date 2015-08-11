#include <iostream>
#include "graph.h"

Graph::Graph()
{

}

Graph::~Graph()
{

}

bool Graph::load(const char* filename)
{
	std::ifstream input;
	input.open(filename, std::ios::out);
	if (!input)
	{
		openMapEditor();
	}
	int nodeNum;
	int edgeNum;
	int tmp;
	input >> nodeNum;
	for (int i = 0; i < nodeNum; ++i)
	{
		if (input.eof()) return false;
		Position nodePos;
		input >> tmp;
		nodePos.x(tmp);
		if (input.eof()) return false;
		input >> tmp;
		nodePos.y(tmp);
		node.push_back(nodePos);
	}
	input >> edgeNum;
	int roadStart;
	int roadDest;
	int roadLines;
	for (int i = 0; i < edgeNum; ++i)
	{
		if (input.eof()) return false;
		input >> roadStart;
		if (roadStart > nodeNum) return false;
		if (input.eof()) return false;
		input >> roadDest;
		if (roadDest > nodeNum) return false;
		if (input.eof()) return false;
		input >> roadLines;
		if (roadLines < 1) return false;
		edge.push_back(Edge(node.begin() + roadStart - 1, node.begin() + roadDest - 1, roadLines));
	}
	return true;
}

void Graph::generate()
{

}

void Graph::render()
{
	for (std::vector<Node>::iterator i = node.begin(); i != node.end(); ++i)
	{
		i->render();
	}
	for (std::vector<Edge>::iterator i = edge.begin(); i != edge.end(); ++i)
	{
		i->render();
	}
}

void Graph::openMapEditor()
{

}