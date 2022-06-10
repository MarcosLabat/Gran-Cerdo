#include <iostream>
#include "funciones.h"
//LIBRERIA PARA PODER VER LOS ACENTOS
#include <locale.h>
//LIBRERIA PARA PODER USAR "STRING"
#include <string>
//LIBRERIA PARA LOS COLORES
#include <stdio.h>
//LIBRERIA PARA PONER EN PAUSA LA CONSOLA
#include <conio.h>
using namespace std;

int main(){
    system("color 5F");
    setlocale(LC_ALL, "");
    Beep(250, 100);
    Beep(300, 100);
    Beep(400, 100);
    Beep(500, 100);
    int opcion, puntaje = 0, puntajeMaximo = 0, puntajeAnterior;
    string  nombreGanador, nombreGanador2, anteriorGanador, anteriorGanador2;
    menuInicio(opcion);
    while(opcion >= 0 || opcion <= 3){
        if(opcion == 1){
            limpiarConsola();
            iniciarJuego(nombreGanador, nombreGanador2,puntaje);
        }
        else if(opcion == 2){
            limpiarConsola();
            mostrarEstadisticas(nombreGanador, nombreGanador2, anteriorGanador, anteriorGanador2, puntaje, puntajeMaximo, puntajeAnterior);
            volverMenu();
        }
        else if(opcion == 3){
            limpiarConsola();
            int legajos[4] = {25970, 25988, 26812, 26330};
            string nombresApellidos[4] = {"LABAT MARCOS LUCIANO", "MAGNAVACHI PABLO ANDRÉS", "TAM JUAN FACUNDO", "TORRES PAULA ANDREA"};
            cout << "\t\n LOS CREADORES DEL JUEGO SON:";
            for(int i = 0; i < 4; i++){
                cout << "\t\n\n " << nombresApellidos[i] << " " << legajos[i] ;
            }
            volverMenu();
        }else if(opcion == 4){
            reglas();
            volverMenu();
        }else{
            bool r;
            r = confirmacionSalir();
            if(r){
                limpiarConsola();
                cout << "\t\n HASTA LUEGO";
                Beep(500, 150);
                Beep(400, 150);
                Beep(300, 150);
                Beep(200, 150);
                Beep(100, 150);
                return 0;
            }
        }
    menuInicio(opcion);
    }
    return 0;
}
