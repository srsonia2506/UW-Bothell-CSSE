#include "polynomial.h"

ostream& operator<<(ostream& output, const Polynomial& p){
    // TODO: insert return statement here
}

Polynomial::Polynomial(){
}

Polynomial::Polynomial(const Polynomial& p){
}

Polynomial::~Polynomial(){
}

int Polynomial::degree() const{
    return 0;
}

double Polynomial::coefficient(const int power) const{
    return 0.0;
}

bool Polynomial::changeCoefficient(const double newCoefficient, const int power){
    return false;
}

Polynomial Polynomial::operator+(const Polynomial& p) const{
    return Polynomial();
}

Polynomial Polynomial::operator-(const Polynomial& p) const{
    return Polynomial();
}

bool Polynomial::operator==(const Polynomial& p) const{
    return false;
}

bool Polynomial::operator!=(const Polynomial& p) const{
    return false;
}

Polynomial& Polynomial::operator=(const Polynomial& p){
    // TODO: insert return statement here
}

Polynomial& Polynomial::operator+=(const Polynomial& p){
    // TODO: insert return statement here
}

Polynomial& Polynomial::operator-=(const Polynomial& p){
    // TODO: insert return statement here
}

bool Polynomial::insert(Term* pos, const double newCoefficient, const int power){
    return false;
}

bool Polynomial::remove(Term* pos){
    return false;
}
