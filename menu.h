#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <vector>
#include "sala.h"
#include "dormitorio.h"
#include "cocina.h"
#include "bano.h"
#include "patio.h"
#include "estado.h"

using namespace std;

class Menu {
  private:
    int opcion;    
    string ubicacion;    
    vector<string> listaMenu;
    vector<string> acciones;    
    vector<bool>limpiarPantallaBarra;
    Patio lugar2;    
    string accionPendiente;
    
  public:
    Menu();
    ~Menu();
    void inicial();
    int keypress();
    int comprobar();    
    vector <string> salida(Estado);
    void accion(int, Estado);
    void gotoxy(int, int);
    void estableceLugar();
    void limpiarPantalla();
    void limpiarBarra(int, int, int , int);
    int obtenerMenu();
    void limpiarMenu(int);
    void pantallaInicial();
    Cuarto lugar();
    };
#endif