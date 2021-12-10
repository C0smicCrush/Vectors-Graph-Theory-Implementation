#ifndef GRAPH_H
#define GRAPH_H
#include "linkedlist.h"
#include "stack.h"
#include <vector>
#include <queue>
#include <algorithm>
using std::vector;
using std::queue;
class Graph{
	private:
		int nodes,edges;
		vector<LinkedList*> adjList;
		vector<int> adjNums;
		string outSTR;
		int returnInsertLocation(int);
		void DFSprivate(int);
		void BFSprivate(int);
	public:
		void DFS(int);
		void BFS(int);
		Graph();
		~Graph();
		int returnNodes();
		int returnEdges();
		bool addVertex(int);
		bool addEdge(int,int,int);
		bool removeVertex(int);
		bool removeEdge(int, int);
			
};
#endif
