#include <iostream>
#include <ctime>
//#include <thread>
#include "tiempo.h"
using namespace std;


int main() {
#ifdef _WIN32
  
#else
  system("tput civis");
#endif  
  Tiempo tiempo;
  tiempo.correTiempo();
  
}