////////////////////////////////  list.h file  ///////////////////////////////
// Simple linked list, uses Node as linked list node

#ifndef LIST_H
#define LIST_H

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
template <typename T>
class List {
    friend ostream& operator<<(ostream& output, const List<T>& thelist){
        typename List<T>::Node* current = thelist.head;
        while (current != NULL) {
            output << *current->data;
            current = current->next;
        }
        return output;
    }

public:
    List();                                     // constructor
    ~List();                                    // destructor
    List(const List&);                          // copy constructor

    // insert one NodeData object, assume parameter points to valid object,
    // return whether successfully inserted
    bool isEmpty() const;
    bool insert(T*);
    // is list empty?
    void buildList(ifstream&);                  // build a list from datafile
    void merge(List<T>, List<T>);
    bool operator==(const List<T>&) const;
    bool operator!=(const List<T>&) const;
    List<T>& operator=(const List<T>&);
    bool retrieve(const T& target, T*& other) const;
    void makeEmpty();
    void intersect(List<T>&, List<T>&);
    void copy(const List<T>&);
    bool remove(const T&, T*&);

    // needs many more member functions to become a complete ADT

private:
    struct Node {             // the node in a linked list
        T* data;        // pointer to actual data, operations in NodeData
        Node* next;
    };

    Node* head;               // pointer to first node in list
};

//----------------------------------------------------------------------------
// Constructor 
template <typename T>
List<T>::List() {
    head = NULL;
}

//----------------------------------------------------------------------------
// Destructor
template<typename T> List<T>::~List() {
    makeEmpty();
}

//----------------------------------------------------------------------------
//Copy constructors
template<typename T>
List<T>::List(const List<T>& cpy) {
    if (cpy.head == nullptr) {
        this->head = nullptr;
    }
    copy(cpy);
}

//----------------------------------------------------------------------------
// Copy
// returns a copy of the given list    
template <typename T>void List<T>::copy(const List<T>& other) {
    if (other.head == NULL) return;
    head = new Node();
    Node* curr = head;
    Node* walker = other.head;
    T* data = new T;
    *data = *walker->data;
    head->data = data;
    walker = walker->next;
    while (walker != nullptr) {
        curr->next = new Node();
        curr = curr->next;
        data = new T;
        *data = *walker->data;
        curr->data = data;
        walker = walker->next;
    }
    curr->next = nullptr;
}

//----------------------------------------------------------------------------
// isEmpty 
// check to see if List is empty as defined by a NULL head
template <typename T>
bool List<T>::isEmpty() const {
    return head == NULL;
}

//----------------------------------------------------------------------------
// insert 
// insert an item into list; operator< of the T class
// has the responsibility for the sorting criteria
template <typename T> bool List<T>::insert(T* dataptr) {

    Node* ptr = new Node;
    if (ptr == NULL) return false;                 // out of memory, bail
    ptr->data = dataptr;                           // link the node to data

    // if the list is empty or if the node should be inserted before 
    // the first node of the list
    if (isEmpty() || *ptr->data < *head->data) {
        ptr->next = head;
        head = ptr;
    }

    // then check the rest of the list until we find where it belongs 
    else {
        Node* current = head->next;          // to walk list
        Node* previous = head;               // to walk list, lags behind

        // walk until end of the list or found position to insert
        while (current != NULL && *current->data < *ptr->data) {
            previous = current;                  // walk to next node
            current = current->next;
        }

        // insert new node, link it in
        ptr->next = current;
        previous->next = ptr;
    }
    return true;
}

//----------------------------------------------------------------------------
// buildList 
// continually insert new items into the list
template <typename T> void List<T>::buildList(ifstream& infile) {
    T* ptr;
    bool successfulRead;                            // read good data
    bool success;                                   // successfully insert
    for (;;) {
        ptr = new T;
        successfulRead = ptr->setData(infile);       // fill the T object
        if (infile.eof()) {
            delete ptr;
            ptr = NULL;
            break;
        }

        // insert good data into the list, otherwise ignore it
        if (successfulRead) {
            success = insert(ptr);
        }
        else {
            delete ptr;
            ptr = NULL;
        }
        if (!success) break;
    }
}

//----------------------------------------------------------------------------
// Merge
// takes 2 sorted lists and merge into one long sorted list
template<typename T> void List<T>::merge(List<T> one, List<T> two) {
    Node* dummy1 = one.head;
    Node* dummy2 = two.head;
    Node* endpoint = nullptr;
    Node* anchor = nullptr;
    if (!one.isEmpty() && !two.isEmpty()) {
        //set to lowest and check for null(set anchor for other one DONE!)
        if (*dummy1->data > *dummy2->data) {
            anchor = dummy2;        //sets anchor
            endpoint = anchor;      //brings endpoint to anchor
            dummy2 = anchor->next;  //moves dummy2 up one
        }
        else {
            anchor = dummy1;        //sets anchor
            endpoint = anchor;
            dummy1 = anchor->next;
        }
        for (;;) {
            if (dummy1 == nullptr || dummy2 == nullptr) {
                break;
            }
            else if (*dummy1->data > *dummy2->data) {
                endpoint->next = dummy2;
                dummy2 = dummy2->next;
                endpoint = endpoint->next;
            }
            else if (*dummy1->data <= *dummy2->data) {
                endpoint->next = dummy1;
                dummy1 = dummy1->next;
                endpoint = endpoint->next;
            }
        }
        //anchor onto bigger one when one nulls
        if (dummy1 == nullptr) {
            anchor->next = dummy2;
        }
        if (dummy2 == nullptr) {
            anchor->next = dummy1;
        }
    }

    //call after making sure 2 isnt merging 2 and 1 into 2
    //(when both parameters are not current object)
    if (this->head != one.head && this->head != two.head) {
        makeEmpty();
    }

    head = anchor;

    //null all dangles
    anchor = nullptr;
    dummy1 = nullptr;
    dummy2 = nullptr;
    endpoint = nullptr;
}

