#include "Graph.h"
#include <iostream>
#include <chrono>
#include "SolutionVisualizer.h"
using namespace std;

string SolutionVisualizer::toString(vector<size_t> * v)
{
	string result = "(";
	for (auto& el : *v)
	{
		result += to_string(el);
		if (el != v->back())
			result += ", ";
	}
	result += ")";

	return result;
}

void SolutionVisualizer::printGraphWithSubgraph(Graph* G, vector<size_t> * X)
{
	if (G->verticesCount() > maxGraph)
		return;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	short white = 15;
	short normal = 7;
	short gray = 8;

	cout << "  ";

	for (size_t j = 0; j < G->verticesCount(); j++)
	{
		if (contains(X, j))
			SetConsoleTextAttribute(hConsole, white);
		else
			SetConsoleTextAttribute(hConsole, gray);

		cout << j << " ";
	}

	cout << endl;

	for (size_t i = 0; i < G->verticesCount(); i++)
	{
		if (contains(X, i))
			SetConsoleTextAttribute(hConsole, white);
		else
			SetConsoleTextAttribute(hConsole, gray);

		cout << i << " ";

		for (size_t j = 0; j < G->verticesCount(); j++)
		{

			if (j != -1 && i != -1)
			{
				if (contains(X, i) && contains(X, j))
					SetConsoleTextAttribute(hConsole, white);
				else
					SetConsoleTextAttribute(hConsole, gray);

				cout << G->edge(i, j) << " ";
			}
		}
		cout << endl;
	}

	SetConsoleTextAttribute(hConsole, normal);
	cout << endl;
}

void SolutionVisualizer::printSubgraph(Graph* G, vector<size_t> * X)
{
	cout << "Subgraph:" << endl;
	for (auto& i : *X)
	{
		for (auto& j : *X)
		{
			cout << G->edge(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;

}

void SolutionVisualizer::printTime(chrono::duration<double>  t)
{
	cout << "Elapsed time: " << t.count() << " s" << endl << endl;
}

void SolutionVisualizer::printSequences(vector<size_t> * X, vector<size_t> * Y)
{
	cout << "X=" << toString(X) << endl;
	cout << "Y=" << toString(Y) << endl;
	cout << endl;
}

bool SolutionVisualizer::contains(vector<size_t> * v, size_t el)
{
	return find(v->begin(), v->end(), el) != v->end();
}

SolutionVisualizer::SolutionVisualizer()
{
}


SolutionVisualizer::~SolutionVisualizer()
{
}

void SolutionVisualizer::visualize(Graph* G, Graph* H, vector<size_t> * X, vector<size_t> * Y, chrono::duration<double>  t)
{
	printTime(t);
	printSequences(X, Y);
	printSubgraph(G, X);

	cout << "Graph G:" << endl;
	printGraphWithSubgraph(G, X);

	cout << "Graph H:" << endl;
	printGraphWithSubgraph(H, Y);
}
