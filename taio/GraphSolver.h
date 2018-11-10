#pragma once
#pragma once

#include "Graph.h"
#include <vector>
using namespace std;

class GraphSolver
{
private:
	Graph* _G;
	Graph* _H;
	vector<int> X;
	vector<int> Y;
	vector<int> Xmax;
	vector<int> Ymax;

	void init();
	void solveYNode();
	void solveXNode();
	void approxSolveXNode();
	bool approxSolveYNode();
	void updateMaxSequences();
	bool checkAdjecencyMatrices(int y);
	bool checkConnectivity(int x);
	bool contains(vector<int> v, int el);
	void printSequences();
	void sortMaxSequences();
	Graph* getMaxSubGraph();

public:
	GraphSolver(Graph* G, Graph* H)
		: _G(G), _H(H) {}
	~GraphSolver();

	Graph* solve(vector<int>* g, vector<int>* h);
	Graph * approxSolve(vector<int>* g, vector<int>* h);
};

