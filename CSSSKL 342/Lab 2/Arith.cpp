#include "Arith.h"

Arith::Arith() { x = 0; }
Arith::Arith(int xx) { x = xx; }
int Arith::add(Arith other) {
    return x + other.x;
}

