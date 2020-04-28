#include <iostream>
using namespace std;

int main() {  
    int arr[20];    // static array of 20 ints  
    for (int i = 0; i < 20; ++i) {    
        arr[i] = 3 * i - 8;  
    }  
    for (int i = -5; i <= 25; ++i) {    
        cout << arr[i] << " ";  
    }  
    cout << endl;  
    return 0;
}