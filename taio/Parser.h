#pragma once
#include <vector>
#include "Graph.h"
using namespace std;

class Parser
{
private:
	char trueSymbol = '1';
	char falseSymbol = '0';
	char spaceSymbol = ' ';

public:
	vector<vector<bool>> parseToBool(vector<vector<string>> const data);
	Graph* parseToGraph(vector<vector<bool>> const data);

	bool canParseToGraph(vector<vector<bool>> const data);

private:
	bool parseToBool(string s);
	string trim(string word);
};
