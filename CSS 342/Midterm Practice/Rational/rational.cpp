#include "rational.h"
using namespace std;

Rational::Rational(int num, int denom) {
    num= (denom < 0) ? -num : num;
    denom= (denom < 0) ? -denom : denom;
}

Rational Rational::operator+(Rational other){
    Rational f3;
    f3.num = other.denom * num + other.num * denom;
    f3.denom = denom * other.denom;
    return f3.reduce();    
}

Rational Rational::operator-(Rational other){
    Rational f3;
    f3.num = num - other.num;
    f3.denom = denom - other.denom;
    return f3.reduce();
}

Rational Rational::operator*(Rational other){ 
    Rational f3;
    f3.num = num * other.num;
    f3.denom = denom * other.denom;
    return f3.reduce();
}

Rational Rational::operator/(Rational other){
    Rational f3 = Rational(other.denom, other.num);
    return *this * other;
}

bool Rational::operator<(Rational other){
    return (float)numerator / denominator < (float)r.numerator / r.denominator;
}

bool Rational::operator>(Rational other){
    return (float)num/denom> (float)other.numerator / other.denominator;

bool Rational::operator>=(Rational other){
    return *this == other || *this > other;
}

bool Rational::operator<=(Rational other){
    return return return *this == other || *this < other;
}

bool Rational::operator==(Rational other){
    return denom == other.denom && num == other.num;
}

bool Rational::operator!=(Rational other){
    return !(*this == other); 
}

Rational Rational::operator+=(Rational other) {
    return *this + other;
}

ostream operator<<(ostream output, Rational r) {
    if (r.denominator == 0)
        output << endl << "invalid output" << endl;
    else if (r.numerator == 0)                             
        output << 0;
    else if (r.denominator == 1)                            
        output << r.numerator;
    else
        output << r.numerator << "/" << r.denominator;

    return output;
}

istream operator>>(istream input, Rational other) {
    input >> other.numerator >> "/" >> other.denominator;
    return input;
}

Rational Rational::reduce(){
    int factor = gcd(this->num, this->denom);
    return Rational(num / factor, denom / factor);
}

int gcd(int num, int denom){ 
   return (denom == 0)? num : gcd(denom, num % denom);
}