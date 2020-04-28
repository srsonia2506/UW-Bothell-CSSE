#include <iostream>
#include <cmath> 
using namespace std;

class Point {
private:
    float x, y;
public:
    Point() {}
    Point(float xx, float yy) { x = xx; y = yy; }

    void add(Point& other) {
        x += other.x;
        y += other.y;
    }

    void show() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    int radius() {
        int radius;
        radius = sqrt(x * x + y * y);
        return radius;
    }
};

int main() {
    Point p(3.0, 4.0);
    p.show();
    cout << "Radius of p is " << p.radius() << endl;
    Point q(4.0, 5.0);
    q.show();
    cout << "Radius of q is " << q.radius() << endl;
    p.add(q);
    p.show();
    cout << "Radius of p after adding to q is " << p.radius() << endl;
    return 0;
}
