#include "patio.h"
using namespace std;
Patio::Patio(){
   this -> opciones.push_back
   ("Entrar a la casa") ;  
   this-> respuesta.push_back("sala");
}
Patio::~Patio(){

}
string Patio::accion(int a){
  string resultado = respuesta[a];  
  return resultado;
}
vector<string> Patio::getOpciones(){    
  return opciones;
}
