#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <vector>
#include <fstream>
#include "node.hpp"
#include "car.hpp"

class Graph
{
public:
	Graph();
	~Graph();

	bool load(const char* filename);
	void generate();
	void render();
	void advance();
	void openMapEditor();
	void addCar();

private:
	std::vector<Node> node;
	std::vector<Road> road;
	std::vector<Car> car;
};

#endif