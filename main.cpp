#include "main.h"
int main(){

	Graph graph;// create Graph
	
	std::cout << std::endl<<  "returnVertices on an empty graph" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << std::endl << "Vertices: "<< graph.returnVertices() << std::endl;//check Vertices and edges on empty graph
	std::cout << std::endl<<  "returnEdges on an empty graph" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << "Edges: " << graph.returnEdges() << " " << std::endl;
	std::cout << std::endl<<  "Testing removeVertex on empty graph" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << graph.removeVertex(2);
	std::cout << std::endl<<  "Testing removeEdge on empty graph" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << graph.removeEdge(2,3); 
	
	
	std::cout << std::endl<<  "DFS and BFS on an empty graph" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.DFS(2);//check DFS on empty graph
	graph.BFS(2);//check BFS on empty graph
	
	
	std::cout << std::endl<<  "Testing existsVertex(5) on empty graph" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << "Exists : " << graph.existsVertex(5) << std::endl;
	std::cout << std::endl<<  "Testing existsEdge(5,3) on empty graph" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << "Exists : " << graph.existsEdge(5,3) << std::endl;
	//addVertex testing
	std::cout << std::endl<<  "Add a proper vertex number" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.addVertex(2);//add Arbitrary node
	std::cout << "Vertices : " << graph.returnVertices() << std::endl;
	std::cout << std::endl<<  "Adding the same number again" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.addVertex(2);//add same node again
	std::cout << "Vertices : " << graph.returnVertices() << std::endl;
	std::cout << std::endl<<  "Adding 0 as vertex" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.addVertex(0);//add invalid node number
	std::cout << "Vertices : " << graph.returnVertices() << std::endl;
	std::cout << std::endl<<  "Adding valid vertex num" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.addVertex(3);//add a valid node number
	std::cout << "Vertices : " << graph.returnVertices() << std::endl;
	std::cout << std::endl<<  "Adding another proper" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.addVertex(4); //add another node so we can see how the Graph behaves
	std::cout << "Vertices : " << graph.returnVertices() << std::endl;
	
	std::cout << std::endl<<  "BFS and DFS on disconnected" << std::endl << "----------------------------"<<std::endl << std::endl;
	//Check DFS and BFS
	std::cout << "DFS : ";
	graph.DFS(2);//try DFS on a disconnected graph
	std::cout << std::endl << "BFS : ";
	graph.BFS(4);//try BFS on a disconnected graph
	std::cout << std::endl<<std::endl<<  "BFS and DFS on nonexistant vertex" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << std::endl << "DFS : " << std::endl;
	graph.DFS(5);//try DFS on nonexistant vertex
	std::cout << "BFS : ";
	graph.BFS(5);//try BFS on nonexistant vertex
	std::cout << std::endl;
	
	
	//addEdge testing
	graph.addEdge(2,4,5);//We add an Edge
	std::cout << std::endl<<"Adding a normal edge" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout <<"Edges : "<< graph.returnEdges() << std::endl;
	std::cout << std::endl<<"Adding the same edge again" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.addEdge(2,4,5); // Add same vertice again to test addEdge
	std::cout <<"Edges : "<< graph.returnEdges() << std::endl;
	std::cout << std::endl<<  "Adding the edge the opposite way" << std::endl << "-------------------------------"<<std::endl << std::endl;
	graph.addEdge(4,2,3); // Add edge the opposite way and check if edge counter updates
	std::cout << "Edges : " << graph.returnEdges()<<std::endl;
	std::cout << std::endl<<  "Adding the edge with a proper primary but improper secondary" << std::endl << "---------------------------------------------------------------"<<std::endl << std::endl;
	graph.addEdge(2,5,4);//Add edge with the primary int being part of the graph but the secondary int not being one
	std::cout << "Edges : " << graph.returnEdges()<<std::endl;
	std::cout << std::endl<<  "Adding the edge with improper primary and secondary" << std::endl << "-------------------------------------------------------"<<std::endl << std::endl;
	graph.addEdge(7,6,10);// Add edge with neither of the ints being part of the graph
	std::cout << "Edges : " << graph.returnEdges() << std::endl;
	std::cout << std::endl<<  "Adding the edge with improper distance" << std::endl << "----------------------------------------------------"<<std::endl << std::endl;
	graph.addEdge(2,3,0); //Add edge but with Distance of 0 
	std::cout << "Edges : " << graph.returnEdges() << std::endl;
	
	//Test isDisconnected method
	//Currently a disconnected graph
	std::cout << std::endl<<  "Disconnected Graph: " << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << "Is disconnected : " << graph.isDisconnected() << std::endl;//Check if isDisconnected works
	std::cout << std::endl<<  "Connected Graph: " << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.addEdge(2,3,3);//Add edge to create connected graph
	std::cout << "Is disconnected : " << graph.isDisconnected() << std::endl; //Another check of isDisconnected
	
	
	//BFS and DFS on a connected graph
	std::cout << std::endl<<  "DFS on connected graph" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << "DFS : ";
	graph.DFS(2);//DFS on connected graph
	std::cout << std::endl;
	std::cout << std::endl<<  "BFS on connected graph" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout <<  "BFS : ";
	graph.BFS(2);//BFS on connected graph
	std::cout << std::endl;
	std::cout << std::endl<<  "DFS on vertex without connections" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << "DFS : ";
	graph.DFS(3); //DFS on 3 which doesn't go to any other numbers 
	std::cout << std::endl<<std::endl;
	
	std::cout << std::endl<<  "adding vertices and edges to make testing easier" << std::endl << "---------------------------------------------------"<<std::endl;
	
	/*
	We add some more vertices and edges thus to test our methods better
	 */
	graph.addVertex(5);
	graph.addVertex(1);
	graph.addEdge(1,3,5);
	graph.addEdge(5,1,2);
	graph.addEdge(5,2,7);
	graph.addEdge(3,4,4);
	graph.addEdge(3,5,7);
	std::cout << ".....done" << std::endl;
	
	
	//returnNeighbors testing
	std::cout << std::endl<<  "Testing returnNeighbors(3)" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.returnNeighbors(3);//Neighbors for 3 are 2 , 3 , 5 , 1
	std::cout << std::endl<<  "Testing returnNeighbors(2)" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.returnNeighbors(2);//Neighbors for 2 are 3 , 4, 5
	std::cout << std::endl<<  "Testing returnNeighbors for nonexistant vertice" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.returnNeighbors(56);
	std::cout << std::endl<<  "Testing existsEdge(2,3) -it exists-" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << graph.existsEdge(2,3) << std::endl;//check if 2,3 exists(it does)
	std::cout << std::endl<<  "Testing existsEdge(2,6) -it doesn't exist-" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << graph.existsEdge(2,6) << std::endl;//check if 2,6 exists(it doesn't)
	std::cout << std::endl<<  "Testing DFS with 2" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.DFS(2);//DFS starting with 2
	std::cout << std::endl<<  "Testing BFS with 3" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.BFS(3);//BFS starting with 2
	std::cout << std::endl<<  "Checking isDisconnected on a connected graph" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << graph.isDisconnected();
	
	
	//removeVertex testing
	std::cout << std::endl<<  "Testing removeVertex with nonexistant vertex" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << graph.removeVertex(56)<<std::endl;//56 isnt a vertex
	std::cout << std::endl<<  "Testing removeVertex with existant vertex" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << "Vertices before removal : " << graph.returnVertices()<<std::endl;
	std::cout <<"Removal : " << graph.removeVertex(2) << std::endl;//2 is a vertex
	std::cout << "Vertices after removal : " << graph.returnVertices()<<std::endl;
	
	//removeEdge testing
	std::cout << std::endl<<  "Testing removeEdge with known edge" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << "Edges before removal : " << graph.returnEdges()<<std::endl;
	std::cout <<"Removal : " << graph.removeEdge(3,4) << std::endl;
	std::cout << "Edges after removal : " << graph.returnEdges()<<std::endl;
	std::cout << std::endl<<  "Testing removeEdge with known bad edge" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << "Edges before removal : " << graph.returnEdges()<<std::endl;
	std::cout <<"Removal : " <<graph.removeEdge(3,6) << std::endl;
	std::cout << "Edges before removal : " << graph.returnEdges() << std::endl; 
 	
 	
 	//delete graph
 	Graph* graphPtr;
 	graphPtr = &graph;
 	delete graphPtr;
 	Graph graphTest;
 	graphTest.addVertex(0);
 	graphTest.addVertex(1);
 	graphTest.addVertex(2);
 	graphTest.addVertex(3);
 	graphTest.addVertex(4);
 	graphTest.addVertex(5);
 	graphTest.addVertex(6);
 	graphTest.addVertex(7);
 	graphTest.addVertex(8);
 	graphTest.addVertex(9);
 	std::cout << graphTest.returnVertices();
 	
	return 0;
}
