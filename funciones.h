#ifndef funciones
#define funciones
#include <iostream>
//LIBRERIAS PARA GENERAR EL NUMERO ALEATORIO
#include <stdlib.h>
#include <ctime>
//LIBRERIA PARA LIMPIAR LA CONSOLA
#include <windows.h>
//LIBRERIA PARA PODER USAR STRING
#include <string>
//LIBRERIA PARA PASAR DE MINUSCULA A MAYUSCULA
#include <cctype>
//LIBRERIA PARA PONER EN PAUSA LA CONSOLA
#include <conio.h>

using namespace std;
void iniciarJuego(string &nombre, string &nombre2, int &puntaje);
void volverMenu();
void mostrarEstadisticas(int puntajeGanadores[], string nombresGanadores[], string nombreEmpate[]);
void mostrarGanador(string nombresJugadores[], int trufasTotales[], int contadorOinks1, int contadorOinks2, int maxLanzamiento1,
                   int maxLanzamiento2, string &nombre, string &nombre2, int &puntaje);
void menuInicio(int &opcion);
void reglas();
bool confirmacionSalir();
void rondas(string nombresJugadores[], string &nombre, string &nombre2, int &puntaje);
bool empiezaJugador(string nombresJugadores[]);
bool validarOpcion(char opcion);
int tirarDados();
void dibujarDados(int a);
void limpiarConsola();
#endif // funciones
