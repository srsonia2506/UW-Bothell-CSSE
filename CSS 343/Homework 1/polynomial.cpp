#include "polynomial.h"

ostream& operator<<(ostream& output, const Polynomial& p){
    Polynomial::Term* curr = p.head;
    while (curr!=nullptr) {
        output << to_string(curr->coeff)
            << "x"
            << to_string(curr->power)
            << " + ";
    }
    return output;
}

//-----------------------------------------------------------------------------
// Constructor
Polynomial::Polynomial(){
    size = 0;
    head = new Term;
    head->next = head;
    head->prev = head;
}

//-----------------------------------------------------------------------------
// Copy constructor
Polynomial::Polynomial(const Polynomial& p){
}

//-----------------------------------------------------------------------------
// sortInput
// reads and sorts data in students arr by last name using insertion sort
// students with invalid scores ie below 0 or above 100 ignored
Polynomial::~Polynomial(){
}

//-----------------------------------------------------------------------------
// Degree Getter
// returns the degree of a polynomial
int Polynomial::degree() const{
    return head->power;
}

//-----------------------------------------------------------------------------
// Coefficient Getter
// Returns the coefficient of the x^power term.
double Polynomial::coefficient(const int power) const{
    return head->coeff;
}

//-----------------------------------------------------------------------------
// sortInput
// reads and sorts data in students arr by last name using insertion sort
// students with invalid scores ie below 0 or above 100 ignored
bool Polynomial::changeCoefficient(const double newCoefficient, const int power){
    return false;
}

//-----------------------------------------------------------------------------
// sortInput
// reads and sorts data in students arr by last name using insertion sort
// students with invalid scores ie below 0 or above 100 ignored
Polynomial Polynomial::operator+(const Polynomial& p) const{
    return Polynomial();
}

//-----------------------------------------------------------------------------
// sortInput
// reads and sorts data in students arr by last name using insertion sort
// students with invalid scores ie below 0 or above 100 ignored
Polynomial Polynomial::operator-(const Polynomial& p) const{
    return Polynomial();
}

//-----------------------------------------------------------------------------
// sortInput
// reads and sorts data in students arr by last name using insertion sort
// students with invalid scores ie below 0 or above 100 ignored
bool Polynomial::operator==(const Polynomial& p) const{
    return false;
}

//-----------------------------------------------------------------------------
// sortInput
// reads and sorts data in students arr by last name using insertion sort
// students with invalid scores ie below 0 or above 100 ignored
bool Polynomial::operator!=(const Polynomial& p) const{
    return false;
}

//-----------------------------------------------------------------------------
// Overloaded Equals
Polynomial& Polynomial::operator=(const Polynomial& p){

}

//-----------------------------------------------------------------------------
// sortInput
// reads and sorts data in students arr by last name using insertion sort
// students with invalid scores ie below 0 or above 100 ignored
Polynomial& Polynomial::operator+=(const Polynomial& p){
    // TODO: insert return statement here
}

//-----------------------------------------------------------------------------
// sortInput
// reads and sorts data in students arr by last name using insertion sort
// students with invalid scores ie below 0 or above 100 ignored
Polynomial& Polynomial::operator-=(const Polynomial& p){
    // TODO: insert return statement here
}

//-----------------------------------------------------------------------------
// sortInput
// reads and sorts data in students arr by last name using insertion sort
// students with invalid scores ie below 0 or above 100 ignored
bool Polynomial::insert(Term* pos, const double newCoefficient, const int power){
    return false;
}

//-----------------------------------------------------------------------------
// sortInput
// reads and sorts data in students arr by last name using insertion sort
// students with invalid scores ie below 0 or above 100 ignored
bool Polynomial::remove(Term* pos){
    Term* np = pos;
    while (np->next != nullptr) {
        cout << np->coeff << " + ";
        np = np->next;
    }
}
