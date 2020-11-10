#include "estado.h"
using namespace std;
Estado::Estado(){
  this-> hambre =0;
  this-> suciedad = 4;
  this-> cansancio = 2;
  this-> totalAlimentacion = 10;
  this-> totalLimpieza = 10;
  this-> totalCansancio =10;
}
Estado::~Estado(){

}
/*void Estado::alimentarse() {
  hambre-=totalAlimentacion;
} 
void Estado::tomarBano() {
  suciedad-=totalLimpieza;
} 
void Estado::descansar() {
  cansancio-=totalCansancio;
}*/
void Estado::mejorarEstado(string accionMejora){
    
  if(accionMejora=="comer"){
    if(hambre>0){
      if(hambre-totalAlimentacion<-3){
        hambre = -3;
    } else{
        hambre-=totalAlimentacion;
      }
    }
  }
  else if(accionMejora=="ducha"){    
    if(suciedad>0){
    if(suciedad-totalLimpieza<-3){
        suciedad = -3;
    } 
    else{
      suciedad-=totalLimpieza;
    }         
    }
  }
  else if(accionMejora=="dormir"){
    if(cansancio>0){
      if(cansancio-totalCansancio<-3){
        cansancio = -3;
      } 
      else{
        cansancio-=totalCansancio;
      }
    }
  }
}

void Estado::aumentaHambre() {
  hambre+=1;
}
void Estado::aumentaSuciedad() {
  suciedad+=1;
}
void Estado::aumentaCansancio() {
  cansancio+=1;
}

int Estado::obtieneTotalAlimentacion(){  
  return totalAlimentacion;
};
int Estado::obtieneTotalLimpieza(){
  return totalLimpieza;
};
int Estado::obtieneTotalCansancio(){  
  return totalCansancio;
};

int Estado::obtieneHambreActual(){
  int resultado;
  if(hambre<0){
    resultado = 0;
  }
  else{
    resultado = hambre;
  }  
  return resultado;
};
int Estado::obtieneSuciedadActual(){
  int resultado;
  if(suciedad<0){
    resultado = 0;
  }
  else{
    resultado = suciedad;
  }     
  return resultado;
};
int Estado::obtieneCansancioActual(){  
  int resultado;
  if(cansancio<0){
    resultado = 0;
  }
  else{
    resultado = cansancio;
  }  
  return resultado;
};
