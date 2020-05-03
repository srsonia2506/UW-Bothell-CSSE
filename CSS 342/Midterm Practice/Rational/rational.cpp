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
    return false;
}

bool Rational::operator>(Rational other){
    return false;
}

bool Rational::operator>=(Rational other){
    return false;
}

bool Rational::operator<=(Rational other){
    return false;
}

bool Rational::operator==(Rational other){
    return denom == other.denom && num == other.num;
}

bool Rational::operator!=(Rational other){
    return !(*this == other); 
}

Rational Rational::reduce(){
    int factor = gcd(this->num, this->denom);
    return Rational(num / factor, denom / factor);
}

int gcd(int num, int denom){ 
   return (denom == 0)? num : gcd(denom, num % denom);
}
