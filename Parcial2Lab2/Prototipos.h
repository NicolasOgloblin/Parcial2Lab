#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include "Clases.h"
#include "Funciones.h"
#include "Reportes.h"

///----------------- PROTOTIPOS -----------------///
void cargarCadena(char, int);
int buscarPorDni(int);
Jugadores leerRegistro (int);
bool agregarJugador();
bool agregarJugadorValidado();
bool listarTodos ();
bool listarPorDni ();
bool modificarFechaInscripcion ();
bool bajaLogica();
bool buscarPorNombre ();
bool modificarRegistro (Jugadores, int);
void obtenerHoraSys();
void subMenuDeportes();
void subMenuJugadores();
void subMenuReportes();
void subMenuConfiguracion();
int buscarPorID(int);
bool modificarRegistroDeporte(Deporte, int);
bool buscarDeporte(int);
bool restaurarDatosInicioDeporte();
bool restaurarDatosInicioJugadores();
bool restaurarDatosInicio ();
bool agregarDeporte();
void mostrarDeportes ();
bool listarDeportePorId ();
Deporte leeRegistro (int);
bool modificarAnioDeOrigen();
bool eliminarRegistroDeporte();
bool copiaSeguridadDeportes();
bool restaurarArchDeportes();
bool copiaSeguridadJugadores();
bool restaurarArchJugadores();
///----------------- FIN PROTOTIPOS -----------------///



#endif // PROTOTIPOS_H_INCLUDED
