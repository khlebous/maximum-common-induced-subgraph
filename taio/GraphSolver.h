#pragma once
#include "Graph.h"
#include <vector>
using namespace std;

class GraphSolver
{
private:
	Graph* _G;
	Graph* _H;
	vector<size_t> X;
	vector<size_t> Y;
	vector<size_t> Xmax;
	vector<size_t> Ymax;

	void init();
	void solveYNode();
	void solveXNode();
	void approxSolveXNode();
	bool approxSolveYNode();
	bool updateMaxSequences();
	bool checkAdjecencyMatrices(size_t y);
	bool checkConnectivity(size_t x);
	bool contains(vector<size_t> v, size_t el);
	void printSequences();
	void sortMaxSequences();
	Graph* getMaxSubGraph();

public:
	GraphSolver(Graph* G, Graph* H): _G(G), _H(H) {}
	~GraphSolver() {}

	Graph* solve(vector<size_t>* g, vector<size_t>* h);
	Graph * approxSolve(vector<size_t>* g, vector<size_t>* h);
};

