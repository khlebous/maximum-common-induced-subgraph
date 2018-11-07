#include <iostream>

#include "GraphSolver.h"

using namespace std;


GraphSolver::~GraphSolver()
{
}

Graph* GraphSolver::getMaxSubGraph()
{
	size_t vertCount = Xmax.size();
	bool** edges = new bool*[vertCount - 1];

	for (size_t i = 1; i < vertCount; i++)
	{
		edges[i - 1] = new bool[i];

		for (size_t j = 0; j < i; j++)
			edges[i - 1][j] = _G->edge(Xmax[i], Ymax[j]);
	}

	return new Graph(vertCount, edges);
}

bool GraphSolver::checkAdjecencyMatrices(int y)
{
	int n = X.size();
	int x = X[n - 1]; //last added x; |X| = |Y| + 1

	for (size_t i = 0; i < n - 1; i++)
	{
		if (_G->edge(X[i], x) != _H->edge(Y[i], y))
			return false;
	}

	return true;
}

bool GraphSolver::checkConnectivity(int x)
{
	for (auto& v : X)
	{
		if (_G->edge(v, x))
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

bool GraphSolver::contains(vector<int> v, int el) {
	return find(v.begin(), v.end(), el) != v.end();
}

void GraphSolver::init()
{
	//just to be sure or to relauch solving
	X.clear();
	Y.clear();
	Xmax.clear();
	Ymax.clear();
}

Graph* GraphSolver::solve()
{
	init();

	int n = _G->verticesCount();
	for (size_t i = 0; i < n; i++)
	{
		X.push_back(i);
		printSequences();
		solveXNode();
		X.pop_back();
	}

	Graph* result = getMaxSubGraph();

	return result;
}

void GraphSolver::solveRYNode() {

	int n = _G->verticesCount();
	for (size_t i = 0; i < n; i++)
	{
		if (contains(X, i))
			continue;

		if (checkConnectivity(i)) {
			X.push_back(i);
			printSequences();
			solveXNode();
			X.pop_back();
		}
	}
}

void GraphSolver::solveXNode() {

	int n = _H->verticesCount();
	for (size_t i = 0; i < n; i++)
	{
		if (contains(Y, i))
			continue;

		if (checkAdjecencyMatrices(i)) {
			Y.push_back(i);
			printSequences();
			updateMaxSequences(); // where should it be?
			solveRYNode();
			Y.pop_back();
		}
	}
}

void GraphSolver::printSequences()
{
	cout << "X=(";
	for (auto& v : X)
	{
		cout << v;
		if (v != X.back())
			cout << " , ";
	}
	cout << ")" << endl;

	cout << "Y=(";
	for (auto& v : Y)
	{
		cout << v;
		if (v != Y.back())
			cout << " , ";
	}
	cout << ")" << endl << endl;
}





