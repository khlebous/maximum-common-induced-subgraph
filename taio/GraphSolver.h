#pragma once
#pragma once

#include "Graph.h"
#include <vector>
using namespace std;

class GraphSolver
{
private:
	Graph getSubMaxGraph();
	bool checkAdjecencyMatrices(int x, int y);
	bool checkConnectivity(int x);
	void updateMaxSequences();
	void init();

	Graph _G;
	Graph _H;
	vector<int> X;
	vector<int> Y;
	vector<int> Xmax;
	vector<int> Ymax; // it appears to be useless

public:
	GraphSolver(Graph G, Graph H)
		: _G(G), _H(H){}
	~GraphSolver();

	Graph Solve();
};

