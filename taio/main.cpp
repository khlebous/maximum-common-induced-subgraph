#include <iostream>
#include <string>

#include "CsvReader.h"

using namespace std;

int main()
{
	cout << "Hello, World!\n";

	string path = "csvTest.txt";
	CsvReader csvReader = CsvReader(path);

	vector<vector<string>> graph = csvReader.getData();
	for (auto& row : graph) {
		for (auto& col : row) {
			cout << '_' << col;
		}
		cout << "_\n";
	}

	return 0;
}