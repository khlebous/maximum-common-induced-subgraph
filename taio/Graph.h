#pragma once

class Graph
{
private:
	size_t vertCount;
	bool** edges;

public:
	Graph(size_t vertCount, bool** edges) 
		: vertCount(vertCount), edges(edges) {}
	~Graph();

	size_t verticesCount() { return vertCount; }
	bool edge(int i, int j);
	void print();
};

