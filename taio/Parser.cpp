#include "Parser.h"
#include <vector>
#include <iostream>
using namespace std;

vector<vector<bool>> Parser::parseToBool(vector<vector<string>> const data)
{
	vector<vector<bool>> outData;
	for (auto& row : data)
	{
		vector<bool> line;
		for (auto& el : row)
		{
			bool value = parseToBool(el);
			line.push_back(value);
		}
		outData.push_back(line);
	}

	return outData;
}

Graph Parser::parseToGraph(vector<vector<bool>> const data)
{
	size_t vertCount = data.size();
	bool** edges = new bool*[vertCount - 1];

	for (size_t i = 1; i < vertCount; i++)
	{
		edges[i - 1] = new bool[i];

		for (size_t j = 0; j < i; j++)
			edges[i - 1][j] = data[i][j];
	}

	return Graph(vertCount, edges);
}

bool Parser::canParseToGraph(vector<vector<bool>> const data)
{
	size_t vertCount = data.size();

	if (vertCount == 0)
		return false;

	for (auto& el : data)
	{
		if (el.size() != vertCount)
			return false;
	}

	for (size_t i = 0; i < vertCount; i++)
		for (size_t j = 0; j < i; j++)
		{
			if (data[i][j] != data[j][i])
				return false;
		}

	for (size_t i = 0; i < vertCount; i++)
		if (data[i][i] == true)
			return false;

	return true;
}

bool Parser::parseToBool(string s)
{
	string trimed = trim(s);

	if (trimed.length() != 1)
		throw "Incorrect input";
	char symbolToParse = trimed[0];

	if (symbolToParse == trueSymbol)
		return true;
	else if (symbolToParse == falseSymbol)
		return false;
	else
		throw "Incorrect input";
}

string Parser::trim(string word)
{
	if (word == "")
		return "";

	int firstNonSpacePos = -1;
	while (word[++firstNonSpacePos] == spaceSymbol);

	int lastNonSpacePos = word.length();
	while (word[--lastNonSpacePos] == spaceSymbol);

	if (firstNonSpacePos > lastNonSpacePos)
		return "";

	return word.substr(firstNonSpacePos, lastNonSpacePos - firstNonSpacePos + 1);
}
