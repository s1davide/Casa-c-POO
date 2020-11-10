#include "bano.h"
using namespace std;
Bano::Bano(){
   setOpciones("Tomar una ducha");
   setOpciones("Volver a la sala");   
   acciones.push_back("baño, ducha");
   acciones.push_back("sala");   
}
Bano::~Bano(){
  
}