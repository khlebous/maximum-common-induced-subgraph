#include "Experiment.h"




Experiment::Experiment()
{
}


Experiment::~Experiment()
{
}

void Experiment::Run(vector<double>* averageTimes, Graph *(GraphGenerator::* generateFunc)(size_t), int maxSize, int numberPerSize, unsigned int seed, bool exact)
{
	averageTimes->clear();

	GraphGenerator gg(seed);

	for (size_t i = 1; i < maxSize; i++)
	{
		vector<double> times;
		for (size_t j = 0; j < numberPerSize; j++)
		{
			Graph * g = (gg.*generateFunc)(i);
			Graph * h = (gg.*generateFunc)(i);

			vector<size_t> x;
			vector<size_t> y;
			double time;

			if (exact)
				GraphSolver(g, h).solve(&x, &y, &time);
			else
				GraphSolver(g, h).approxSolve(&x, &y, &time);
			times.push_back(time);

			delete g;
			delete h;
		}

		double sum = 0;
		for (auto& t : times)
		{
			sum += t;
		}
		averageTimes->push_back(sum / times.size());
	}
}

void Experiment::RunExact(vector<double> * averageTimes, Graph * (GraphGenerator::*generateFunc) (size_t), int maxSize, int numberPerSize, unsigned int seed)
{
	Run(averageTimes, generateFunc, maxSize, numberPerSize, seed, true);
}

void Experiment::RunAprox(vector<double>* averageTimes, Graph *(GraphGenerator::* generateFunc)(size_t), int maxSize, int numberPerSize, unsigned int seed)
{
	Run(averageTimes, generateFunc, maxSize, numberPerSize, seed, false);
}

