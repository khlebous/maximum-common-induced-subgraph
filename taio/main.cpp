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

int main(int argc, char* argv[])
{
	bool runExact = true;
	bool runAprox = true;

	string pathG = "";
	string pathH = "";

	if (argc < 3 || argc > 4)
	{
		cout << "Wrong args" << endl;
		return 0;
	}

	if (argc == 3)
	{
		pathG = argv[1];
		pathH = argv[2];
	}

	if (argc == 4)
	{
		pathG = argv[1];
		pathH = argv[2];

		if (strcmp(argv[3], "-e") == 0)
		{
			runAprox = false;
		}

		if (strcmp(argv[3], "-a") == 0)
		{
			runExact = false;
		}
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
	double time;

	if (runExact)
	{
		cout << endl << "Exact algorithm:" << endl;
		Graph* exactResult = solver.solve(&g, &h, &time);
		SolutionVisualizer(graphG, graphH, &g, &h, time).visualize();
		delete exactResult;
	}

	if (runAprox)
	{
		cout << endl << "Approximate algorithm:" << endl;
		Graph* approxResult = solver.approxSolve(&g, &h, &time);
		SolutionVisualizer(graphG, graphH, &g, &h, time).visualize();
		delete approxResult;
	}

	delete graphG;
	delete graphH;

	system("pause");
	return 0;
}

//Experiment ex;
//vector<double> results;
//ex.RunExact(&results, &GraphGenerator::genTree, &GraphGenerator::genTree, 7, 1);
//system("pause");
//return 0;