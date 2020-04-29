#include "intset.h"

// ---------------------------------------------------------------------------
// Copy Constructor 
// Copy constructor for class IntSet
IntSet::IntSet(const IntSet& a) {
    copy(a);
}

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class IntSet
IntSet::IntSet(int a, int b, int c, int d, int e) {
    int highest = 0;
    int sortArr[5] = { a,b,c,d,e };
    for (int i = 0; i < 5;i++) {
        if (sortArr[i] > highest) highest = sortArr[i];
    }
    if (highest < 0 ) highest = 0;
    size = highest+1;
    ptrArr = new bool[size];
    for (int i = 0; i < size; i++) {
        ptrArr[i] = false;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < size; j++) {
            if (j==sortArr[i]) ptrArr[j] = true;
        }
    }
}

// ---------------------------------------------------------------------------
// Destructor 
// Destructor for the class IntSet
IntSet::~IntSet() {
    delete[] ptrArr;
    ptrArr = NULL;
}

// ---------------------------------------------------------------------------
// Copy
// Destructor for the class IntSet
void IntSet:: copy(const IntSet& a) {
    size = a.size;
    ptrArr = new bool[size];

    for (int i = 0; i < size; i++) {
        ptrArr[i] = a.ptrArr[i];
    }
}

// arithmetic operators
IntSet IntSet:: operator+(const IntSet& a) const {
    IntSet unions = *this;
    for (int i = 0; i < a.size;i++) {
        if (a.ptrArr[i]==true) {
            //unions.ptrArr[i] = true;
            unions.insert(i);
        }
    }
    return unions;
}

// difference operator
// returns the difference of two sets aay A-B, which is the set of all
// elements that are in set A but not in Set B.

IntSet IntSet::operator-(const IntSet& a) const {
    IntSet diff;
    int tempsize;
    if (size<a.size) {
        tempsize = diff.size;
    }
    else {
        tempsize = a.size;
    }
    for (int i = 0; i < tempsize; i++) {
        if (ptrArr[i] == true && a.ptrArr[i] == false) {
            diff.insert(i);
            //diff.ptrArr[i] = true;
        }
    }
    /*
    for (int i = 0; i < a.size; i++) {
        if (a.ptrArr[i] == true){
            if (!a.ptrArr[i] == true){
                diff.remove(i);
            }
        }
    }
    */
    
    return diff;
}

IntSet IntSet:: operator*(const IntSet& a) const {
    IntSet b = *this;
    for (int i = 0; i < a.size;i++) {
        if (a.ptrArr[i] == true && this->ptrArr[i] == true) b.insert(i);
        if (a.ptrArr[i] == true) b.remove(i);
    }
    return b;
}

IntSet IntSet:: operator=(const IntSet& right) {
    if (&right != this) {                    
        delete[] ptrArr;                   
        copy(right);
    }
    return *this;                           
}

// boolean comparison operators
IntSet IntSet:: operator+=(const IntSet& a) {
    return *this = *this + a;
}

IntSet IntSet:: operator-=(const IntSet& a) {
    return *this = *this - a;
}

IntSet IntSet::  operator*=(const IntSet& a) {
    return *this = *this * a;
}

// The assignment operator to assign one set to another
bool IntSet::operator==(const IntSet& a) const {
    if(this-> size != a.size) {
        return false;
    }
    for (int i = 0; i < a.size; i++) {
        if (a.ptrArr[i] != this->ptrArr[i]) {
            return false;
        }
    }
    return true;
}

// not equal operator
// The assignment operator to assigne one set to another
bool IntSet::operator!=(const IntSet& a) const {
    /*
    if (this->size != a.size) {
        return false;
    }
    for (int i = 0; i < a.size; i++) {
        if (a.ptrArr[i] != this->ptrArr[i]) {
            return true;
        }
    }
    */
    int lowSize = (a.size > size) ? size : a.size;
    for (int i = 0; i < lowSize; i++) {
        if (ptrArr[i] != a.ptrArr[i]) {
            return true;
        }
    }
    return false;
}

// << operator
// overloaded output operator for class IntSet
ostream& operator << (ostream& output, const IntSet& a) {
    if (a.isEmpty()) {
    }
    else {
        output << "{";
        for (int i = 0; i < a.size; i++) {
            if (a.ptrArr[i] == true) output << i << " ";
        }
        output << "}";
    }
    return output;
}

istream& operator>>(istream& input, IntSet& a) {
    int in;
    for (int i = 0; i < a.size; i){
        input >> in;
        a.insert(in);
        if (in < 0) break;
    }
    return input;  
}

bool IntSet:: remove(int a) {
    if (a < 0 || a > size) {
        return false;
    }
    ptrArr[a]=false;
    return true;
}

// ---------------------------------------------------------------------------
// insert
bool IntSet:: insert(int a) {
    if (a < 0) { 
        return false; 
    } else if (a < size) {
        ptrArr[a] = true;
        return true;
    } else {
        bool* temp = ptrArr;
        ptrArr = new bool[a + 1];
        for (int i = 0; i < size;i++) {
            ptrArr[i] = temp[i];
        }
        size = a + 1;
        ptrArr[a] = true;
        delete []temp;
        return true;
    }
    return true;
}

// ---------------------------------------------------------------------------
// isInSet
// checks if valid
bool IntSet:: isInSet(int a) const {
    if (a < 0 || a > size) {
        return false;
    }
    return ptrArr[a];
}

// ---------------------------------------------------------------------------
// Empty
// checks if empty
bool IntSet:: isEmpty() const {
    return size==0;
}
