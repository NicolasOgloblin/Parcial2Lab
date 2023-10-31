///PARTICIPANTES:
///Maximiliano Ferrandi
///Nicolás Ogloblin

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

#include "Funciones.h"
#include "Clases.h"
#include "Prototipos.h"
#include "Reportes.h"


int main()
{

   int opc;

    while(true){

    system ("cls");

    cout <<"       MENU PRINCIPAL             "<< endl;
    cout <<"----------------------------------"<< endl;
    cout <<"1) MENU JUGADORES                 "<< endl;
    cout <<"2) MENU DEPORTES                  "<< endl;
    cout <<"3) MENU EQUIPOS                   "<< endl;
    cout <<"4) MENU TIPOS DE DEPORTES         "<< endl;
    cout <<"5) REPORTES                       "<< endl;
    cout <<"6) CONFIGURACION                  "<< endl;
    cout <<"----------------------------------"<< endl;
    cout <<"0) SALIR                          "<< endl;

    cout << "Ingrese una opcion: ";
    cin >> opc;

    system("cls");

    switch(opc){

    case 1: subMenuJugadores();
        break;
    case 2: subMenuDeportes();
        break;
  //case 3: subMenuEquipos();
 //       break;
    case 4: subMenuTiposDeDeporte();
        break;
    case 5: subMenuReportes();
        break;
    case 6: subMenuConfiguracion();
        break;
    case 0: return 0;
        break;

        }
    system("pause");
    }
    return 0;
}
