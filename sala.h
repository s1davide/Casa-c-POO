#ifndef SALA_H
#define SALA_H
#include <vector>
#include <iostream>
#include "cuarto.h"
using namespace std;
class Sala: public virtual Cuarto {
  private:    
  public:
    Sala();
    ~Sala();        
};
#endif