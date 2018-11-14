#include <chrono>
#include <string>
#include <vector>

#include <Windows.h>
#include "Graph.h"
#include "GraphSolver.h"

using namespace std;

class SolutionVisualizer
{
private:
	size_t maxGraphSize = 15;
	Graph* _G;
	Graph* _H;
	vector<size_t>* _X;
	vector<size_t>* _Y;
	chrono::duration<double> _t;


	string toString(vector<size_t>* v);
	void printGraphWithSubgraph(Graph* G, vector<size_t>* X);
	void printSubgraph();
	void printTime();
	void printSequences();
	bool contains(vector<size_t> * v, size_t el);


public:
	SolutionVisualizer(Graph* G, Graph* H, vector<size_t> * X, vector<size_t> * Y, chrono::duration<double>  t);
	~SolutionVisualizer();

	void visualize();
};

