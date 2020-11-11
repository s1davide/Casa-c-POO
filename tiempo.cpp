#include "tiempo.h"
#include "menu.h"
#include <iostream>
#include <unistd.h>
#ifdef _WIN32
  #include<windows.h>
  #include <conio.h>
  #include <stdio.h>
#else
  #include "keys.h"
#endif


using namespace std;

Tiempo::Tiempo(){
  this -> hora = 23;
}
Tiempo::~Tiempo(){}
void Tiempo::correTiempo(){
  ocultarCursor();
  Menu menu;
  menu.limpiarPantalla();
  int teclaEnter;
  int kbh;
  do{

   menu.limpiarPantalla();
   menu.pantallaInicial();
   //menu.gotoxy(1,1);
   //cout<<getch();;
   teclaEnter = menu.comprobar();
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
  menu.salidaMenu();
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
        menu.limpiarPantalla();
        instanciaEstado.aumentaHambre();
        instanciaEstado.aumentaSuciedad();
        instanciaEstado.aumentaCansancio();
        menu.salida(instanciaEstado);
        menu.salidaMenu();
      }
      else{
        suma+=1;
      }
      if(horaActual>23){
        horaActual=0;
      }
      _sleep();
    #ifdef _WIN32
        kbh = kbhit();
    #else
        kbh = _kbhit();
    #endif
    vector <string> estadoJuego;
    estadoJuego.push_back("NA");
    estadoJuego.push_back("continuar");
    if(kbh){
    menu.accion(menu.comprobar(), instanciaEstado);
    }
    estadoJuego = menu.estadoJuego();
  if(estadoJuego [0]!="NA" && estadoJuego [1]!="terminar"){
     instanciaEstado.mejorarEstado( estadoJuego [0]);
     if(estadoJuego [0]!="NA"){
        menu.salida(instanciaEstado);
     }
  }
   else if(estadoJuego [1]=="terminar"){
     break;
   }
  }
}

void Tiempo::_sleep(){
  #ifdef _WIN32
    Sleep(3);
  #else
    this_thread::sleep_for(chrono::milliseconds(8));
  #endif
}
void Tiempo::ocultarCursor(){
    #ifdef _WIN32
      HANDLE consola;
      consola = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_CURSOR_INFO cci;
      cci.dwSize = 1;
      cci.bVisible = FALSE;
      SetConsoleCursorInfo(consola, &cci);
    #else
      system("tput civis");
    #endif
}
