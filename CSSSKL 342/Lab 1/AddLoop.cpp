#include <iostream>
using namespace std;

void add(int a, int b) {
	cout << "Their sum is " << a + b << endl;
}

void input() {
	int x; //first number
	int y; //second number

	cout << "Add two numbers" << endl << endl;
	cout << "Please input first number  ";
	cin >> x;
	cout << "Please input second number ";
	cin >> y;

	add(x, y);
}

int main() {
	char z;

	do {
		input();
		cout << "Would you like to continue? Y/N ";
		cin >> z;
	} while (z == 'y');

	return 0;
}