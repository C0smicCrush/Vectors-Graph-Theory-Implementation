#include "Graph.h"
Graph::Graph(){
	nodes = 0;
	edges = 0;
	outSTR = "Hello";
}
int Graph::returnEdges(){
	return edges;
}
int Graph::returnNodes(){
	return nodes;
}
bool Graph::addEdge(int primary, int secondary,int distance){
	bool added = 0;
	
	if((std::binary_search(adjNums.begin(),adjNums.end(),primary)) && (std::binary_search(adjNums.begin(),adjNums.end(),secondary))){
		int loc = returnInsertLocation(primary);
		int count1  = adjList[loc]->getCount();
		adjList[loc]->addNode(secondary, &outSTR, distance);
		int count2 = adjList[loc]->getCount();
		if(count1 < count2){
			added = 1;
			edges++;
		}
	}

	return added; 
}
bool Graph::addVertex(int inVert){
	bool added = 0;
	if (!std::binary_search (adjNums.begin(), adjNums.end(), inVert)){
		added = 1;
		int insertLoc = returnInsertLocation(inVert);
		LinkedList* newLL = new LinkedList;
		auto pos = adjList.begin() + insertLoc;
		adjList.insert(pos, newLL);
		adjNums.insert(adjNums.begin() + insertLoc, inVert);
		nodes++;
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
void Graph::DFS(int startNode){
	DFSprivate(startNode);
	
}
void Graph::DFSprivate(int startNode){
		vector<bool> visited(nodes, false);
		Stack stack;
		stack.push(startNode);
		while(!stack.isEmpty()){
			int top = stack.peek();
			stack.pop();
			int loc = returnInsertLocation(top);
			if(!visited[loc]){
				std::cout << top << " ";
				visited[loc] = true;
			}
			int count = adjList[loc]->getCount();
			int arr2[count];
			int* arr = arr2;
			adjList[loc]->returnArray(arr);
			for(int x = count -1; x > -1; x--){
				int loc = returnInsertLocation(arr2[x]);
				if(!visited[loc]){
					stack.push(arr2[x]);
				}
			}
	}

}
void Graph::BFS(int startingNode){
	BFSprivate(startingNode);
}
void Graph::BFSprivate(int startingNode){
	vector<bool> visited(nodes, false);
	queue<int> q;
	q.push	(startingNode);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		int loc = returnInsertLocation(top);
		if(!visited[loc]){
			std::cout << top << " ";
			visited[loc] = true;
		}
		int count = adjList[loc]->getCount();
		int arr2[count];
		int* arr = arr2;
		adjList[loc]->returnArray(arr);
		for(int x = 0;x < count;x++){
			int loc = returnInsertLocation(arr2[x]);
			if(!visited[loc]){
				q.push(arr2[x]);
			}
		}
	}
}
bool Graph::removeVertex(int intIn){
	bool removed = 0;
	int loc = returnInsertLocation(intIn);
	if(adjNums[loc] == intIn){
		removed = 1;
		edges = edges - adjList[loc]->getCount();
		for(int x = 0; x < nodes; x++){
			bool check = adjList[x]->deleteNode(intIn);
			edges = edges - check;
		}
		delete adjList[loc];
		adjList.erase(adjList.begin() + loc);
		adjNums.erase(adjNums.begin() + loc);
		nodes--;
	}

	return removed;
}
bool Graph::removeEdge(int primary, int secondary){
	bool removed = 0;
	int loc = returnInsertLocation(primary);
	if(adjNums[loc] == primary){
		removed = adjList[loc]->deleteNode(secondary);
	}
	edges = edges - removed;
	return removed;
}
void Graph::returnNeighbors(int startingNode){
	int loc = returnInsertLocation(startingNode);
	if(adjNums[loc] == startingNode){
		std::cout << startingNode << " Goes to " << std::endl; 
		adjList[loc]->printList(true);
		std::cout << "The following go to " << startingNode << std::endl;
		for(int x = 0; x < nodes; x++){
			if(adjList[x]->exists(startingNode)){
				std::cout << adjNums[x];
				adjList[x]->printNode(startingNode);
			}
		}
	}
	else{
		std::cout << "Nothing is connected to " << startingNode << std::endl;
	}

}
Graph::~Graph(){
	nodes = 0;
	edges = 0;
	for(int x = 0; nodes; x++){
		delete adjList[x];
	}
}
