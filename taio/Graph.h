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
	bool edge(size_t i, size_t j);
	void setEdge(size_t i, size_t j, bool value);
	void print();
	void printEdges();
};

