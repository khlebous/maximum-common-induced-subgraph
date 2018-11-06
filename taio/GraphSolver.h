#pragma once
#pragma once

#include "Graph.h"
#include <vector>
using namespace std;

class GraphSolver
{
public:
	GraphSolver();
	~GraphSolver();

	Graph Solve(Graph const G, Graph const H);

};

