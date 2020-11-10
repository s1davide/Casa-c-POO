#ifndef PATIO_H
#define PATIO_H
#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Patio {

  private:
    vector<string>opciones;
    vector <string> respuesta;
  public:
    Patio();
    ~Patio();    
    string accion(int);
    vector<string> getOpciones(); 
               
};
#endif