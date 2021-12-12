/*
	Author: Aatmodhee Goswami
	file: Graph.h
	Purpose and usage: This file is the header file of the Graph class, and includes all of its prototypes
 */
#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <queue>
#include <algorithm>
#include "linkedlist.h"
#include "stack.h"
using std::vector;
using std::queue;
class Graph{
	private:
		int vertices,edges;
		vector<LinkedList*> adjList;
		vector<int> adjNums;
		string outSTR;
		int returnInsertLocation(int);
		bool DFSprivate(int);
		bool BFSprivate(int);
		bool disconnectedHelper(int);
		void removeVertexHelper(int,int);
	public:
		void clearGraph();
		void printVertices();
		bool existsVertex(int);
		bool existsEdge(int,int);
		void returnNeighbors(int);
		void DFS(int);
		void BFS(int);
		Graph();
		~Graph();
		int returnVertices();
		int returnEdges();
		bool addVertex(int);
		bool addEdge(int,int,int);
		bool removeVertex(int);
		bool removeEdge(int, int);
		bool isDisconnected();
			
};
#endif
