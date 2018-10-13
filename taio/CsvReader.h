#pragma once

#include <iostream>
#include <vector>

using namespace std;

class CsvReader
{
	string fileName;
	char delimeter;

public:
	CsvReader(string filename, char delm = ',') 
		:fileName(filename), delimeter(delm) { }

	vector<vector<string>> getData();

private:
	vector<string> split(string line);
	string trim(string line, size_t startPos, size_t length);
};

