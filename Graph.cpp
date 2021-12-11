#include "Graph.h"
Graph::Graph(){
	vertices = 0;
	edges = 0;
	outSTR = "Hello";
}
int Graph::returnEdges(){
	return edges;
}
int Graph::returnVertices(){
	return vertices;
}
bool Graph::existsEdge(int primary, int secondary){
	bool ret = 0;
	if(vertices > 0){
	if((std::binary_search(adjNums.begin(),adjNums.end(),primary))){
		int loc = returnInsertLocation(primary);
		ret = adjList[loc]->exists(secondary);
		}
	}
	return ret;
}
bool Graph::existsVertex(int inVert){
	bool ret = 0;
	if(vertices > 0 ){
	int loc = returnInsertLocation(inVert);
	if(adjNums[loc] == inVert){
		ret = 1;
		}
	}
	return ret;
}
bool Graph::isDisconnected(){
	bool ret = 1; 
	for(int x = 0; x < vertices; x++){
		bool check = disconnectedHelper(adjNums[x]);
		if(check == 1){
			ret = 0;
		}
	}
	return ret;
}
bool Graph::disconnectedHelper(int startNode){
	vector<bool> visited(vertices, false);
	bool ret = 0;
	Stack stack;
	int vis = 0;
	stack.push(startNode);
	while(!stack.isEmpty()){
		int top = stack.peek();
		stack.pop();
		int loc = returnInsertLocation(top);
		if(!visited[loc]){
			vis++;
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
	if(vis == vertices){
		ret = 1;
	}
	return ret;
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
	if (!std::binary_search (adjNums.begin(), adjNums.end(), inVert) && inVert > 0){
		added = 1;
		int insertLoc = returnInsertLocation(inVert);
		LinkedList* newLL = new LinkedList;
		adjList.insert(adjList.begin()+insertLoc, newLL);
		adjNums.insert(adjNums.begin() + insertLoc, inVert);
		vertices++;
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
	if(vertices > 0){
		int check = returnInsertLocation(startNode);
		if(adjNums[check] == startNode){
		DFSprivate(startNode);
		}	
	}
	
}
bool Graph::DFSprivate(int startNode){
		vector<bool> visited(vertices, false);
		bool ret = 0;
		Stack stack;
		int vis = 0;
		stack.push(startNode);
		while(!stack.isEmpty()){
			int top = stack.peek();
			stack.pop();
			int loc = returnInsertLocation(top);
			if(!visited[loc]){
				std::cout << top << " ";
				vis++;
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
	if(vis == vertices){
		ret = 1;
	}
	return ret;
}
void Graph::BFS(int startingNode){
	if(vertices > 0){
		int check = returnInsertLocation(startingNode);
		if(adjNums[check] == startingNode){
		BFSprivate(startingNode);
		}
	}
}
bool Graph::BFSprivate(int startingNode){
	vector<bool> visited(vertices, false);
	bool ret = 0;
	int vis = 0;
	queue<int> q;
	q.push	(startingNode);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		int loc = returnInsertLocation(top);
		if(!visited[loc]){
			std::cout << top << " ";
			vis++;
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
	if(vis == vertices){
		ret = 1;
	}
	return ret;
}
bool Graph::removeVertex(int intIn){
	bool removed = 0;
	if(vertices > 0){
	int loc = returnInsertLocation(intIn);
	if(adjNums[loc] == intIn){
		removed = 1;
		edges = edges - adjList[loc]->getCount();
		for(int x = 0; x < vertices; x++){
			bool check = adjList[x]->deleteNode(intIn);
			edges = edges - check;
			}
		delete adjList[loc];
		adjList.erase(adjList.begin() + loc);
		adjNums.erase(adjNums.begin() + loc);
		vertices--;
		}
	}
	return removed;
}
bool Graph::removeEdge(int primary, int secondary){
	bool removed = 0;
	if(vertices > 0 ){
	int loc = returnInsertLocation(primary);
	if(adjNums[loc] == primary){
		removed = adjList[loc]->deleteNode(secondary);
		}	
	edges = edges - removed;
	return removed;
	}
}
void Graph::returnNeighbors(int startingNode){
	int loc = returnInsertLocation(startingNode);
	if(adjNums[loc] == startingNode){
		std::cout << startingNode << " Goes to " << std::endl; 
		adjList[loc]->printList(true);
		std::cout << "The following go to " << startingNode << std::endl;
		for(int x = 0; x < vertices; x++){
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
Graph::~Graph()
{
	clear();
}

void Graph::clear()
{

	for(int x = 0; x < vertices; x++){
		delete adjList[x];
	}
	adjList.clear();
	adjNums.clear();

	edges = 0;
	vertices = 0;
}
