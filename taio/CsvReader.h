#pragma once

#include <iostream>
#include <vector>

using namespace std;

class CsvReader
{
private:
	string fileName;
	char delimeter;

public:
	CsvReader(string filename, char delm = ',') 
		:fileName(filename), delimeter(delm) { }

	vector<vector<string>> getData();

private:
	vector<string> split(string line);
};
