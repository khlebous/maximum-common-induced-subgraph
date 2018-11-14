#include <iostream>
#include <chrono>
#include <iomanip>

#include "Graph.h"
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
	if (G->verticesCount() > maxGraphSize)
		return;

	int w = G->verticesCount() < 10 ? 2 : 3;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int white = 15;
	int normal = 7;
	int gray = 8;

	cout << setw(w) << " " << setw(w) << "|";

	SetConsoleTextAttribute(hConsole, white);
	for (auto& v : *X)
	{
		cout << setw(w) << v;
	}

	SetConsoleTextAttribute(hConsole, gray);
	for (size_t j = 0; j < G->verticesCount(); j++)
	{
		if (!contains(X, j))
		{
			cout << setw(w) << j;
		}
	}
	SetConsoleTextAttribute(hConsole, normal);
	cout << endl;

	cout << string(2 * w - 1, '-') << "|" << string(1 + w * G->verticesCount(), '-') << endl;



	for (auto& v : *X)
	{
		SetConsoleTextAttribute(hConsole, white);
		cout << setw(w) << v;

		SetConsoleTextAttribute(hConsole, normal);
		cout << setw(w) << "|";

		SetConsoleTextAttribute(hConsole, white);
		for (auto& u : *X)
		{
			cout << setw(w) << G->edge(v, u);
		}

		SetConsoleTextAttribute(hConsole, gray);
		for (size_t j = 0; j < G->verticesCount(); j++)
		{
			if (!contains(X, j))
				cout << setw(w) << G->edge(v, j);
		}
		SetConsoleTextAttribute(hConsole, normal);
		cout << endl;
	}

	for (size_t i = 0; i < G->verticesCount(); i++)
	{
		if (contains(X, i))
			continue;

		SetConsoleTextAttribute(hConsole, gray);
		cout << setw(w) << i;

		SetConsoleTextAttribute(hConsole, normal);
		cout << setw(w) << "|";

		SetConsoleTextAttribute(hConsole, gray);
		for (auto& v : *X)
		{
			cout << setw(w) << G->edge(i, v);
		}

		for (size_t j = 0; j < G->verticesCount(); j++)
		{
			if (!contains(X, j))
				cout << setw(w) << G->edge(i, j);
		}
		SetConsoleTextAttribute(hConsole, normal);
		cout << endl;
	}

	cout << endl;
}

void SolutionVisualizer::printSubgraph()
{
	cout << "Subgraph:" << endl;
	for (auto& i : *_X)
	{
		for (auto& j : *_X)
		{
			cout << _G->edge(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;

}

void SolutionVisualizer::printTime()
{
	cout << "Elapsed time: " << _t << " s" << endl << endl;
}

void SolutionVisualizer::printSequences()
{
	cout << "X=" << toString(_X) << endl;
	cout << "Y=" << toString(_Y) << endl;
	cout << endl;
}

bool SolutionVisualizer::contains(vector<size_t> * v, size_t el)
{
	return find(v->begin(), v->end(), el) != v->end();
}

SolutionVisualizer::SolutionVisualizer(Graph* G, Graph* H, vector<size_t> * X, vector<size_t> * Y, double  t)
{
	_G = G;
	_H = H;
	_X = X;
	_Y = Y;
	_t = t;
}

SolutionVisualizer::~SolutionVisualizer()
{
}

void SolutionVisualizer::visualize()
{
	printTime();
	printSequences();
	//printSubgraph();

	cout << "Graph G:" << endl;
	printGraphWithSubgraph(_G, _X);

	cout << "Graph H:" << endl;
	printGraphWithSubgraph(_H, _Y);
}
