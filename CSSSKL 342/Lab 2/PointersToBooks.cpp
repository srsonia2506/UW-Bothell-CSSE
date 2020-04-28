#include <iostream>
using namespace std;

class Book {
private:  
    string title;  
    float  price;
public:  
    string getTitle(){ return title; }  
    float  getPrice(){ return price; }  
    Book(string t, float p) { title = t; price = p; }
};

int main() {  
    Book stroustrup("The C++ Programming Language", 53.99);  
    Book meyers("Effective Modern C++", 42.03);
    Book teenager("Harry Potter", 19.93);

    Book* books[3] = { &stroustrup, &meyers, &teenager };

    for (int i = 0; i < 3; ++i) {
        cout << "Price of " << (*books[i]).getTitle() << " is " << (*books[i]).getPrice() << endl;
    }

    return 0;
}