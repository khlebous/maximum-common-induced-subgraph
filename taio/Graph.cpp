#include "Graph.h"
#include <iostream>
using namespace std;

Graph::~Graph()
{
	for (size_t i = 0; i < vertCount - 1; i++)
		delete[] edges[i];

	delete[] edges;
}

bool Graph::edge(int i, int j)
{
	if (i == j || i >= vertCount || j >= vertCount || i < 0 || j < 0)
		return false;

	return i < j ? edges[j - 1][i] : edges[i - 1][j];
}

void Graph::print()
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
