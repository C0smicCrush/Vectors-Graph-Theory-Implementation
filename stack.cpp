/*********************
Name: Aatmodhee Goswami
Coding 03 Data Structures
Purpose: This is the cpp file for the stack program, which elaborates on the prototype methods in stack.h.
**********************/
#include "stack.h"
Stack::~Stack(){
	int top = 0;
	delete[] a;
}

// include header
Stack::Stack(int intIn){
	int* array{ new int[intIn]{} };
	a = array;
	top = -1;
}
//Checks if empty
bool Stack::isEmpty(){

return top < 0;
}

//Getter


int Stack::peek(){
	if(isEmpty()){
		throw 0;
	}
	return a[top];
}
	
//Setters
int Stack::pop(){//Returns a value too so it's a combination of getter and setter
	if(isEmpty()){
		throw 0; 
	}
	return a[top--];
}
bool Stack::push(int x){
	bool bo = false;
		
		a[++top] = x;

		bo = true;		
	return bo;
}


//




