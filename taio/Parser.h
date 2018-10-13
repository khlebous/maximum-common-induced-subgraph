#pragma once

#include <vector>

using namespace std;

class Parser
{
private:
	char trueSymbol = '1';
	char falseSymbol = '0';
	char spaceSymbol = ' ';

public:
	vector<vector<bool>> parseToBool(vector<vector<string>> const data);

private:
	bool parseToBool(string s);
	string trim(string word);
};
