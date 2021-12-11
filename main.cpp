#include "Graph.h"
int main(){
	Graph graph;
	graph.addVertex(1);
	graph.addVertex(2);
	graph.addVertex(3);
	graph.addVertex(4);
	graph.addVertex(5);
	graph.addVertex(6);
	graph.addEdge(5,2,3);
	graph.addEdge(1,2,3);
	graph.addEdge(2,3,3);	
	graph.addEdge(3,4,3);
	graph.addEdge(4,1,1);
	graph.addEdge(2,5,1);
	graph.addEdge(1,3,4);
	graph.addEdge(5,6,4);
	graph.addEdge(6,2,4);
	std::cout << std::endl << "Nodes: "<< graph.returnNodes() << std::endl;
	std::cout << "Edges: " << graph.returnEdges() << " " << std::endl;
	graph.DFS(2);
	std::cout << std::endl;
	graph.BFS(2);
	std::cout << std::endl;
	graph.DFS(1);
	std::cout << std::endl;
	graph.DFS(5);
	std::cout << std::endl;
	graph.removeVertex(2);
	std::cout << graph.removeVertex(56)<<std::endl;
	std::cout << graph.returnNodes()<<std::endl;
	std::cout << graph.returnEdges()<<std::endl;
	graph.returnNeighbors(56);
	graph.addVertex(2);
	graph.addEdge(2,3,3);
	std::cout << graph.returnEdges() << std::endl << graph.returnNodes()<< std::endl;
	return 0;
}
