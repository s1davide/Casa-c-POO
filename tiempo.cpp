#include "tiempo.h"
#include "menu.h"
#include <iostream>
#include <thread>
#include <unistd.h>
#include <term.h>

#ifdef _WIN32
  #include<windows.h>
#else
  #include "keys.h"
#endif  
using namespace std;

Tiempo::Tiempo(){
  this -> hora = 23;
}
Tiempo::~Tiempo(){}
void Tiempo::correTiempo(){
  Menu menu;  
  menu.limpiarPantalla();
  int teclaEnter;
  int kbh;     
  do{menu.pantallaInicial();  
   teclaEnter = menu.comprobar();
   menu.limpiarPantalla();   
   }while(teclaEnter!=13);
  menu.limpiarPantalla();
  int suma= 0;  
  int horaActual= 8;    
  Estado instanciaEstado;

  menu.gotoxy(20, 5);
  if (hora<10){
      cout<<"0";
  }
  cout<<hora<<":"<<0;
  cout<<0<<"\n";
  menu.salida(instanciaEstado);  
  while(true){     
    menu.gotoxy(20, 3);
      cout<<"Casa";
    menu.gotoxy(20, 5);        
      if(horaActual<10){
        cout<<"0"   ;  
      }
      cout<<horaActual<<":"   ;
      if (suma<10){
        cout<<"0"   ;  
      }
       cout<<suma<<"\n"   ;
      if(suma>59){
        horaActual+=1;
        suma=0;
        instanciaEstado.aumentaHambre();
        instanciaEstado.aumentaSuciedad();
        instanciaEstado.aumentaCansancio();
      }
      else{
        suma+=1;               
      }      
      if(horaActual>23){
        horaActual=0;
      }                
      _sleep();
      //menu.limpiarPantalla();
      cout<<progresoSegundos << "\n";  
    
    #ifdef _WIN32

    #else        
        kbh = _kbhit();               
    #endif     
    if(kbh){              
    menu.accion(menu.comprobar(), instanciaEstado);      
    }  
  vector <string> resultadoSalida;
  resultadoSalida =  menu.salida(instanciaEstado);  
  if(resultadoSalida[0]!="NA" && resultadoSalida[1]!="terminar"){     
     instanciaEstado.mejorarEstado( resultadoSalida[0]);
     
  } 
   else if(resultadoSalida[1]=="terminar"){
     break;
   }
  }
}

void Tiempo::_sleep(){
  #ifdef _WIN32
        
  #else
    this_thread::sleep_for(chrono::milliseconds(15));
  #endif            
}
