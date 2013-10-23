//
//  CS341-midterm-03
//
//  Created by Jason Lu on 10/22/13.
//  Copyright (c) 2013 Lu Jason. All rights reserved.
//  Double link list app
//  1) Introducing delete method
//  2) Link deleted element to the last
//
// Author: John Maslanka
// Date:   26-Jan-2002;
// A simple queue class using a linked list of queue
// objects to illustrate FIFO (first-in-first-out)
// behavior.
// Installation: Home PC with MicroSoft Visual C++ V6.0
//
// Edit:	8-Mar-2004 removed cout << from Serve method
// Edit:	02/20/2012 change user data type from char to string, change menu
//			to all letters.
// Edit:	02/20/2012 insert container class Queue

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

// #include "Node.h"
class Node {  // Definition of a Node on the Queue
public:
    Node () {}						// default constructor
    Node* Admit (Node*, string);    // add a Node to the end of the Queue
    Node* Serve (Node*);            // remove a Node from the front of the Queue
    string Peek ();                 // get user from front node in Queue
    Node* getNextPointer ();        // get pointer to next Entrant back in Queue
    
    
    // Added by Jason, for remove node logic.
    Node* getPriorPointer ();       // get pointer to prior Entrant
    Node* setNextPointer ( Node* );        // get pointer to next Entrant back in Queue
    Node* setPriorPointer ( Node* );       // get pointer to prior Entrant
    Node* backToTheQueue (Node*);   // Back to the queue
    // End of Jason's code.
    
    string getNodeData ();          // return user data from current Entrant
private:
    string item;    // user data
    // following are the two pointers
    Node* prior; // the one ahead of you in the line
    Node* next;  // the one behind you in the line
};

// #include "Node.cpp"
Node* Node::Admit (Node* endPtr, string a) {
    Node* temp = NULL;
    if (temp = new Node) {
        temp->item = a;
        temp->next = NULL;
        temp->prior = endPtr;
        if ( endPtr != NULL) {
            endPtr->next = temp;
        }
    }
    else
		cout << "Dynamic memory exhausted" << endl;
    return temp;
}

Node* Node::Serve (Node* y) {
    Node* temp;
    temp = y->next;
    delete y;
    if (temp != NULL)
		temp->prior = NULL;
    return temp;
}

string Node::Peek ()  // like Stack Peek but peek front
{ return item; }

Node* Node::getNextPointer ()
{ return next; }

string Node::getNodeData ()
{ return item; }


// Added by Jason, for remove node logic.
Node* Node::backToTheQueue (Node* endPtr) {
    Node *a = this;
    a->next = NULL;
    a->prior = endPtr;
    if ( endPtr != NULL) {
        endPtr->next = a;
    }
    return a;
}

Node* Node::getPriorPointer()
{ return prior; }

Node* Node::setNextPointer ( Node* value)
{ this->next = value; return this; }

Node* Node::setPriorPointer( Node* value)
{ this->prior = value; return this; }
// End of Jason's code.



// #include "Queue.h"

class Queue {
public:
	Queue ();
	bool admitEntrant (string);
	void serveSeniorEntrant ();
	string peekSeniorEntrant ();
	void dumpQueueFromFront ();
    bool exists(string);
    bool leave(string);
    Node* removeEntrant(int index);
private:
	Node* front;  // the one about to be served at the front of the line - head
	Node* end;    // the one at the end of the line - tail
	bool  peekFlag;  //check if Senior entrant is peeked befor being served
};


Queue::Queue() {
    front = end = NULL;
    peekFlag = false;
}

bool Queue::admitEntrant ( string x ) {
    bool admitSuccess = false;
    Node A;
    end = A.Admit (end, x);
    if (end != NULL)
    { if (front == NULL)
        front = end;
        admitSuccess = true;
    }
    return admitSuccess;
}

