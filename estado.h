#ifndef ESTADO_H
#define ESTADO_H
#include <vector>
#include <iostream>
#include "cuarto.h"
using namespace std;
class Estado {
  private:
  int  hambre ;
  int  suciedad;
  int  cansancio;
  int totalAlimentacion;
  int totalLimpieza;
  int totalCansancio;
  bool espera;
  public:
    Estado();
    ~Estado();
    void mejorarEstado(string);
    void mejorarEstado();
    void aumentaHambre();
    void aumentaSuciedad();
    void aumentaCansancio();
    int obtieneTotalAlimentacion();
    int obtieneTotalLimpieza();
    int obtieneTotalCansancio();
    int obtieneHambreActual();
    int obtieneSuciedadActual();
    int obtieneCansancioActual();
};
#endif
