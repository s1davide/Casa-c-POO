#ifndef CUARTO_H
#define CUARTO_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Cuarto {

  protected:
    vector<string>opciones;
    vector<string>acciones;
  public:
    Cuarto();
    ~Cuarto();    
    void setOpciones(string);
    void setAccion(string);
    vector<string>getOpciones();
    string getAccion(int);            
};
#endif