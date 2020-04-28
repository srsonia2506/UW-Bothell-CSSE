#include <iostream>
using namespace std;

void divrem(int divisor, int dividend, int& quotient, int& rem) {
    quotient = dividend / divisor;
    rem = dividend % divisor;
}

int main() {
    int x, y, quotient, rem;

    //input of numbers
    cout << "When 6 is divided by 2, 6 is dividend and 2 is divisor." << endl;
    cout << "Please input dividend ";
    cin >> x;
    cout << "Please input divisor ";
    cin >> y;

    //div function - pass by ref 
    cout << "Before function - quotient = " << quotient << "  rem = " << rem << endl;
    divrem(y, x, quotient, rem);
    cout << "After function - quotient = " << quotient << "  rem = " << rem << endl;

    return 0;
}