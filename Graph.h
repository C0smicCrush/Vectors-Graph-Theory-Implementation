#ifndef GRAPH_H
#define GRAPH_H
#include "linkedlist.cpp"
#include <vector>
#include <algorithm>
class Graph{
	private:
	int nodes,edges;
	vector<LinkedList*> adjList;
	vector<int> adjNums;
	
	public:
		Graph();
		~Graph();
		int returnNodes();
		int returnEdges();
		bool addVertex(int);
		bool addEdge(int,int);
		bool removeVertex(int);
		bool removeEdge(int, int);
			
};
#endif
