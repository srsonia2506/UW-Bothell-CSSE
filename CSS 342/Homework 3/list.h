////////////////////////////////  list.h file  ///////////////////////////////
// Simple linked list, uses Node as linked list node

#ifndef LIST_H
#define LIST_H

#include "nodedata.h"
#include <iostream>
#include <fstream>
using namespace std;

//--------------------------  class List  ------------------------------------
// ADT List: finite, ordered collection of zero or more items.
//           The ordering is determined by operator< of NodeData class.
//          
// Implementation and assumptions:  
//   -- Implemented as a linked list.
//   -- There is no dummy head node, head points to first node.  
//      If the list is empty, head is NULL.
//   -- The insert allocates memory for a Node, ptr to the data is passed in.
//      Allocating memory and setting data is the responsibility of the caller.
//   -- Control of <, printing, etc. of NodeData information is in the 
//      NodeData class.  
//
// Note this definition is not a complete class and is not fully documented.
//----------------------------------------------------------------------------
class List {
    friend ostream& operator<<(ostream&, const List&);

public:
    List();                                     // constructor
    // ~List();                                 // destructor
    // List(const List&);                       // copy constructor

    // insert one NodeData object, assume parameter points to valid object,
    // return whether successfully inserted
    bool insert(NodeData*);
    bool isEmpty() const;                       // is list empty?
    void buildList(ifstream&);                  // build a list from datafile

    // needs many more member functions to become a complete ADT

private:
    struct Node {             // the node in a linked list
        NodeData* data;        // pointer to actual data, operations in NodeData
        Node* next;
    };

    Node* head;               // pointer to first node in list
};

#endif
