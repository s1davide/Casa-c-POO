#ifndef DORMITORIO_H
#define DORMITORIO_H
#include <string>
#include <iostream>
#include "cuarto.h"
using namespace std;
class Dormitorio: public virtual Cuarto {
  private:      
  public:
    Dormitorio();
    ~Dormitorio();        
    
};
#endif