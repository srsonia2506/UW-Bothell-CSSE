#pragma once
using namespace std;
#include <iostream>

class Rational{
public:
    Rational(int num=1, int denom = 1); //default constructor
    Rational(int num, int denom);

    Rational operator+(Rational other);
    Rational operator-(Rational other);
    Rational operator*(Rational other);
    Rational operator/(Rational other);

    Rational operator+=(Rational);

    bool operator<(Rational);
    bool operator>(Rational);
    bool operator>=(Rational);
    bool operator<=(Rational);
    bool operator==(Rational);
    bool operator!=(Rational);	

private:
    int denom, num;
    Rational reduce();
};

