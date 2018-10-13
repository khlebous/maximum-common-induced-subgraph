#include <iostream>
#include <string>

#include "CsvReader.h"
#include "Parser.h"

using namespace std;

int main()
{
	cout << "Hello, World!\n";

	//string path = "CSVs/csvTest.txt";
	string path = "CSVs/correctToParseToBool.txt";
	CsvReader csvReader = CsvReader(path);
	vector<vector<string>> graphS = csvReader.getData();

	Parser parser = Parser();
	vector<vector<bool>> graphB = parser.parseToBool(graphS);

	for (auto& row : graphB) {
		for (bool el : row) {
			cout << '_' << el;
		}
		cout << "_\n";
	}

	return 0;
}