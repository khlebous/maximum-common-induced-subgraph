#pragma once

#include "GraphGenerator.h"
#include "GraphSolver.h"

class Experiment
{
private:
	void Run(vector<double> * averageTimes, Graph * (GraphGenerator::*generateFunc) (size_t), int maxSize, int numberPerSize, unsigned int seed, bool exact);


public:
	Experiment();
	~Experiment();

	void RunExact(vector<double> * averageTimes, Graph * (GraphGenerator::*generateFunc) (size_t), int maxSize = 10, int numberPerSize = 5, unsigned int seed = 0);
	void RunAprox(vector<double> * averageTimes, Graph * (GraphGenerator::*generateFunc) (size_t), int maxSize = 10, int numberPerSize = 5, unsigned int seed = 0);
};

