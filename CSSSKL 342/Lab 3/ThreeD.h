#include <iostream>
#include <cmath>
using namespace std;

template<typename T> class ThreeD {
public:
    ThreeD() {}
    ThreeD(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
    double radius() {
        double rad = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        return rad;
    }
    void say() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
private:
    T x;
    T y;
    T z;
};