//----------------------------------------------------------------------------
// Operator== 
// Compares two lists -> returns true if the lists hold identical objects
template<typename T> bool List<T>::operator==(const List& comp) const {

    if (head == nullptr && comp.head == nullptr) {
        return true;
    }
    if (head == nullptr || comp.head == nullptr) {
        return false;
    }

    Node* current = head;          
    Node* other = comp.head;      

    while (current != nullptr && other != nullptr) {
        if (current->data != other->data) {
            return false;
        }
        other = other->next;                  
        current = current->next;              
    }
    return true;
}

//----------------------------------------------------------------------------
// Operator!= 
// Compares two lists -> returns true if the lists hold identical objects
template<typename T> bool List<T>::operator!=(const List<T>& comp) const {
    return !(*this == comp);
}

//----------------------------------------------------------------------------
// operator=
// assign one list to another
template<typename T> List<T>& List<T>::operator=(const List<T>& comp) {
    if (comp.head == NULL) {
        this->makeEmpty();
    }
    else if (this->head == comp.head) {
        return *this;
    }
    else {
        makeEmpty();
        copy(comp);
    }
    return *this;
}

//----------------------------------------------------------------------------
// Remove
// Remove first parameter from list and set the second parameter to the 
// Object* from the list if found.
// Return value is whether the removal was successful.
template <typename T> bool List<T>::remove(const T& target, T*& other) {
    Node* current = head;
    Node* previous;
    if (current == NULL) {
        current = nullptr;
        return false;
    }
    if (*current->data == target) {
        current = head;
        head = head->next;
        other = current->data;
        current = nullptr;
        return true;
    }
    while(current != NULL) {
        previous = current;
        if (*current->data == target) {
            other = current->data;
            previous->next = current->next;
            current = nullptr;
            return true;
        }
    }
    other = nullptr;
    return false;
}

//----------------------------------------------------------------------------
// Retrieve
// similar to remove, but not removed from list
template<typename T> bool List<T>::retrieve(const T& target, T*& other) const {
    Node* current = head;  Node* previous;
    if (current == nullptr) {
        other = nullptr;
        return false;
    }
    if (*current->data == target) {
        other = current->data;
        return true;
    }
    while (current != nullptr) {
        previous = current;
        current = current->next;
        if (*current->data == target) {
            other = current->data; 
            return true;
        }
    }
    previous = nullptr;
    other = nullptr;
    return false;
}

//----------------------------------------------------------------------------
// MakeEmpty
// empty out the list, deallocate all memory for all Nodes and each Object
template <typename T>void List<T>::makeEmpty() { 
    Node* current = head;        
    while (head != NULL) { 
        current = head;                
        head = head->next;                
        current->next = nullptr;                
        delete current->data;                
        current->data = nullptr;                
        delete current; 
    }         
    head = nullptr; 
}

//----------------------------------------------------------------------------
// intersect
// takes 2 sorted lists and finds the items in common in both lists
template<typename T> void List<T>::intersect(List<T>& one, List<T>& two) {
    Node* dummy1 = one.head;
    Node* dummy2 = two.head;
    Node* endpoint = nullptr;
    Node* anchor = nullptr;
    if (dummy1 != nullptr && dummy2 != nullptr) {
        //find pairing and set anchor for that
        for (;;) {
            if (dummy1 == nullptr||dummy2 == nullptr) {
                break;
            }
            if (*dummy1->data == *dummy2->data) {
                anchor = dummy1;        //sets anchor
                endpoint = anchor;      //brings endpoint to anchor
                dummy1 = anchor->next;  //moves dummy1 up one
                dummy2 = dummy2->next;  //dummy2 moves up as well
                break;
            }
            //if one is smaller move it up in order to not miss any pairings
            if (*dummy1->data < *dummy2->data) {
                dummy1 = dummy1->next;
            }
            //move two if one is bigger
            else {
                dummy2 = dummy2->next;
            }
        }

        for (;;) {
            if (dummy1 == nullptr || dummy2 == nullptr) {
                break;
            }
            if (*dummy1->data == *dummy2->data) {
                endpoint->next = dummy1;
                dummy1 = dummy1->next;  //moves dummy1 up one
                dummy2 = dummy2->next;  //dummy2 moves up as well
            }
            //if one is smaller move it up in order to not miss any pairings
            else if (*dummy1->data < *dummy2->data) {
                dummy1 = dummy1->next;
            }
            //move two if one is bigger
            else {
                dummy2 = dummy2->next;
            }
        }
    }
    head = anchor;

    //null all dangles
    anchor = nullptr;
    dummy1 = nullptr;
    dummy2 = nullptr;
    endpoint = nullptr;
}

#endif