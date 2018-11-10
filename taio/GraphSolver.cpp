#include <iostream>

#include "GraphSolver.h"

using namespace std;


GraphSolver::~GraphSolver()
{
}

Graph* GraphSolver::solve(vector<int>* g, vector<int>* h)
{
	init();

	int n = _G->verticesCount();
	for (size_t i = 0; i < n; i++)
	{
		X.push_back(i);
		solveXNode();
		X.pop_back();
	}

	sortMaxSequences();
	g->assign(Xmax.begin(), Xmax.end());
	h->assign(Ymax.begin(), Ymax.end());
	Graph* result = getMaxSubGraph();

	return result;
}

void GraphSolver::solveXNode() {

	int n = _H->verticesCount();
	for (size_t i = 0; i < n; i++)
	{
		if (contains(Y, i))
			continue;

		if (checkAdjecencyMatrices(i)) {
			Y.push_back(i);
			updateMaxSequences(); // where should it be?
			solveYNode();
			Y.pop_back();
		}
	}
}

void GraphSolver::solveYNode() {

	int n = _G->verticesCount();
	for (size_t i = 0; i < n; i++)
	{
		if (contains(X, i))
			continue;

		if (checkConnectivity(i)) {
			X.push_back(i);
			solveXNode();
			X.pop_back();
		}
	}
}

Graph * GraphSolver::approxSolve(vector<int>* g, vector<int>* h)
{
	init();
	int n = _G->verticesCount();
	int m = _H->verticesCount();

	for (size_t i = 0; i < n; i++)
	{
		X.push_back(i);
		for (size_t j = 0; j < m; j++)
		{
			Y.push_back(j);
			updateMaxSequences();
			approxSolveXNode();

			Y.pop_back();
		}
		X.pop_back();
	}

	sortMaxSequences();
	g->assign(Xmax.begin(), Xmax.end());
	h->assign(Ymax.begin(), Ymax.end());
	Graph* result = getMaxSubGraph();

	return result;
}

void GraphSolver::approxSolveXNode()
{
	int n = _G->verticesCount();
	bool foundAndSearched = false;

	for (size_t i = 0; i < n; i++)
	{
		if (contains(X, i))
			continue;

		if (checkConnectivity(i)) {
			X.push_back(i);
			foundAndSearched = approxSolveYNode();
			X.pop_back();

			if (foundAndSearched)
				break;
		}
	}
}

bool GraphSolver::approxSolveYNode()
{
	int m = _H->verticesCount();

	for (size_t i = 0; i < m; i++)
	{
		if (contains(Y, i))
			continue;

		if (checkAdjecencyMatrices(i)) {
			Y.push_back(i);
			updateMaxSequences(); // where should it be?
			approxSolveXNode();
			Y.pop_back();
			return true;
		}
	}

	return false;
}

void GraphSolver::init()
{
	//just to be sure or to relauch solving
	X.clear();
	Y.clear();
	Xmax.clear();
	Ymax.clear();
}

void GraphSolver::updateMaxSequences()
{
	if (X.size() > Xmax.size())
	{
		Xmax = X;
		Ymax = Y;
	}
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

bool GraphSolver::contains(vector<int> v, int el) {
	return find(v.begin(), v.end(), el) != v.end();
}

Graph* GraphSolver::getMaxSubGraph()
{
	size_t vertCount = Xmax.size();
	bool** edges = new bool*[vertCount - 1];

	for (size_t i = 1; i < vertCount; i++)
	{
		edges[i - 1] = new bool[i];

		for (size_t j = 0; j < i; j++)
			edges[i - 1][j] = _G->edge(Xmax[i], Ymax[i]);
	}

	return new Graph(vertCount, edges);
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

void GraphSolver::sortMaxSequences()
{
	int n = Xmax.size();
	int m = Ymax.size();
	int tmp;

	for (size_t i = 0; i < n - 1; i++)
	{
		for (size_t j = 0; j < m - i - 1; j++)
		{
			if (Xmax[j] > Xmax[j+1])
			{
				tmp = Xmax[j];
				Xmax[j] = Xmax[j + 1];
				Xmax[j + 1] = tmp;

				tmp = Ymax[j];
				Ymax[j] = Ymax[j + 1];
				Ymax[j + 1] = tmp;
			}
		}
	}

}






