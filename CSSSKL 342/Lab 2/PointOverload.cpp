#include <iostream>
using namespace std;
class Point{
private:
  int x, y;
public:
  Point(int xx, int yy) { x = xx; y = yy; }
  Point operator+(Point& q) { return Point(x + q.x, y + q.y); }
  Point operator-(Point& q) { return Point(x - q.x, y - q.y); }
  bool operator==(Point& q) { return (x == q.x, y == q.y); }
  bool operator<(Point& q) { return (x < q.x, y < q.y); }
  void show() { cout << "(" << x << ", " << y << ")" << endl; }
};

int main() {
    Point p(1, 2);
    p.show();
    Point q(2, 3);
    q.show();
    Point a = p + q;
    a.show();
    Point b = p - q;
    b.show();
    (p == q) ? "Equal" : "Not Equal";
    (p < q) ? "Less than" : "Not lesser than";
    return 0;
}

