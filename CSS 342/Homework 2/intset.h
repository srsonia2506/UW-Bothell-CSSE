#ifndef INTSET_H
#define INTSET_H
#include <iostream>
using namespace std;

const int DATA = -1;
const int DEFAULT_SIZE = 1;

//---------------------------------------------------------------------------
// insert purpose of class
//
// Implementation and assumptions:
//   -- fill this up

class IntSet {

    friend ostream& operator<<(ostream&, const IntSet&);
    friend istream& operator>>(istream&, IntSet&);

public:
    // constructor
    IntSet(const IntSet&);
    IntSet(int = DATA, int = DATA, int = DATA, int = DATA, int = DATA);

    //destructor 
    ~IntSet();

    // arithmetic operators
    IntSet operator+(const IntSet&) const;   
    IntSet operator-(const IntSet&) const;   
    IntSet operator*(const IntSet&) const;    
    IntSet operator=(const IntSet&);                                                         

    // boolean comparison operators
    IntSet operator+=(const IntSet&);   
    IntSet operator-=(const IntSet&);
    IntSet operator*=(const IntSet&);
    bool operator==(const IntSet&) const;      
    bool operator!=(const IntSet&) const;      

    bool remove(int);
    bool insert(int);
    bool isInSet(int) const;
    bool isEmpty() const;

private:
    int size;                         
    bool* ptrArr;                      
    void copy(const IntSet&);         
};

#endif