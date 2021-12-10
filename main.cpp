#include "Graph.h"
int main(){
	std::cout << "Hello ";
	Graph graph;
	graph.addVertex(1);
	graph.addVertex(2);
	graph.addVertex(3);
	graph.addVertex(4);
	graph.addVertex(5);
	graph.addEdge(1,2,3);
	graph.addEdge(2,1,3);	
	graph.addEdge(2,3,3);
	graph.addEdge(3,1,3);
	graph.addEdge(2,4,1);
	graph.addEdge(2,5,1);
	graph.addEdge(1,3,4);
//	std::cout << graph.returnNodes();
//	std::cout << graph.returnEdges() << " ";
	graph.DFS(2);
	return 0;
}
