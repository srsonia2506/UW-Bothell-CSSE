#pragma once
#ifndef ARITH_H
#define ARITH_H

class Arith{
  public:
    Arith();
    Arith(int xx);
    int add(Arith other);
  private:
    int x;
};

#endif



