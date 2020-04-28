#include <iostream>
using namespace std;

class DynArray {
private:
    double arr[];
    int size;
public:
    DynArray(){
        double* arr = new double[5];
        fill(arr, arr + sizeof(arr), 0.0);
    }
    DynArray(int num) {
        double* arr = new double[num];
        fill(arr, arr + sizeof(arr), 0.0);
    }
    
    void set(int i, double val){
        arr[i] = val;
    }

    double get(int i){
        return arr[i];
    }

    void grow(){
        double* temp = arr;
        size = sizeof(arr);
        int newSize = size * 2;
        arr = new double[newSize];
        for (int i = 0; i < size; i++) { arr[i] = temp[i]; }
    }
};

int main() {
    DynArray p(7);
    DynArray q;

    cout << p.get(5) << q.get(3) << endl;
    q.set(2, 24.5);
    cout << q.get(2) << endl;

    return 0;
}
