#include "Parser.h"

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
