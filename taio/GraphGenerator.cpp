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

	bool* added = new bool[size];

	vector<size_t> verts1;
	for (size_t i = 0; i < size; i++)
	{
		verts1.push_back(i);
	}
	vector<size_t> verts2 = verts1;


	random_shuffle(verts1.begin(), verts1.end(), randomInt);
	for (auto& a : verts1)
	{
		random_shuffle(verts2.begin(), verts2.end(), randomInt);
		for (auto& b : verts2)
		{
			if (a != b && (!added[a] || ! added[b]))
			{
				added[a] = true;
				added[b] = true;
				g->setEdge(a, b, true);
				break;
			}
		}
	}

	delete added;

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
	Graph* g = genEmptyGraph(size);

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (random() < chance)
				g->setEdge(i, j, true);
		}
	}

	return g;
}