// Added by Jason, leave queue logic.
bool Queue::exists (string x) {
    Node *node = front;
    while(node != end) {
        if(node->getNodeData() == x) {
            return true;
        }
        node = node->getNextPointer();
    }
    return false;
}

bool Queue::leave(string x) {
    Node *node = front;
    // If x is the first of queue.
    if(node->getNodeData() == x) {
        return false;
    }
    
    while(node != end) {
        node = node->getNextPointer();
        if(node->getNodeData() == x) {
            break;
        }
    }
    
    if(node == end) {
        // If the last one lefe the queue, nothing happedn, order will not changed.
        return true;
    }
    
    Node *leaving = node;
    Node *previous = node->getPriorPointer();
    Node *next = node->getNextPointer();
    previous->setNextPointer(next);
    next->setPriorPointer(previous);
    node->backToTheQueue(end);
    return true;
}

// End of Jason's code

Node* Queue::removeEntrant(int index) {
    Node node;
    return &node;
}

string Queue::peekSeniorEntrant () {
    peekFlag = true;
    string returnValue = "";
    if (front != NULL) {
        returnValue = front-> Peek ();
    }
    else {
        peekFlag = false;
        cout << "Queue is empty." << endl;
    }
    return returnValue;
}

void Queue::serveSeniorEntrant () {
    Node A;
    if (peekFlag == true)
		if (front != NULL)
            front = A.Serve (front);
		else
            cout << "Queue is empty." << endl;
        else
            cout << "Senior Queue Member has not been Peeked." << endl;
    peekFlag = false;
}

void Queue::dumpQueueFromFront () {
    if (front != NULL) {
        cout << " Dumping Queue from most senior to most junior..." << endl;
        Node* temp;
        for (temp = front; temp != NULL; temp = temp -> getNextPointer ()) {
            cout << "  " << temp -> getNodeData () << endl;
        }
    } else {
        cout << "Queue is empty." << endl;
    }
}

int main () {
    Queue Q;
    char resp = ' ';
    string cval;
    cout << "Actions: Admit, Serve, Peek, Report, Leave, "
    << " Help, Quit or ^Z" << endl;
    while (!cin.eof() && resp != 'Q' && resp != 'q') {
        cout << "Enter action selection: ";
        cin >> resp;
        if (!cin.eof())
        {
            switch (resp) {
                case 'A': case 'a': // Admit
                    cout << "Enter name to enter into Node: ";
                    cin >> cval;
                    if (!cin.eof())
                    { if ( Q.admitEntrant (cval) )
                        cout << "Added entrant " << cval << " to list." << endl;
                    else
                        cout << "Failed to add entrant " << cval << " to list." << endl;
                    }
                    break;
                // Added by Jason, leave queue logic.
                case 'L': case 'l': // Leave
                    cout << "Enter name to leave from queue: ";
                    cin >> cval;
                    if (!cin.eof()) {
                        if(!Q.exists( cval )) {
                            cout << "There's no one names "<< cval << " in the queue." << endl;
                        } else if ( Q.leave (cval) )
                            cout << cval<< " was left the queue and return to the end of list." << endl;
                        else
                            cout << cval<< " can not leave queue because he is being searved." << endl;
                    }
                    break;
                // End of Jason's code.
                case 'S': case 's': // Serve
                    Q.serveSeniorEntrant ();
                    break;
                case 'P': case 'p': // Peek
                    cout << Q.peekSeniorEntrant () << endl;
                    break;
                case 'R': case 'r':
                    Q.dumpQueueFromFront();
                    break;
                case 'h': case 'H':
                    cout << "Actions: Admit, Serve, Peek, Report, Leave, "
                    << " Help, Quit or ^Z" << endl;
                    break;
                case 'Q': case 'q':
                    break;
                default:
                    cout << " Invalid Action. Try again." << endl;
            }
            cin.clear();
        }
    }
    cout << "Thank you for using my Queue program." << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
