 main
#include <iostream>
#include "graph.h"
=======
/*
	Author: Aatmodhee Goswami
	file: main.cpp
	Purpose and usage: This file is the testing center of the Graph Class and includes all of its public methods to test
 */
#include "main.h"
 main
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
	graph.addVertex(5);//add another one
	
	
	std::cout << std::endl<<  "BFS and DFS on disconnected" << std::endl << "----------------------------"<<std::endl << std::endl;
	//Check DFS and BFS
	std::cout << "DFS : ";
	graph.DFS(2);//try DFS on a disconnected graph
	std::cout << std::endl << "BFS : ";
	graph.BFS(4);//try BFS on a disconnected graph
	std::cout << std::endl<<std::endl<<  "BFS and DFS on nonexistant vertex" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << std::endl << "DFS : " << std::endl;
	graph.DFS(6);//try DFS on nonexistant vertex
	std::cout << "BFS : ";
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
	graph.addEdge(2,6,4);//Add edge with the primary int being part of the graph but the secondary int not being one
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
	graph.addEdge(3,5,2);
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
	graph.DFS(5); //DFS on 3 which doesn't go to any other numbers 
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
	std::cout << std::endl<<  "Testing addEdge under for loops" << std::endl << "----------------------------"<<std::endl << std::endl;
	for(int x =0; x < 10; x++){
		graph.addEdge(x,x-1,2); //Test how it performs under loops
	}
	std::cout << std::endl<<  "...done" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << std::endl<<  "Testing printVertices()" << std::endl << "----------------------------"<<std::endl << std::endl;
	graph.printVertices();
	
	
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
 	
 	
	std::cout << std::endl<<  "Testing graph under for loops" << std::endl << "----------------------------"<<std::endl << std::endl; 	
 	for(int x = 0; x < 10; x++ ){
 		graph.addVertex(x);
 		graph.addEdge(x,x-1,2);
 		graph.addEdge(x-1,x,2);
	 }
	std::cout << "......done" <<std::endl;
	std::cout << std::endl<<  "BFS of 10" << std::endl << "----------------------------"<<std::endl << std::endl; 		 
	graph.BFS(10);
	
	std::cout << std::endl<<  "Making a list of random data and adding it to vertex randomly as our final test" << std::endl << "--------------------------------------------------------------"<<std::endl << std::endl;
	srand(time(NULL));
	const int testdatasize  = rand () % 30 + 10;
	int testdata[testdatasize];
	int distances[testdatasize];
	for(int x = 0 ; x < testdatasize; x ++ ){
		testdata[x] = rand() % 30;
		distances[x]  = rand() % 30;
		graph.addVertex(testdata[x]);
	}
	std::cout << std::endl<<  "Data Added" << std::endl << "----------------------------"<<std::endl << std::endl;
	
	std::cout << std::endl<<  "Randomly doing operations 50 times" << std::endl << "----------------------------"<<std::endl << std::endl;
	for(int x = 0; x < 50; x++){
		int ran = rand() % 3;
		int ran2 = 10 + rand() % 5;
		int randist = 10 +  rand() % 3;
		switch(ran){
			case 0:
				graph.addEdge(testdata[ran2], testdata[randist], distances[randist]);
				break;
			case 1:
				graph.removeEdge(testdata[ran2],testdata[randist]);
				break;
			case 2:
				graph.addVertex(testdata[ran2]);
				break;
		}
	}
	std::cout << std::endl<<  "Checking the Vertices and Edges" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << "Edges : "  << graph.returnEdges() << std::endl;
	std::cout << "Vertices : " << graph.returnVertices() << std::endl;
	std::cout << std::endl<<  "Now trying BFS with a few random ints which could be in the Graph" << std::endl << "----------------------------"<<std::endl << std::endl;
	for(int x = 0; x < 5; x++){
		int ran = rand() % testdatasize;
		std::cout << std::endl << "Next: " << std::endl;
		graph.BFS(testdata[ran]); 

	}
	std::cout << std::endl<<  "Running isDisconnected" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << "Disconnected : " << graph.isDisconnected() << std::endl;
	std::cout << std::endl<<  "Now trying DFS with a few random ints which could be in the Graph" << std::endl << "----------------------------"<<std::endl << std::endl;
	for(int x = 0; x < 5; x++){
		int ran = rand() % testdatasize;
		std::cout << std::endl << "Next: " << std::endl;
		graph.DFS(testdata[ran]); 

	}
	std::cout << std::endl<<  "Running isDisconnected" << std::endl << "----------------------------"<<std::endl << std::endl;
	std::cout << "Disconnected : " << graph.isDisconnected() << std::endl;
	
	std::cout << std::endl<<  "Running for loop on RemoveVertices " << std::endl << "----------------------------"<<std::endl << std::endl;

  	for(int x =0; x < 30; x++){
  		graph.removeVertex(x);
	  }
	std::cout << std::endl<<  "..done" << std::endl << "----------------------------"<<std::endl << std::endl;

	std::cout << std::endl<<  "Testing clearGraph() method" << std::endl << "----------------------------"<<std::endl << std::endl;
 	graph.clearGraph();
 	std::cout << std::endl<<  "..done" << std::endl << "----------------------------"<<std::endl << std::endl;
 	std::cout << std::endl<<  "Vertices : " << graph.returnVertices() <<  std::endl << "----------------------------"<<std::endl << std::endl;
 	std::cout << std::endl<<  "Done Testing" << std::endl << "----------------------------"<<std::endl << std::endl;
	return 0;
}
