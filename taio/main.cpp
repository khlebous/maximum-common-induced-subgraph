#include <iostream>
#include <string>
#include <cstdlib>
#include <string>
#include <chrono>

#include "CsvReader.h"
#include "Parser.h"
#include "GraphSolver.h"
using namespace std;

void printDuration(std::chrono::duration<double> elapsed);
void printSequences(vector<int> X, vector<int> Y);

int main(int argc, char* argv[])
{
	string pathG = "CSVs/GraphG.txt";
	string pathH = "CSVs/GraphH.txt";

	if (argc == 3)
	{
		pathG = argv[1];
		pathH = argv[2];
	}

	Parser parser = Parser();

	CsvReader csvReaderG = CsvReader(pathG);
	vector<vector<bool>> dataG = parser.parseToBool(csvReaderG.getData());
	if (!parser.canParseToGraph(dataG)) {
		cout << "Wrong graph G" << endl;
		return 0;
	}
	Graph graphG = parser.parseToGraph(dataG);

	CsvReader csvReaderH = CsvReader(pathH);
	vector<vector<bool>> dataH = parser.parseToBool(csvReaderH.getData());
	if (!parser.canParseToGraph(dataH)) {
		cout << "Wrong graph H" << endl;
		return 0;
	}
	Graph graphH = parser.parseToGraph(dataH);

	GraphSolver solver = GraphSolver(&graphG, &graphH);
	vector<int> g;
	vector<int> h;

	cout << "Exact algorithm:" << endl;
	auto start = std::chrono::high_resolution_clock::now();
	Graph* exactResult = solver.solve(&g, &h);
	auto finish = std::chrono::high_resolution_clock::now();
	printDuration(finish - start);
	printSequences(g, h);
	delete exactResult;

	cout << "Approximate algorithm:" << endl;
	start = std::chrono::high_resolution_clock::now();
	Graph* approxResult = solver.approxSolve(&g, &h);
	finish = std::chrono::high_resolution_clock::now();
	printDuration(finish - start);
	printSequences(g, h);
	delete approxResult;

	system("pause");
	return 0;
}

void printDuration(std::chrono::duration<double> elapsed) {
	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}

void printSequences(vector<int> X, vector<int> Y)
{
	cout << "X=(";
	for (auto& v : X)
	{
		cout << v;
		if (v != X.back())
			cout << " , ";
	}
	cout << ")" << endl;

	cout << "Y=(";
	for (auto& v : Y)
	{
		cout << v;
		if (v != Y.back())
			cout << " , ";
	}
	cout << ")" << endl << endl;
}