//
//  main.cpp
//  CS341-midterm-02
//
//  Created by Jason Lu on 10/22/13.
//  Copyright (c) 2013 Lu Jason. All rights reserved.
//
//  Stack app
//  1) Receieved a syntax string like "C = A + B"
//  2) Save each part of syntax in stack
//  3) Reverse syntax to "B + A = C"
//  4) Display precedure each step of the way
//  5) Display result(reversed syntax) at console.
//
//  Originally composed by:
//  John Maslanka, Small Stack program, revised 3/2/2010, 2/14/2013
//  Revised by
//  Jason Lu, CS341 midterm app

#include <iostream>
#include <string>
using namespace std;


// class Node definition

class Node
{
public:
	Node();
	Node(string);
	void   putNextPtr (Node* ptr);
	Node*  getNextPtr ();
	void   putData (string D);
	string getData ();
private:
	string Data;
	Node* Next;
};

// full method definitions for class Node

Node::Node()
{
	Data = "";
	Next = NULL;
}

Node::Node(string A)
{
	Data = A;
	Next = NULL;
}
void   Node::putNextPtr (Node* ptr)
{Next = ptr;}
Node*  Node::getNextPtr ()
{return Next;}
void   Node::putData (string D)
{Data = D;}
string Node::getData ()
{return Data;}

// class Stack definition

class Stack
{
public:
	Stack();
	void Push(string);
	string Peek();
	string Pop();
	~Stack();
private:
	Node* StackPointer;
    //	Node* previous;
};

// full method definitions for class Stack

Stack::Stack()
{
	// StackPointer = previous = NULL;
	StackPointer = NULL;
}

void Stack::Push(string A)
{
	if (StackPointer == NULL)
	{  // create first Node on the Stack
		StackPointer = new Node(A);
	}
	else
	{
        Node* nodePtr = new Node(A); // create all successive nodes
        nodePtr->putNextPtr (StackPointer); // tie new node into the stack
        StackPointer = nodePtr;
	}
}

string Stack::Peek()
{	string myData = "";
	if (StackPointer != NULL)
		myData = StackPointer->getData();
	return myData;
}

string Stack::Pop()
{	string myData = "";
	if (StackPointer != NULL)
	{
		Node* nodePtr = StackPointer;
		StackPointer = StackPointer->getNextPtr();
		myData = nodePtr->getData();
		delete nodePtr;
		nodePtr = NULL;
	}
	return myData;
}

Stack::~Stack ()
{	Node* nodePtr = StackPointer;
	int ct = 0;
	if (nodePtr != NULL)
		while (nodePtr)
		{	Node* temp = nodePtr;
			nodePtr = nodePtr->getNextPtr();
			delete temp;
			ct++;
		}
	cout << "Number of Stack entries deleted is " << ct << endl;
    
}

int main()
{
	string userData;
    string expression;
	Stack myStack;
	cout << "Welcome to the Stack program." << endl;
    cout << "Enter a syntax formula with operand and oprator to form a expression: " << endl;
    int partCount = 0;
	while (!cin.eof())
	{
        //cout << "Press 1 to Push, 2 to Pop, 3 to Peek, ^z to end" << endl;
        cout << "Press Ctrl + z, Ctrl + d to end input";
		cin >> expression;
		if (!cin.eof()&& cin.good()) {
            myStack.Push(expression);
            partCount++;
            /*
            
            
            int strLen = (int)expression.length();
            int oprators[strLen], opratorPositions[strLen], opratorCount = 0;
            char *exp=new char[strLen];
            exp = (char*)expression.c_str();
            // Find out oprator position
            for(int i = 0; i < strLen; i++) {
                //myStack.Push((string)exp[i]);
                switch (exp[i]) {
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                        case '%':
                        case '=':
                            oprators[opratorCount] = exp[i];
                            opratorPositions[opratorCount] = i;
                            opratorCount++;
                            break;
                }
                
                cout << "Index: " << i << ", value: " << exp[i] << endl;;
            }
            
            for(int i = 0; i < opratorCount; i++) {
                cout << "Index: " << i << " at position: " << opratorPositions[i] << " is: " << oprators[i] << endl;
            }
//            cout << strLen << endl;
            cout << exp << endl;
             */
        }

	}
    string result = "";
    cout << "The stack contants " << partCount << " elements." << endl;
    for(int i = 0; i < partCount; i++) {
        string element = myStack.Peek();
        cout << "The " << i << "th element is :";
        result.append(element);
        cout << element << endl;
        myStack.Pop();
    }
    cout << "The reversed syntax is: " << result << endl;
    cout << "\n\n***Thank You For Using My Stack ***\n\n";
    return 0;
}




