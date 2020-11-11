#ifndef TIEMPO_H
#define TIEMPO_H
#include <ctime>
#include <iostream>
#include "estado.h"
#include "menu.h"
#include <chrono>
#include <thread>


class Tiempo {

  private:
    int hora;
    int progresoSegundos;
    time_t tiempoInicial;
    time_t tiempoActual;
    time_t tiempoAnterior;
  public:
    Tiempo();
    ~Tiempo();
    void correTiempo();
    void ocultarCursor();
    void _sleep();
    void gotoxy(int, int);
};
#endif
