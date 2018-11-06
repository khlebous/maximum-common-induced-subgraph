#include "GraphSolver.h"

using namespace std;

GraphSolver::GraphSolver()
{
}


GraphSolver::~GraphSolver()
{
}



Graph GraphSolver::getSubGraph(Graph const G, vector<int> vertices)
{
	throw logic_error("not implemented exception");
}

bool GraphSolver::checkAdjecencyMatrices(Graph const G, vector<int> X, int x, Graph const H, vector<int> Y, int y)
{
	throw logic_error("not implemented exception");
}

bool GraphSolver::checkConnectivity(Graph const G, vector<int> X, int x)
{
	throw logic_error("not implemented exception");
}

Graph GraphSolver::Solve(Graph const G, Graph const H)
{
	vector<int> X;
	vector<int> Y;

	//loops or recurrence?
	//i think recurrence

	Graph result = getSubGraph(G, X);
	return result;
}





