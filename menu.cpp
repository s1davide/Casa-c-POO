#include "menu.h"
#include "splitstring.h"
#include <vector>

using namespace std;

Menu::Menu(){
this -> ubicacion = "patio";
this -> opcion = 0;
this -> accionPendiente = "NA";
this -> limpiarPantallaBarra.push_back(false);
this -> limpiarPantallaBarra.push_back(false);
this -> limpiarPantallaBarra.push_back(false);
this -> porcentajes.push_back(0);
this -> porcentajes.push_back(0);
this -> porcentajes.push_back(0);

}
Menu::~Menu(){
}

void Menu::accion(int a, Estado instanciaEstado){
  int numeroOpciones;
  if (ubicacion=="patio"){
     numeroOpciones =lugar2.getOpciones().size();
    }
    else{
      numeroOpciones =lugar().getOpciones().size();
    }
    if(a>=49 && a<=57){
      if(a-49>=numeroOpciones){
        gotoxy(1, 2);
        cout<<"Opción invalida";
      }
      else{
        gotoxy(1, 2);
        cout<<"               ";
        if (ubicacion=="patio"){
      acciones = separar(lugar2.accion(a-49),',');
      ubicacion=acciones[0];
      }else{
        limpiarMenu(obtenerMenu());
        vector <string> ejecutarAccion;
        ejecutarAccion =separar(lugar().getAccion(a-49),',');
        ubicacion=ejecutarAccion[0];
        ejecutarAccion.size()>1  ?accionPendiente = ejecutarAccion[1] : accionPendiente="NA";
        opcion = 0;
        }
      }
    }
    else if(a==115 && (opcion+1)<numeroOpciones){
      opcion+=1;
      salida(instanciaEstado);
    }
    else if(a==119 && (opcion-1)>=0){
    opcion-=1;
    salida(instanciaEstado);
    }
    else if(a==10 || a==13){
      if (ubicacion=="patio"){
      acciones = separar(lugar2.accion(opcion),',');
      ubicacion=acciones[0];
      }
      else{
        limpiarMenu(obtenerMenu());
        vector <string> ejecutarAccion;
        ejecutarAccion =separar(lugar().getAccion(opcion),',');
        ubicacion=ejecutarAccion[0];
        ejecutarAccion.size()>1  ?accionPendiente = ejecutarAccion[1] : accionPendiente="NA";
        opcion = 0;
      }
    }
  salida(instanciaEstado);
  salidaMenu();
}

void Menu::salida(Estado instanciaEstado){

  gotoxy(1, 7);
  cout<<"Ubicación: "<<ubicacion;
  int ubicacionBarra = 11;
  int ubicacionProcentaje = ubicacionBarra*2;
  int linea =9;
  float totalAlimentacion = (float)instanciaEstado.obtieneTotalAlimentacion();
  float alimentacion = (float)instanciaEstado.obtieneHambreActual();
  float porcentaje = (alimentacion/totalAlimentacion)*100;
  porcentajes[0]= porcentaje;
  limpiarBarra(alimentacion, 0, ubicacionBarra, linea);
  gotoxy(1, linea);
  cout<<"Hambre: ";
  for(int i = ubicacionBarra; i<alimentacion+ubicacionBarra; i++){
    gotoxy(i, linea);
    cout<<"█";
  }
  gotoxy(ubicacionProcentaje, linea);
  cout<<porcentaje<<" %";

  float totalLimpieza = (float)instanciaEstado.obtieneTotalLimpieza();
  float suciedad = (float)instanciaEstado.obtieneSuciedadActual();
  float porcentaje2 = (suciedad/totalLimpieza)*100;
  porcentajes[1]= porcentaje2;
  limpiarBarra(suciedad, 1, ubicacionBarra, linea+1);
  gotoxy(1, linea+1);
  cout<<"Suciedad: ";
  for(int i = ubicacionBarra; i<suciedad+ubicacionBarra; i++){
    gotoxy(i, linea+1);
    cout<<"█";
  }
  gotoxy(ubicacionProcentaje, linea+1);
  cout<<porcentaje2<<" %";

  float totalCansancio = (float)instanciaEstado.obtieneTotalCansancio();
  float cansancio = (float)instanciaEstado.obtieneCansancioActual();
  float porcentaje3 = (cansancio/totalCansancio)*100;
  porcentajes[2] = porcentaje3;
  limpiarBarra(cansancio, 2, ubicacionBarra, linea+2);

  gotoxy(1, linea+2);
  cout<<"Sueño: ";
  for(int i = ubicacionBarra; i<cansancio+ubicacionBarra; i++){
    gotoxy(i, linea+2);
    cout<<"█";
  }
  gotoxy(ubicacionProcentaje, linea+2);
  cout<<porcentaje3<<" %";
}
void Menu::salidaMenu(){
  limpiarMenu(obtenerMenu());
  obtenerMenu();
  for(int i= 0; i<listaMenu.size();i++){
    if(i==opcion){
      gotoxy(1, 13+i);
      cout<<"                         ";
      gotoxy(1, 13+i);
      printf("%s - %s",listaMenu[i].c_str(),"[x]\n");
      //cout<<i+1<<". " <<listaMenu[i]<<" [x]"<<"\n";
    }
    else{
      gotoxy(1, 13+i);
      cout<<"                         ";
      gotoxy(1, 13+i);
      printf("%s - %s",listaMenu[i].c_str(),"[]\n");
      //cout<<i+1<<". "<<listaMenu[i]<<" []"<<"\n";
    }
  }
}
int Menu::keypress() {
  system ("/bin/stty raw");
  int c;
  system("/bin/stty -echo");
  c = getc(stdin);
  system("/bin/stty echo");
  system ("/bin/stty cooked");
  return c;
}
int Menu::comprobar(){
    int tecla;
     #ifdef _WIN32
        tecla = getch();

    #else
        tecla =keypress();
    #endif
  return tecla;
}
void Menu::gotoxy(int x,int y)
{
    #ifdef _WIN32
        HANDLE consola;
        consola = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(consola, dwPos);

    #else
        printf("%c[%d;%df",0x1B,y,x);
    #endif
}

