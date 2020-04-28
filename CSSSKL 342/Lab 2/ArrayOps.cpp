#include <iostream>
#include <cstdlib>
using namespace std;

double fRand(double, double);

int main() {
    int arr[10];    // static array of 10 ints
 
    for (int i = 0; i < 10; i++) {
        arr[i] = fRand(1.0, 100.0);
    }

    int max, min=arr[0], sum = arr[0];

    for (int i = 0; i < 10; ++i) {
        sum += arr[i];
        if (arr[i] < min) { min = arr[i]; }
        if (arr[i] > max) { max = arr[i]; }
    }
    cout << "Average: " << sum/10 << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    return 0;
}

double fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}