#include "stdafx.h"
#include "CppUnitTest.h"
#include "../taio/GraphSolver.h"
#include "../taio/GraphSolver.cpp"
#include "../taio/Graph.h"
#include "../taio/Graph.cpp"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(TestGraphSolver)
	{
	public:

		TEST_METHOD(TestPath4Path4)
		{
			size_t vertCount = 4;
			bool** eG = new bool*[vertCount - 1];
			bool** eH = new bool*[vertCount - 1];

			for (size_t i = 0; i < vertCount - 1; i++)
			{
				eG[i] = new bool[i + 1];
				eH[i] = new bool[i + 1];
			}

			eG[0][0] = 1;
			eG[1][0] = 0; eG[1][1] = 1;
			eG[2][0] = 0; eG[2][1] = 0; eG[2][2] = 1;

			eH[0][0] = 1;
			eH[1][0] = 0; eH[1][1] = 0;
			eH[2][0] = 0; eH[2][1] = 1; eH[2][2] = 1;

			Graph* graphG = new Graph(vertCount, eG);
			Graph* graphH = new Graph(vertCount, eH);
			GraphSolver solver = GraphSolver(graphG, graphH);
			vector<int> g;
			vector<int> h;
			Graph* gR = solver.solve(&g, &h);

			Assert::AreEqual(vertCount, gR->verticesCount());
			Assert::AreEqual(g[0], h[0]);
			Assert::AreEqual(g[1], h[1]);
			Assert::AreEqual(g[2], h[3]);
			Assert::AreEqual(g[3], h[2]);

			delete gR;
			delete graphG;
			delete graphH;
		}

		TEST_METHOD(TestCircle5Complete6)
		{
			bool** eG = new bool*[4];
			bool** eH = new bool*[5];

			for (size_t i = 0; i < 4; i++)
				eG[i] = new bool[i+1];
			for (size_t i = 0; i < 5; i++)
				eH[i] = new bool[i+1];

			eG[0][0] = 1;
			eG[1][0] = 0; eG[1][1] = 1;
			eG[2][0] = 0; eG[2][1] = 0; eG[2][2] = 1;
			eG[3][0] = 1; eG[3][1] = 0; eG[3][2] = 0; eG[3][3] = 1;

			eH[0][0] = 1;
			eH[1][0] = 1; eH[1][1] = 1;
			eH[2][0] = 1; eH[2][1] = 1; eH[2][2] = 1;
			eH[3][0] = 1; eH[3][1] = 1; eH[3][2] = 1; eH[3][3] = 1;
			eH[4][0] = 1; eH[4][1] = 1; eH[4][2] = 1; eH[4][3] = 1; eH[4][4] = 1;

			Graph* graphG = new Graph(5, eG);
			Graph* graphH = new Graph(6, eH);
			GraphSolver solver = GraphSolver(graphG, graphH);
			vector<int> g;
			vector<int> h;
			Graph* gR = solver.solve(&g, &h);

			Assert::AreEqual((size_t)2, gR->verticesCount());
			Assert::AreEqual(g[0], h[0]);
			Assert::AreEqual(g[1], h[1]);

			delete gR;
			delete graphG;
			delete graphH;
		}
	};
}