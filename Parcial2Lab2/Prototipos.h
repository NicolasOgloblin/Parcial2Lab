#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include "Clases.h"

///  ----------------------------------------------------  PROTOTIPOS  ----------------------------------------------------  ///

//Main
void subMenuJugadores();
void subMenuDeportes();
void subMenuEquipos();
void subMenuTiposDeDeporte();
void subMenuReportes();
void subMenuConfiguracion();

//Cadena
void cargarCadena(char *, int);

//Restaurar datos de inicio
bool restaurarDatosInicioDeporte();
bool restaurarDatosInicioJugadores();
bool restaurarDatosInicio ();

//Funciones para equipos
bool agregarEquipos();
Equipos leerRegistroEquipo(int);
bool listarEquiposPorId();
bool listarTodosEquipo();
int BuscarEquiposPorID(int);
void escribirRegistroEquipo(Equipos, int);
bool modificarRegistroEquipo();
bool eliminarRegistroEquipo();

//Funciones para tipos de deportes
bool agregarTipoDeporte();
bool listarTipoPorID();
bool listarTodosTipos();
int buscarPorIDTipo(int);
TipodeDeporte leeRegistroTipo (int);
bool modificarRegistroTipodeDeporte (TipodeDeporte, int);
bool bajaLogicaTipo();

//Funciones para archivos deportes
bool agregarDeporte();
void mostrarDeportes();
bool listarDeportePorId();
Deporte leeRegistro (int);
bool modificarAnioDeOrigen();
int buscarPorID (int);
bool eliminarRegistroDeporte();
bool modificarRegistroDeporte (Deporte, int);
bool copiaSeguridadDeportes();
bool restaurarArchDeportes();

//Funciones para archivo jugadores
bool agregarJugador();
bool agregarJugadorValidado();
bool listarTodos();
bool listarPorDni();
bool modificarFechaInscripcion();
bool bajaLogica();
bool buscarPorNombre();
int buscarPorDni (int);
Jugadores leerRegistro (int);
bool modificarRegistro (Jugadores, int);
bool copiaSeguridadJugadores();
bool restaurarArchJugadores();

//Otras
void obtenerHoraSys();
bool buscarDeporte(int);


///  ----------------------------------------------------  FIN PROTOTIPOS  ----------------------------------------------------  ///



#endif // PROTOTIPOS_H_INCLUDED
