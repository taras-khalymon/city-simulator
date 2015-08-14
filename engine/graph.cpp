#include <iostream>
#include "graph.hpp"

Graph::Graph()
{}

Graph::~Graph()
{}

bool Graph::load(const char* filename)
{
	std::ifstream input;
	input.open(filename, std::ios::out);
	if (!input)
	{
		openMapEditor();
	}
	int nodeNum;
	int roadNum;
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
	input >> roadNum;
	int roadStart;
	int roadDest;
	int roadLines;
	for (int i = 0; i < roadNum; ++i)
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
		road.push_back(Road(node.begin() + roadStart - 1, node.begin() + roadDest - 1, roadLines));
	}
	
	for (std::vector<Road>::iterator i = road.begin(); i != road.end(); ++i)
	{
		i->s()->addRoad(i);
	}
	node.at(roadStart - 1).addRoad(road.end() - 1);
	for (std::vector<Road>::iterator i = road.begin(); i != road.end(); ++i)
	{
		for (std::vector<Road>::iterator j = road.begin(); j != road.end(); ++j)
		{
			if (i->isBackRoad(j))
			{
				i->initBackRoad(j);
			}
		}
	}
	for (std::vector<Road>::iterator i = road.begin(); i != road.end(); ++i)
	{
		i->initLines();
	}

	car.push_back(Car(road.begin(), 1, 0));
	std::cerr << "\n" << node[2].roads()[0]->lines()[0].len() << "\n";
	return true;
}

void Graph::generate()
{}

void Graph::render()
{
	// for (std::vector<Node>::iterator i = node.begin(); i != node.end(); ++i)
	// {
	// 	i->render();
	// }

	for (std::vector<Road>::iterator i = road.begin(); i != road.end(); ++i)
	{
		i->render();
	}
	for (std::vector<Car>::iterator i = car.begin(); i != car.end(); ++i)
	{
		i->render();
	}
}

void Graph::advance()
{
	for (std::vector<Car>::iterator i = car.begin(); i < car.end(); ++i)
	{
		if (i->advance())
		{
			car.erase(i);
			i--;	
		}
	}
}

void Graph::openMapEditor()
{}