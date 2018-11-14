#include <iostream>
#include <string>
#include <cstdlib>
#include <string>
#include <chrono>
#include "CsvReader.h"
#include "Parser.h"
#include "GraphSolver.h"
#include "GraphGenerator.h"
#include "SolutionVisualizer.h"
#include "Experiment.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

const string exNr = "1";

int main(int argc, char* argv[])
{
	Experiment ex;
	vector<double> results;
	ex.RunExact(&results, &GraphGenerator::genTree, 7, 1);
	system("pause");
	return 0;

	string pathH = "CSVs/ex" + exNr + "_g.csv";
	string pathG = "CSVs/ex" + exNr + "_h.csv";
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
	Graph* graphG = parser.parseToGraph(dataG);

	CsvReader csvReaderH = CsvReader(pathH);
	vector<vector<bool>> dataH = parser.parseToBool(csvReaderH.getData());
	if (!parser.canParseToGraph(dataH)) {
		cout << "Wrong graph H" << endl;
		return 0;
	}
	Graph* graphH = parser.parseToGraph(dataH);

	GraphSolver solver = GraphSolver(graphG, graphH);

	vector<size_t> g;
	vector<size_t> h;

	cout << "Exact algorithm:" << endl;
	double time;
	Graph* exactResult = solver.solve(&g, &h, &time);
	SolutionVisualizer(graphG, graphH, &g, &h, time).visualize();
	delete exactResult;


	cout << "Approximate algorithm:" << endl;
	Graph* approxResult = solver.approxSolve(&g, &h, &time);
	SolutionVisualizer(graphG, graphH, &g, &h, time).visualize();
	delete approxResult;

	delete graphG;
	delete graphH;

	system("pause");
	return 0;
}
