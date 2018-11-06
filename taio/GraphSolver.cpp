#include "GraphSolver.h"

using namespace std;



GraphSolver::~GraphSolver()
{
}

Graph GraphSolver::getSubMaxGraph()
{
	size_t vertCount = Xmax.size();
	bool** edges = new bool*[vertCount - 1];

	for (size_t i = 1; i < vertCount; i++)
	{
		edges[i - 1] = new bool[i];

		for (size_t j = 0; j < i; j++)
			edges[i - 1][j] = _G.edge(Xmax[i], Xmax[j]);
	}

	return Graph(vertCount, edges);
}

bool GraphSolver::checkAdjecencyMatrices(int x, int y)
{
	for (size_t i = 0; i < X.size(); i++)
	{
		if (_G.edge(X[i], x) != _G.edge(Y[i], y))
			return false;
	}

	return true;
}

bool GraphSolver::checkConnectivity(int x)
{
	for (auto& v : X)
	{
		if (_G.edge(v, x))
			return true;
	}

	return false;
}

void GraphSolver::updateMaxSequences()
{
	if (X.size() > Xmax.size())
	{
		//surprisingly it is a deep copy
		Xmax = X;
		Ymax = Y;
	}
}

void GraphSolver::init()
{
	//just to be sure or to relauch solving
	X.clear();
	Y.clear();
	Xmax.clear();
	Ymax.clear();
}

Graph GraphSolver::Solve()
{
	init();

	X.push_back(2);
	X.push_back(3);

	Graph result = getSubMaxGraph();

	return result;
}





