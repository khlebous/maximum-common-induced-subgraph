#include "CsvReader.h"

#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string>> CsvReader::getData()
{
	vector<vector<string> > dataList;

	ifstream file(fileName);
	string line = "";

	while (getline(file, line))
	{
		vector<string> vec = split(line);
		dataList.push_back(vec);
	}
	file.close();

	return dataList;
}

vector<string> CsvReader::split(string line)
{
	vector<string> splitedLine;

	size_t startPos = 0;
	for (size_t i = 0; i < line.length(); i++)
	{
		if (line[i] == delimeter)
		{
			if (i == startPos)
			{
				splitedLine.push_back("");
			}
			else
			{
				string nextWord = line.substr(startPos, i - startPos);
				splitedLine.push_back(nextWord);
			}
			startPos = i + 1;
		}
		else if (i == line.length() - 1)
		{
			string nextWord = line.substr(startPos, i - startPos + 1);
			splitedLine.push_back(nextWord);
		}
	}

	return splitedLine;
}

string CsvReader::trim(string line, size_t startPos, size_t length)
{
	string word = line.substr(startPos, length);

	char space = ' ';

	int firstNonSpacePos = -1;
	while (word[++firstNonSpacePos] == space);

	int lastNonSpacePos = word.length();
	while (word[--lastNonSpacePos] == space);

	if (firstNonSpacePos > lastNonSpacePos)
		throw "Empty Word";

	return word.substr(firstNonSpacePos, lastNonSpacePos - firstNonSpacePos + 1);
}