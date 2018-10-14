#include <iostream>
#include <string>

#include "CsvReader.h"
#include "Parser.h"

using namespace std;

int main()
{
	cout << "Hello, World!\n\n";

	//string path = "CSVs/csvTest.txt";
	//string path = "CSVs/correctToParseToBool.txt";
	string path = "CSVs/correctGraph.txt";
	CsvReader csvReader = CsvReader(path);
	vector<vector<string>> graphS = csvReader.getData();

	Parser parser = Parser();
	vector<vector<bool>> graphB = parser.parseToBool(graphS);

	bool canParse = parser.canParseToGraph(graphB);
	cout << "can parse graphB? : " << canParse << endl;
	cout << endl;

	Graph graph = parser.parseToGraph(graphB);
	graph.print();
	cout << endl;

	cout << "Test edge function:" << endl;
	for (size_t i = 0; i < graph.verticesCount(); i++)
	{
		for (size_t j = 0; j < graph.verticesCount(); j++)
			cout << graph.edge(i, j) << " ";
		cout << endl;
	}

	return 0;
}