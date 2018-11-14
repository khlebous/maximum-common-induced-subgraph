#pragma once

#include <random>
#include <iostream>

#include "Graph.h"

using namespace std;

class GraphGenerator
{
private:

	mt19937 _mt;
	uniform_real_distribution<double> _dist;
	double _sparseGraphDensity = 0.8;
	double _normalGraphDensity = 0.5;
	double _tightGraphDensity = 0.2;

	double random();
	double chanceEdgeTree(size_t treeSize, double density);
	Graph* genEmptyGraph(size_t graphSize);
	Graph* genGraph(size_t size, double density);

public:
	GraphGenerator(unsigned int seed);
	~GraphGenerator();

	Graph* genGraph(size_t size);
	Graph* genTree(size_t size);
	Graph* genSparseGraph(size_t size);
	Graph* genTightGraph(size_t size);
	Graph* genCompleteGraph(size_t size);

};