Cuarto Menu::lugar(){
  Cuarto lugar;
  if (ubicacion=="sala"){
    Sala lugar2;
    lugar = lugar2;
    }
  else if (ubicacion=="dormitorio"){
  Dormitorio lugar2;
  lugar = lugar2;
  }
  else if (ubicacion=="baño"){
    Bano lugar2;
    lugar = lugar2;
    }
  else if (ubicacion=="cocina"){
  Cocina lugar2;
  lugar = lugar2;
  }
  return lugar;
}

void Menu::limpiarBarra(int valorBarra, int numeroBarra, int ubicacionBarra, int numeroLinea){
   if(valorBarra==0 && limpiarPantallaBarra[numeroBarra]){
    gotoxy(ubicacionBarra, numeroLinea);
    cout<<"                        ";
    limpiarPantallaBarra[numeroBarra]=false;
  }else if(valorBarra>0 && !limpiarPantallaBarra[numeroBarra]){
    limpiarPantallaBarra[numeroBarra]=true;
  }
}




void Menu::limpiarPantalla(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
};


int Menu::obtenerMenu(){
  if (ubicacion=="patio"){
    listaMenu = lugar2.getOpciones();
  }
  else{
    listaMenu = lugar().getOpciones();
  }
  int listaTamano = listaMenu.size();
  return listaTamano;
}
void Menu::limpiarMenu(int tamanoLista){
  for(int i= 0; i<tamanoLista;i++){
      gotoxy(1, 13+i);
      //cout<<"                            ";
      printf("                             ");
  }
}
vector <string> Menu::estadoJuego(){
  vector <string> respuesta;
  respuesta.push_back(accionPendiente);
  gotoxy(1, 13);
  if(porcentajes[0]+1>100){
    limpiarPantalla();
    cout<<"No te has alimentado a tiempo\n";
    respuesta.push_back("terminar");
  }
  else if(porcentajes[1]+1>100){
    limpiarPantalla();
    cout<<"No te has duchado a tiempo\n";
    respuesta.push_back("terminar");
  }
  else if(porcentajes[2]+1>100){
    limpiarPantalla();
    cout<<"No te has ido a dormir a tiempo\n";
    respuesta.push_back("terminar");
  }
  else{
    respuesta.push_back("continuar");
  }

  return respuesta;
  accionPendiente ="NA";

}
void Menu::pantallaInicial(){

  printf("Controles: \n");
  cout<<"Numero de opción"<<"\n";
  cout<<"                     "<<"\n";
  cout<<"Controles Alternativos: "<<"\n";
  cout<<"Tecla w  -->  Arriba"<<"\n";
  cout<<"Tecla s  -->  Abajo"<<"\n";

  cout<<"Enter para continuar..."<<"\n";
}
