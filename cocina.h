#ifndef COCINA_H
#define COCINA_H
#include <vector>
#include <iostream>
#include "cuarto.h"
using namespace std;
class Cocina: public virtual Cuarto {
  private:    
  public:
    Cocina();
    ~Cocina();        
};
#endif