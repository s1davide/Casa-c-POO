#include "cuarto.h"

using namespace std;
Cuarto::Cuarto(){
  
}
Cuarto::~Cuarto(){

}
string Cuarto::getAccion(int a){
  string res;
  res = acciones[a];  
  return res;
}
vector <string> Cuarto::getOpciones(){
return opciones;
}
void Cuarto::setOpciones(string opt){    
  this->opciones.push_back(opt);
}
void Cuarto::setAccion(string res){    
  this->acciones.push_back(res);
}