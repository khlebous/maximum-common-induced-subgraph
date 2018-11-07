#include <iostream>
#include <string>
#include <cstdlib>

#include "CsvReader.h"
#include "Parser.h"
#include "GraphSolver.h"

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
	graph.printEdges();
	cout << endl;

	cout << "Test edge function:" << endl;
	graph.print();

	GraphSolver solver = GraphSolver(&graph, &graph);
	Graph* result = solver.solve();
	result->printEdges();
	result->print();

	delete result;

	system("pause");
	return 0;
}