#include "sala.h"

using namespace std;
Sala::Sala(){
   setOpciones("Entrar a dormitorio");
   setOpciones("Entrar a la cocina");   
   setOpciones("Entrar al baño");   
   setOpciones("Salir de la casa");
   setAccion("dormitorio");
   setAccion("cocina");
   setAccion("baño");
   setAccion("patio");

}
Sala::~Sala(){

}
