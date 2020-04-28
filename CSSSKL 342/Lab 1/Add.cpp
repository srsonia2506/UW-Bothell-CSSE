#include<iostream>
using namespace std;

int add(int a,int b) {
	return a + b;
}

int main() {
	int x; //first number
	int y; //second number
	cout << "Add two numbers" << endl << endl;
	cout << "Please input first number  ";
	cin >> x;
	cout << "Please input second number ";
	cin >> y;
	int z = add(x, y);
	cout << "Their sum is " << z << endl;
	return 0;
}