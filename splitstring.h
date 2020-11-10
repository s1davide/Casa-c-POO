#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector <string> separar(string texto, char separador) {
    string texto2 = texto;
texto2.erase(std::remove(texto2.begin(), texto2.end(), ' '), texto2.end());    
   vector <string> separado;
   string palabra;
   for(int i = 0; i<texto2.length(); i++){   
     if(texto2[i]!=separador){
        palabra= palabra+ texto2[i];
      }      
      else{
        separado.push_back(palabra);
        palabra = "";
      }
    }
    separado.push_back(palabra);
    palabra = "";
    return separado;
}