#include "Graph.h"
#include <iostream>
using namespace std;

Graph::~Graph()
{
	for (size_t i = 0; i < vertCount - 1; i++)
		delete[] edges[i];

	delete[] edges;
}

bool Graph::edge(size_t i, size_t j)
{
	if (i >= vertCount || j >= vertCount)
		throw invalid_argument("invalid edge index");

	if (i == j)
		return false;

	return i < j ? edges[j - 1][i] : edges[i - 1][j];
}

void Graph::setEdge(size_t i, size_t j, bool value)
{
	if (i >= vertCount || j >= vertCount || i == j)
		throw invalid_argument("invalid edge index");

	if (i < j)
		swap(i, j);

	edges[i - 1][j] = value;
}

void Graph::print()
{
	cout << "Vertices count: " << vertCount << endl;
	cout << "Adjecency matrix: " << endl;
	for (size_t i = 0; i < vertCount; i++)
	{
		for (size_t j = 0; j < vertCount; j++)
			cout << edge(i, j) << ' ';
		cout << endl;
	}
}

void Graph::printEdges()
{
	cout << "Vertices count: " << vertCount << endl;
	cout << "Edges representation: " << endl;
	for (size_t i = 0; i < vertCount - 1; i++)
	{
		for (size_t j = 0; j <= i; j++)
			cout << edges[i][j] << ' ';
		cout << endl;
	}
}
