/*********************
Name: Aatmodhee Goswami
Coding 03 Data Structures
Purpose: This is the header file for the stack program.It creates a class and prototypes for the methods.
**********************/
#ifndef STACK_ONE
#define STACK_ONE
//Maximum size of Stack

/*
 Class Definition
 */
class Stack
{
   
    public:

    Stack(int);
	~Stack();

    // Getters and Setters
    bool push(int);
    int pop();
    bool isEmpty();

    int peek();
    private:
    // Private attributes top and the array which houses stack
    int top;
    int* a;
};


#endif
