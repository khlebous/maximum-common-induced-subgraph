#pragma once
#pragma once

#include "Graph.h"
#include <vector>
using namespace std;

class GraphSolver
{
private:
	Graph* getMaxSubGraph();
	bool checkAdjecencyMatrices(int y);
	bool checkConnectivity(int x);
	void updateMaxSequences();
	bool contains(vector<int> v, int el);
	void init();
	void solveRYNode();
	void solveXNode();
	void printSequences();

	Graph* _G;
	Graph* _H;
	vector<int> X;
	vector<int> Y;
	vector<int> Xmax;
	vector<int> Ymax;

public:
	GraphSolver(Graph* G, Graph* H)
		: _G(G), _H(H) {}
	~GraphSolver();

	Graph* solve();
};

