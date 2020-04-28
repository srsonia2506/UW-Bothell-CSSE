#include <iostream>
#include <string>


using namespace std;
class Book {
private:
  string title;
  float price;
public:
  Book(string t, float p) { title = t; price = p; }
  void show() { cout << title << ", $" << price << endl; }
};

Book* myHeapVariables() {
    int* ptr = new int;
    *ptr = 3;
    float* p = new float;
    *p = 2.3;
    string* q = new string;
    *q = "hello";
    Book* dickens = new Book("A Tale of Two Cities", 3.42);
    return dickens;
}
void myStackVariables() {
    int a = 3;
    float b = 2.3;
    string greet = "hello";
    Book dickens("A Tale of Two Cities", 3.42);
}

int main() {
    Book* pb = myHeapVariables();
    myStackVariables();
    //pb->show();
    //dickens->show();
    return 0;
}