#include "Graph.h"
Graph::Graph(){
	nodes = 0;
	edges = 0;
}
int Graph::returnEdges(){
	return edges;
}
int Graph::returnNodes(){
	return nodes;
}
bool Graph::addEdge(int primary, int secondary){
	bool added = 0;
	if((std::binary_search(adjNums.begin(),adjNums.end(),primary)) && (std::binary_search(adjNums.begin(),adjNums.end(),secondary))){
		bool added = 1;
	}
}
bool Graph::addVertex(int inVert){
	bool added = 0;
	if (!std::binary_search (adjNums.begin(), adjNums.end(), inVert)){
		added = 1;
	}
	return added;
}
int Graph::returnInsertLocation(int intIn){
	int retInt = 0;
	if (adjNums.size() > 0){
		for(int x = 0; x < adjNums.size(); x++ ){
			if(adjNums[x] < intIn){
				retInt++;
			}
		}
	}
	return retInt;
}
