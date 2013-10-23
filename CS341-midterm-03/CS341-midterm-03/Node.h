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

