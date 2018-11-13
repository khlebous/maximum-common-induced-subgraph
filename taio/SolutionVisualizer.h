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
	size_t maxGraph = 15;
	string toString(vector<size_t>* v);
	void printGraphWithSubgraph(Graph* G, vector<size_t>* X);
	void printSubgraph(Graph* G, vector<size_t>* X);
	void printTime(chrono::duration<double>  t);
	void printSequences(vector<size_t>* X, vector<size_t>* Y);
	bool contains(vector<size_t> * v, size_t el);


public:
	SolutionVisualizer();
	~SolutionVisualizer();

	void visualize(Graph* G, Graph* H, vector<size_t>* X, vector<size_t>* Y, chrono::duration<double> t);
};

