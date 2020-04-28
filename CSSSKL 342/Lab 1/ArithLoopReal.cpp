#include <iostream>
using namespace std;

void add(double a, double b) {
    cout << "Their sum is " << a + b << endl;
}

void subtract(double a, double b) {
    cout << "Result from subtraction (b - a) is " << b - a << endl;
}

void multiply(double a, double b) {
    cout << "Result from multiplication is " << a * b << endl;
}

void division(double a, double b) {
    cout << "Result from division (b / a) is " << b / a << endl;
}

int main() {
    double x, y;
    char a, b;

    do {
        //input of numbers
        cout << "Add two numbers" << endl << endl;
        cout << "Please input first number  ";
        cin >> x;
        cout << "Please input second number ";
        cin >> y;

        //input of operations
        cout << "What operation would you like to do?" << endl;
        cout << "Denote addition with a" << endl;
        cout << "Denote subtraction with s" << endl;
        cout << "Denote multiplication with m" << endl;
        cout << "Denote division with d" << endl;
        cin >> a;

        //operations
        //assumed valid inputs only
        if (a == 'a') {
            add(x, y);
        }
        else if (a == 's') {
            subtract(x, y);
        }
        else if (a == 'm') {
            multiply(x, y);
        }
        else if (a == 'd') {
            division(x, y);
        }

        //to continue or not
        cout << "Would you like to continue? Y/N ";
        cin >> b;
        cout << endl;
    } while (b == 'y');

    return 0;
}