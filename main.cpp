#include <iostream>
#include <ctime>
#include "tiempo.h"
#include <fcntl.h>

using namespace std;


int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #else
    #endif

  Tiempo tiempo;
  tiempo.correTiempo();
}
