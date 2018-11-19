#include "CsvReader.h"
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

istream& safeGetline(istream& is, string& t)
{
	t.clear();

	istream::sentry se(is, true);
	streambuf* sb = is.rdbuf();
	
	for (;;) {
		int c = sb->sbumpc();
		switch (c) {
		case '\n':
			return is;
		case '\r':
			if (sb->sgetc() == '\n')
				sb->sbumpc();
			return is;
		case streambuf::traits_type::eof():
			// Also handle the case when the last line has no line ending
			if (t.empty())
				is.setstate(ios::eofbit);
			return is;
		default:
			t += (char)c;
		}
	}
}

vector<vector<string>> CsvReader::getData()
{
	vector<vector<string> > dataList;

	ifstream file(fileName);
	string line = "";

	while (!safeGetline(file, line).eof())
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
				splitedLine.push_back("");
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