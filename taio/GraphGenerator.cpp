#include "GraphGenerator.h"

#include <vector>
#include <algorithm>    

using namespace std;


GraphGenerator::GraphGenerator(unsigned int seed)
{
	_mt = mt19937(seed);
	_dist = uniform_real_distribution<double>(0.0, 1.0);
}

GraphGenerator::~GraphGenerator()
{
}

double GraphGenerator::chanceEdgeTree(size_t treeSize, double density)
{
	size_t currEdges = treeSize - 1;
	size_t allEdges = treeSize * (treeSize - 1);

	double chance = (density*allEdges - currEdges) / allEdges;

	return chance;
}

Graph * GraphGenerator::genEmptyGraph(size_t graphSize)
{
	bool** edges = new bool*[graphSize - 1];

	for (size_t i = 1; i < graphSize; i++)
	{
		edges[i - 1] = new bool[i];

		for (size_t j = 0; j < i; j++)
			edges[i - 1][j] = false;
	}

	Graph* empty = new Graph(graphSize, edges);

	return empty;
}


Graph * GraphGenerator::genGraph(size_t size)
{
	return genGraph(size, _normalGraphDensity);
}

Graph * GraphGenerator::genTree(size_t size)
{
	Graph* g = genEmptyGraph(size);

	auto randomInt = [&](int max) { return (int)(_dist(_mt) * max); };

	vector<size_t> added;
	vector<size_t> toAdd;
	for (size_t i = 0; i < size; i++)
	{
		toAdd.push_back(i);
	}
	random_shuffle(toAdd.begin(), toAdd.end(), randomInt);

	added.push_back(toAdd.back());
	toAdd.pop_back();

	for (auto& v : toAdd)
	{
		random_shuffle(added.begin(), added.end(), randomInt);
		size_t w = added.back();
		g->setEdge(w, v, true);
		added.push_back(v);
	}

	return g;
}

Graph * GraphGenerator::genSparseGraph(size_t size)
{
	return genGraph(size, _sparseGraphDensity);
}

Graph * GraphGenerator::genTightGraph(size_t size)
{
	return genGraph(size, _tightGraphDensity);
}

Graph * GraphGenerator::genCompleteGraph(size_t size)
{
	Graph* g = genEmptyGraph(size);

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			g->setEdge(i, j, true);
		}
	}

	return g;
}

double GraphGenerator::random()
{
	return _dist(_mt);
}

Graph * GraphGenerator::genGraph(size_t size, double density)
{
	double chance = chanceEdgeTree(size, density);
	Graph* g = genTree(size);

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (!g->edge(i, j) && random() < chance)
				g->setEdge(i, j, true);
		}
	}

	return g;
}
