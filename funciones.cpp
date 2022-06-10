#include "funciones.h"
void menuInicio(int &opcion){
    limpiarConsola();
    cout << "\t\t\n JUEGO GRAN CERDO";
    cout << "\t\t\n ---------------------------";
    cout << "\t\t\n 1 - JUGAR";
    cout << "\t\t\n 2 - ESTADÍSTICAS";
    cout << "\t\t\n 3 - CRÉDITOS";
    cout << "\t\t\n 4 - REGLAS";
    cout << "\t\t\n ---------------------------";
    cout << "\t\t\n 0 - SALIR" << endl;
    cout << "\t\t\n INGRESE LA OPCIÓN QUE DESEE: ";
    cin >> opcion;
    Beep(500, 100);
    while(opcion < 0 || opcion > 4){
        limpiarConsola();
        cout << "\t\t\n ERROR,INGRESE UNA OPCION VALIDA";
        cout << "\t\t\n ---------------------------";
        cout << "\t\t\n 1 - JUGAR";
        cout << "\t\t\n 2 - ESTADÍSTICAS";
        cout << "\t\t\n 3 - CRÉDITOS";
        cout << "\t\t\n 4 - REGLAS";
        cout << "\t\t\n ---------------------------";
        cout << "\t\t\n 0 - SALIR" << endl;
        cout << "\t\t\n INGRESE LA OPCIÓN QUE DESEE: ";
        cin >> opcion;
        Beep(500, 100);
    }
}

//INICIO DEL JEUGO
void iniciarJuego(string &nombreGanador, string &nombreGanador2, int &puntaje){
    string nombresJugadores[2];
    cout << "\t\n INGRESE EL NOMBRE DEL PRIMER JUGADOR: ";
    cin >> nombresJugadores[0];
    Beep(500, 100);
    cout << "\t\n INGRESE EL NOMBRE DEL SEGUNDO JUGADOR: ";
    cin >> nombresJugadores[1];
    Beep(500, 100);
    rondas(nombresJugadores, nombreGanador, nombreGanador2, puntaje);
}

//CONFIMACION SI SALE DEL JUEGO
bool confirmacionSalir(){
    limpiarConsola();
    char opcion;
    cout << "\t\n ¿ESTAS SEGURO QUE DESEA SALIR DEL JUEGO?(S/N): ";
    cin >> opcion;
    opcion = toupper(opcion);
    Beep(500, 100);
    while(opcion != 'N' && opcion != 'S'){
    limpiarConsola();
    cout << "\t\n TECLA INCORRECTA,¿ESTAS SEGURO QUE DESEA SALIR DEL JUEGO?(S/N): ";
    cin >> opcion;
    opcion = toupper(opcion);
    Beep(500, 100);
    }
    opcion = toupper(opcion);
    if(opcion == 'S'){
        return true;
    }else{
        return false;
    }
}

//SUB-MENU PARA VOLVER AL MENU PRINCIPAL
void volverMenu(){
    int opcion;
    cout << endl;
    cout << "\t\n ---------------------------";
    cout << "\t\n 1 - MENÚ PRINCIPAL";
    cout << "\t\n ---------------------------" << endl;
    cout << "\t\n INGRESE LA OPCIÓN PARA VOLVER AL MENÚ: ";;
    cin >> opcion;
    opcion = toupper(opcion);
    Beep(500, 100);
    while(opcion != 1){
        limpiarConsola();
        cout << "\t\n ERROR,INGRESE UNA OPCION CORRECTA";
        cout << "\t\n ---------------------------";
        cout << "\t\n 1 - MENÚ PRINCIPAL";
        cout << "\t\n ---------------------------" << endl;
        cout << "\t\n INGRESE LA OPCIÓN PARA VOLVER AL MENÚ: ";
        cin >> opcion;
        opcion = toupper(opcion);
        Beep(500, 100);
    }
}

//MOSTRAR ESTADISTICAS
void mostrarEstadisticas(string &nombreGanador, string &nombreGanador2, string &anteriorGanador, string &anteriorGanador2, int &puntaje, int &puntajeMaximo, int &puntajeAnterior){
    limpiarConsola();
    if(puntaje == 0){
        cout << "\t\n ---------------------------------------------";
        cout << "\t\n | NO HAY DATOS, JUEGUE Y VUELVA A CONSULTAR |";
        cout << "\t\n ---------------------------------------------";
    }else if(nombreGanador == nombreGanador2){
        if(puntaje > puntajeMaximo){
            puntajeMaximo = puntaje;
            anteriorGanador = nombreGanador;
            puntajeAnterior = puntaje;
            cout << "\t\n --------------------------------------------------------------------------------------------------------";
            cout << "\t\n EL JUGADOR CON MAYOR CANTIDAD DE PUNTOS ES " << nombreGanador << " CON " << puntaje << " PDV";
            cout << "\t\n --------------------------------------------------------------------------------------------------------";
        }else if(puntaje < puntajeMaximo){
            cout << "\t\n --------------------------------------------------------------------------------------------------------";
            cout << "\t\n EL JUGADOR CON MAYOR CANTIDAD DE PUNTOS ES " << anteriorGanador << " CON " << puntajeAnterior << " PDV";
            cout << "\t\n --------------------------------------------------------------------------------------------------------";
        }else{
            cout << "\t\n --------------------------------------------------------------------------------------------------------";
            cout << "\t\n LOS JUGADORES CON MAYOR CANTIDAD DE PUNTOS SON " << anteriorGanador << " Y " << nombreGanador << " CON " << puntajeAnterior << " PDV";
            cout << "\t\n --------------------------------------------------------------------------------------------------------";
        }
    }else{
       if(puntaje > puntajeMaximo){
            puntajeMaximo = puntaje;
            anteriorGanador = nombreGanador;
            anteriorGanador2 = nombreGanador2;
            puntajeAnterior = puntaje;
            cout << "\t\n ---------------------------------------------------------------------------------------------------------------------------------";
            cout << "\t\n LOS JUGADORES CON MAYOR CANTIDAD DE PUNTOS SON " << nombreGanador << " Y " << nombreGanador2 << " CON " << puntaje << " PDV";
            cout << "\t\n ----------------------------------------------------------------------------------------------------------------------------------";
        }else if(puntaje < puntajeMaximo){
            cout << "\t\n --------------------------------------------------------------------------------------------------------";
            cout << "\t\n LOS JUGADORES CON MAYOR CANTIDAD DE PUNTOS SON " << anteriorGanador << " Y " << anteriorGanador2 << " CON " << puntajeAnterior << " PDV";
            cout << "\t\n --------------------------------------------------------------------------------------------------------";
        }else{
            cout << "\t\n --------------------------------------------------------------------------------------------------------";
            cout << "\t\n LOS JUGADORES CON MAYOR CANTIDAD DE PUNTOS SON " << anteriorGanador << ", " << anteriorGanador2 << ", " << nombreGanador << " Y " << nombreGanador2 << " CON " << puntajeAnterior << " PDV";
            cout << "\t\n --------------------------------------------------------------------------------------------------------";
        }
    }
}

void reglas(){
    limpiarConsola();
    cout << "\t\n Gran Cerdo es un juego de dados de dos jugadores en el que intervienen el azar y la codicia. El objetivo general del juego es sumar la mayor cantidad de puntos de victoria en un total de 5 rondas";
    cout << "\t\n La suma de puntaje depende de diferentes situaciones que se pueden dar en el juego y que más adelante se explicarán. Se juega con dos o tres dados de seis caras por cada jugador. Antes de comenzar";
    cout << "\t\n se debe determinar cuál de los dos jugadores empieza. Para ello se lanzan dos dados y el jugador que haya obtenido el mayor puntaje comienza. Si empatan en el puntaje, comienza el jugador que haya";
    cout << "\t\n obtenido el dado más alto. Si empatan nuevamente vuelven a lanzar ambos dados otra vez.";
    cout << "\t\n\n El juego está compuesto por cinco rondas por jugador y en cada ronda el jugador dispone de ilimitados lanzamientos.En cada lanzamiento el jugador tira los dados y se analiza los valores de las caras:";
    cout << "\t\n\n 1)Si las caras son distintas entre sí y ninguna de ellas es un as. Entonces el cerdo acumula trufas según la suma de las caras al total de la ronda. Por ejemplo: 5 y 3 Acumula 8 trufas. Luego, puede";
    cout << "\t\n decidir si volver a lanzar los dados o plantarse y ceder el turno al otro cerdo. Si se está lanzando con tres dados y hay dos caras iguales y una distinta (siempre que no sean ases)";
    cout << "\t\n Es correcto que realice cualquiera de estas dos alternativas:";
    cout << "\t\n - No sume ninguna trufa en ese lanzamiento y le pregunte al jugador si desea seguir lanzando.";
    cout << "\t\n - Sume todos los dados en concepto de trufas y le pregunte al jugador si desea seguir lanzando.";
    cout << "\t\n\n 2)Si las caras son iguales entre sí y no son ases. Entonces el cerdo hizo un Oink y  acumula trufas por el doble de la suma de las caras al total de la ronda. Por ejemplo: 4 y 4 Acumula 16 trufas.";
    cout << "\t\n También, está obligado a lanzar los dados una vez más.";
    cout << "\t\n\n 3)Si las caras son distintas entre sí y hay un as entre ellas. Pierde todas las trufas que venía acumulando en la ronda actual y automáticamente le cede el turno al otro cerdo.";
    cout << "\t\n\n 4)Si dos de las caras son iguales entre sí y son ases. El cerdo se hunde en el barro y pierde todas las trufas que venía acumulando en las rondas anteriores y la actual; y automáticamente le cede el turno";
    cout << "\t\n al otro cerdo.";
    cout << "\t\n\n 5)Si se está lanzando con tres dados y tres de las caras son iguales entre sí y son ases. Aplica la misma quita de puntos que en el caso anterior pero dichos puntos se acumulan al otro cerdo en dicha ronda.";
    cout << "\t\n\n CRITERIOS PARA LA SUMA DE PUNTOS";
    cout << "\t\n +----------------------------------------------------+";
    cout << "\t\n | HITO                 |             PDV             |";
    cout << "\t\n ------------------------------------------------------";
    cout << "\t\n | MAS TRUFAS EN TOTAL  |            5 PDV            |";
    cout << "\t\n ------------------------------------------------------";
    cout << "\t\n | CADA 50 TRUFAS       |            1 PDV            |";
    cout << "\t\n ------------------------------------------------------";
    cout << "\t\n | OINK                 |  2 PDV * CANTIDAD DE OINKS  |";
    cout << "\t\n ------------------------------------------------------";
    cout << "\t\n | CERDO CODICIOSO      |            3 PDV            |";
    cout << "\t\n +----------------------------------------------------+";
}

bool empiezaJugador(string nombresJugadores[]){
    bool empiezaJugador = false;
    while(!empiezaJugador){
        limpiarConsola();
        int dadosJug1[2] = {}, dadosJug2[2] = {}, dadosConseguido1 = 0, dadosConseguido2 = 0;
        char tirar;
        cout << "\t\n " << nombresJugadores[0] << " PRESIONE (T) PARA TIRAR LOS DADOS: ";
        cin >> tirar;
        tirar = toupper(tirar);
        Beep(500, 100);
        while(tirar != 'T'){
            cout << "\t\n TECLA INCORRECTA, INGRESE LA (T) POR FAVOR: ";
            cin >> tirar;
            tirar = toupper(tirar);
            Beep(500, 100);
        }
        dadosJug1[0] = tirarDados();
        dadosJug1[1] = tirarDados();
        cout << "\t\n DADOS DE "  << nombresJugadores[0] << endl;
        dibujarDados(dadosJug1[0]);
        dibujarDados(dadosJug1[1]);
        cout << "\t\n " << nombresJugadores[1] << " PRESIONE (T) PARA TIRAR LOS DADOS: ";
        cin >> tirar;
        tirar = toupper(tirar);
        Beep(500, 100);
        if(tirar != 'T'){
            cout << "\t\n TECLA INCORRECTA, INGRESE LA (T) POR FAVOR: ";
            cin >> tirar;
            tirar = toupper(tirar);
            Beep(500, 100);
        }
        dadosJug2[0] = tirarDados();
        dadosJug2[1] = tirarDados();
        cout << "\t\n DADOS DE "  << nombresJugadores[1] << endl;
        dibujarDados(dadosJug2[0]);
        dibujarDados(dadosJug2[1]);
        dadosConseguido1 = dadosJug1[0] + dadosJug1[1];
        dadosConseguido2 = dadosJug2[0] + dadosJug2[1];
        if(dadosConseguido1 > dadosConseguido2){
            cout << "\t\n SUMANDO LAS DOS CARAS, SACO MAYOR RESULTADO. COMINEZA " << nombresJugadores[0];
            cout << "\t\n\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
            getch();
            Beep(500, 100);
            empiezaJugador = true;
            return true;
        }else if(dadosConseguido2 > dadosConseguido1){
            cout << "\t\n SUMANDO LAS DOS CARAS, SACO MAYOR RESULTADO. COMINEZA " << nombresJugadores[1];
            cout << "\t\n\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
            getch();
            Beep(500, 100);
            empiezaJugador = true;
            return false;
        }else{
            if(dadosJug1[0] > dadosJug2[0] && dadosJug1[0] > dadosJug2[1]){
                cout << "\t\n SUMA DE LAS DOS CARAS IGUAL, PERO TIENE MAYOR DADO INDIVIDUAL. COMIENZA " << nombresJugadores[0];
                cout << "\t\n\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                getch();
                Beep(500, 100);
                empiezaJugador = true;
                return true;
            }else if(dadosJug1[1] > dadosJug2[0] && dadosJug1[1] > dadosJug2[1]){
                cout << "\t\n SUMA DE LAS DOS CARAS IGUAL, PERO TIENE MAYOR DADO INDIVIDUAL. COMIENZA " << nombresJugadores[0];
                cout << "\t\n\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                getch();
                Beep(500, 100);
                empiezaJugador = true;
                return true;
            }else if(dadosJug2[0] > dadosJug1[0] && dadosJug2[0] > dadosJug1[1]){
                cout << "\t\n SUMA DE LAS DOS CARAS IGUAL, PERO TIENE MAYOR DADO INDIVIDUAL. COMIENZA " << nombresJugadores[1];
                cout << "\t\n\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                getch();
                Beep(500, 100);
                empiezaJugador = true;
                return false;
            }else if(dadosJug2[1] > dadosJug1[0] && dadosJug2[1] > dadosJug1[1]){
                cout << "\t\n SUMA DE LAS DOS CARAS IGUAL, PERO TIENE MAYOR DADO INDIVIDUAL. COMIENZA " << nombresJugadores[1];
                cout << "\t\n\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                getch();
                Beep(500, 100);
                empiezaJugador = true;
                return false;
            }else{
                cout << "\t\n EMPATE, SE VUELVE A TIRAR.";
                cout << "\t\n\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                getch();
                Beep(500, 100);
                empiezaJugador = false;
            }
        }
    }
}

void rondas(string nombresJugadores[], string &nombreGanador, string &nombreGanador2, int &puntaje){
    int i, trufasTotales[2] = {}, contadorRondas = 0, maxLanzamiento1 = 0, maxLanzamiento2 = 0, contadorOinks1 = 0, contadorOinks2 = 0;
    int contadorLanzamientos = 0, promedioLanzamientos = 0, lanzamientosJug1[5] = {}, lanzamientosJug2[5] = {}, contador1 = 0, contador2 = 0;
    bool banderaTresDados = 0, cayoBarro = 0, empieza = 0;
    char continuar;
    empieza = empiezaJugador(nombresJugadores);
    limpiarConsola();
    for(i = 0; i < 10; i++){
        bool banderaTirar = 1;
        int lanzamientos = 0,  contadorTrufas1 = 0, contadorTrufas2 = 0;
        if(i % 2 == 0){
            contadorRondas++;
        }
        while(banderaTirar != 0){
            int trufas = 0, pasarDeRonda = 0;
            cout << "\t\n GRAN CERDO";
            cout << "\t\n -------------------------------------------------------------";
            cout << "\t\n " << nombresJugadores[0] << ": " << trufasTotales[0] << " trufas acumuladas \t "
            << nombresJugadores[1] << ": " << trufasTotales[1] << " trufas acumuladas";
            if(empieza){
                if(!banderaTresDados){
                    cout << "\t\n\n TURNO DE " << nombresJugadores[0];
                    cout << "\t\n +------------------------------+";
                    cout << "\t\n | RONDA #" << contadorRondas <<"\t\t\t|";
                    if(contadorTrufas1 < 10){
                        cout << "\t\n | TRUFAS DE LA RONDA:" << contadorTrufas1 <<"\t\t|";

                    }else{
                        cout << "\t\n | TRUFAS DE LA RONDA:" << contadorTrufas1 <<"\t|";
                    }
                    cout << "\t\n | LANZAMIENTOS:" << lanzamientos <<"\t\t|";
                    cout << "\t\n +------------------------------+";
                    char tirar;
                    cout << "\t\n " << nombresJugadores[0] << " PRESIONE (T) PARA TIRAR LOS DADOS: ";
                    cin >> tirar;
                    tirar = toupper(tirar);
                    Beep(500, 100);
                    while(tirar != 'T'){
                        cout << "\t\n TECLA INCORRECTA, INGRESE LA (T) POR FAVOR: ";
                        cin >> tirar;
                        tirar = toupper(tirar);
                        Beep(500, 100);
                    }
                    int dados[2] = {}, x;
                    for(x = 0; x < 2; x++){
                        dados[x] = tirarDados();
                    }
                    lanzamientos++;
                    contadorLanzamientos++;
                    if(lanzamientos > maxLanzamiento1){
                        maxLanzamiento1 = lanzamientos;
                    }
                    cout << "\t\n LANZAMIENTO #" << lanzamientos << endl;
                    dibujarDados(dados[0]);
                    dibujarDados(dados[1]);
                    if(dados[0] != dados[1] && dados[0] != 1 && dados[1] != 1){
                        cout << "\t\n SUMAS TUS TRUFAS";
                        trufas = dados[0] + dados[1];
                        contadorTrufas1 += trufas;
                        trufasTotales[0] += trufas;
                    }else if( (dados[0] != dados[1]) && (dados[0] == 1 || dados[1] == 1) ){
                        cout << "\t\n PERDISTE LAS TRUFAS DE LA RONDA ACTUAL";
                        trufasTotales[0] -= contadorTrufas1;
                        contadorTrufas1 = 0;
                        pasarDeRonda = 1;
                    }else if(dados[0] != 1 && dados[1] != 1){
                        cout << "\t\n MULTIPLICAS TUS TRUFAS, HICISTE UN OINK";
                        trufas = (dados[0] + dados[1]) * 2;
                        contadorTrufas1 += trufas;
                        trufasTotales[0] += trufas;
                        contadorOinks1++;
                        pasarDeRonda = 2;
                    }else if(dados[0] == 1){
                        cout << "\t\n TE HUNDISTE EN EL BARRO, PERDES TODAS TUS TRUFAS";
                        trufasTotales[0] = 0;
                        pasarDeRonda = 1;
                        cayoBarro = 1;
                    }
                    cout << "\t\n ¡SUMASTE " << trufas << " TRUFAS!";
                    if(pasarDeRonda == 0){
                        cout << "\t\n ¿CONTINUAR?(S/N): ";
                        cin >> continuar;
                        continuar = toupper(continuar);
                        Beep(500, 100);
                        while(continuar != 'S' && continuar != 'N'){
                            cout << "\t\n TECLA INCORRECTA, ¿CONTINUAR?(S/N): ";
                            cin >> continuar;
                            continuar = toupper(continuar);
                            Beep(500, 100);
                        }
                        if(continuar == 'N'){
                            banderaTirar = 0;
                        }

                    }else if(pasarDeRonda == 1){
                        cout << "\t\n PERDISTE TU TURNO.";
                        cout << "\t\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                        getch();
                        Beep(500, 100);
                        banderaTirar = 0;
                    }else{
                        cout << "\t\n ESTAS OBLIGADO A TIRAR DE NUEVO.";
                        cout << "\t\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                        getch();
                        Beep(500, 100);
                        banderaTirar = 1;
                    }
                    //VERIFICAR SI YA SE TIENE QUE JUGAR CON TRES DADOS
                    if((trufasTotales[0] >= 50 && trufasTotales[1] >= 50) || cayoBarro){
                        limpiarConsola();
                        banderaTresDados = 1;
                        cout << "\t\n A PARTIR DE AHORA SE JUEGA CON TRES DADOS";
                        cout << "\t\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                        getch();
                    }
                    limpiarConsola();
                //ELSE DE LA PREGUNTA SI BANDERATRESDADOS ES TRUE
                }else{
                    cout << "\t\n\n TURNO DE " << nombresJugadores[0];
                    cout << "\t\n +------------------------------+";
                    cout << "\t\n | RONDA #" << contadorRondas <<"\t\t\t|";
                    if(contadorTrufas1 < 10){
                        cout << "\t\n | TRUFAS DE LA RONDA:" << contadorTrufas1 <<"\t\t|";

                    }else{
                        cout << "\t\n | TRUFAS DE LA RONDA:" << contadorTrufas1 <<"\t|";
                    }
                    cout << "\t\n | LANZAMIENTOS:" << lanzamientos <<"\t\t|";
                    cout << "\t\n +------------------------------+";
                    char tirar;
                    cout << "\t\n " << nombresJugadores[0] << " PRESIONE (T) PARA TIRAR LOS DADOS: ";
                    cin >> tirar;
                    tirar = toupper(tirar);
                    Beep(500, 100);
                    while(tirar != 'T'){
                        cout << "\t\n TECLA INCORRECTA, INGRESE LA (T) POR FAVOR: ";
                        cin >> tirar;
                        tirar = toupper(tirar);
                        Beep(500, 100);
                    }
                    int dados[3], i;
                    for(i = 0; i < 3; i++){
                        dados[i] = tirarDados();
                    }
                    lanzamientos++;
                    contadorLanzamientos++;
                    if(lanzamientos > maxLanzamiento1){
                        maxLanzamiento1 = lanzamientos;
                    }
                    cout << "\t\n LANZAMIENTO #" << lanzamientos << endl;
                    for(i = 0; i < 3; i++){
                        dibujarDados(dados[i]);
                    }
                    if((dados[0] == dados[1] && dados[1] == dados[2]) && dados[0] != 1){
                        cout << "\t\n MULTIPLICAS TUS TRUFAS, HICISTE UN OINK";
                        for(int i = 0; i < 3; i++){
                            trufas += dados[i];
                        }
                        trufas *= 2;
                        contadorTrufas1 += trufas;
                        trufasTotales[0] += trufas;
                        contadorOinks1++;
                        pasarDeRonda = 2;
                    }else if( (dados[0] == dados[1] && dados[1] == dados[2]) && dados[0] == 1){
                        cout << "\t\n PERDISTE TUS TRUFAS Y SE LAS CEDES AL OTRO";
                        trufasTotales[1] += trufasTotales[0];
                        trufasTotales[0] = 0;
                        pasarDeRonda = 1;
                    }else if( (dados[0] == dados[1] && dados[0] == 1) || (dados[1] == dados[2] && dados[1] == 1) || (dados[0] == dados[2] && dados[0] == 1) ){
                        cout << "\t\n TE HUNDISTE EN EL BARRO, PERDES TODAS TUS TRUFAS";
                        trufasTotales[0] = 0;
                        pasarDeRonda = 1;
                    }else if( dados[0] != 1 && dados[1] != 1 && dados[2] != 1 ){
                        cout << "\t\n SUMAS TUS TRUFAS";
                        for(int i = 0; i < 3; i++){
                            trufas += dados[i];
                        }
                        contadorTrufas1 += trufas;
                        trufasTotales[0] += trufas;
                    }else if( dados[0] == 1 || dados[1] == 1 || dados[2] == 1 ){
                        cout << "\t\n PERDISTE LAS TRUFAS DE LA RONDA ACTUAL";
                        trufasTotales[0] -= contadorTrufas1;
                        contadorTrufas1 = 0;
                        pasarDeRonda = 1;
                    }
                    cout << "\t\n ¡SUMASTE " << trufas << " TRUFAS!";
                    if(pasarDeRonda == 0){
                        cout << "\t\n ¿CONTINUAR?(S/N): ";
                        cin >> continuar;
                        continuar = toupper(continuar);
                        Beep(500, 100);
                        while(continuar != 'S' && continuar != 'N'){
                            cout << "\t\n TECLA INCORRECTA, ¿CONTINUAR?(S/N): ";
                            cin >> continuar;
                            continuar = toupper(continuar);
                            Beep(500, 100);
                        }
                        if(continuar == 'N'){
                            banderaTirar = 0;
                        }

                    }else if(pasarDeRonda == 1){
                        cout << "\t\n PERDISTE TU TURNO.";
                        cout << "\t\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                        getch();
                        Beep(500, 100);
                        banderaTirar = 0;
                    }else{
                        cout << "\t\n ESTAS OBLIGADO A TIRAR DE NUEVO ";
                        cout << "\t\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                        getch();
                        Beep(500, 100);
                        banderaTirar = 1;
                    }
                    limpiarConsola();
                }
                lanzamientosJug1[contadorRondas - 1] = lanzamientos;
            }else{
                if(!banderaTresDados){
                    cout << "\t\n\n TURNO DE " << nombresJugadores[1];
                    cout << "\t\n +------------------------------+";
                    cout << "\t\n | RONDA #" << contadorRondas <<"\t\t\t|";
                    if(contadorTrufas2 < 10){
                        cout << "\t\n | TRUFAS DE LA RONDA:" << contadorTrufas2 <<"\t\t|";

                    }else{
                        cout << "\t\n | TRUFAS DE LA RONDA:" << contadorTrufas2 <<"\t|";
                    }
                    cout << "\t\n | LANZAMIENTOS:" << lanzamientos <<"\t\t|";
                    cout << "\t\n +------------------------------+";
                    char tirar;
                    cout << "\t\n " << nombresJugadores[1] << " PRESIONE (T) PARA TIRAR LOS DADOS: ";
                    cin >> tirar;
                    tirar = toupper(tirar);
                    Beep(500, 100);
                    while(tirar != 'T'){
                        cout << "\t\n TECLA INCORRECTA, INGRESE LA (T) POR FAVOR: ";
                        tirar = toupper(tirar);
                        cin >> tirar;
                        Beep(500, 100);
                    }
                    int dados[2] = {}, x;
                    for(x = 0; x < 2; x++){
                        dados[x] = tirarDados();
                    }
                    lanzamientos++;
                    contadorLanzamientos++;
                    if(lanzamientos > maxLanzamiento2){
                        maxLanzamiento2 = lanzamientos;
                    }
                    cout << "\t\n LANZAMIENTO #" << lanzamientos << endl;
                    dibujarDados(dados[0]);
                    dibujarDados(dados[1]);
                    if(dados[0] != dados[1] && dados[0] != 1 && dados[1] != 1){
                        cout << "\t\n SUMAS TUS TRUFAS";
                        trufas = dados[0] + dados[1];
                        contadorTrufas2 += trufas;
                        trufasTotales[1] += trufas;
                    }else if((dados[0] != dados[1]) && (dados[0] == 1 || dados[1] == 1) ){
                        cout << "\t\n PERDISTE LAS TRUFAS DE LA RONDA ACTUAL";
                        trufasTotales[1] -= contadorTrufas2;
                        contadorTrufas2 = 0;
                        pasarDeRonda = 1;
                    }
                    else if(dados[0] != 1 && dados[1] != 1){
                        cout << "\t\n MULTIPLICAS TUS TRUFAS, HICISTE UN OINK";
                        trufas = (dados[0] + dados[1]) * 2;
                        contadorTrufas2 += trufas;
                        trufasTotales[1] += trufas;
                        contadorOinks2++;
                        pasarDeRonda = 2;
                    }else if(dados[0] == 1){
                        cout << "\t\n TE HUNDISTE EN EL BARRO, PERDES TODAS TUS TRUFAS";
                        trufasTotales[1] = 0;
                        pasarDeRonda = 1;
                        cayoBarro = 1;
                    }
                    cout << "\t\n ¡SUMASTE " << trufas << " TRUFAS!";
                    if(pasarDeRonda == 0){
                        cout << "\t\n ¿CONTINUAR?(S/N): ";
                        cin >> continuar;
                        continuar = toupper(continuar);
                        Beep(500, 100);
                        while(continuar != 'S' && continuar != 'N'){
                            cout << "\t\n TECLA INCORRECTA, ¿CONTINUAR?(S/N): ";
                            cin >> continuar;
                            continuar = toupper(continuar);
                            Beep(500, 100);
                        }
                        if(continuar == 'N'){
                            banderaTirar = 0;
                        }
                    }else if(pasarDeRonda == 1){
                        cout << "\t\n PERDISTE TU TURNO,  ";
                        cout << "\t\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                        getch();
                        Beep(500, 100);
                        banderaTirar = 0;
                    }else{
                        cout << "\t\n ESTAS OBLIGADO A TIRAR DE NUEVO ";
                        cout << "\t\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                        getch();
                        Beep(500, 100);
                        banderaTirar = 1;
                    }
                    //VERIFICAR SI YA SE TIENE QUE JUGAR CON TRES DADOS
                    if((trufasTotales[0] >= 50 && trufasTotales[1] >= 50) || cayoBarro){
                        limpiarConsola();
                        banderaTresDados = 1;
                        cout << "\t\n A PARTIR DE AHORA SE JUEGA CON TRES DADOS";
                        cout << "\t\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                        getch();
                    }
                    limpiarConsola();
                //ELSE DE LA PREGUNTA SI BANDERATRESDADOS ES TRUE
                }else{
                    cout << "\t\n\n TURNO DE " << nombresJugadores[1];
                    cout << "\t\n +------------------------------+";
                    cout << "\t\n | RONDA #" << contadorRondas <<"\t\t\t|";
                    if(contadorTrufas2 < 10){
                        cout << "\t\n | TRUFAS DE LA RONDA:" << contadorTrufas2 <<"\t\t|";

                    }else{
                        cout << "\t\n | TRUFAS DE LA RONDA:" << contadorTrufas2 <<"\t|";
                    }
                    cout << "\t\n | LANZAMIENTOS:" << lanzamientos <<"\t\t|";
                    cout << "\t\n +------------------------------+";
                    char tirar;
                    cout << "\t\n " << nombresJugadores[1] << " PRESIONE (T) PARA TIRAR LOS DADOS: ";
                    cin >> tirar;
                    tirar = toupper(tirar);
                    Beep(500, 100);
                    while(tirar != 'T'){
                        cout << "\t\n TECLA INCORRECTA, INGRESE LA (T) POR FAVOR: ";
                        cin >> tirar;
                        tirar = toupper(tirar);
                        Beep(500, 100);
                    }
                    int dados[3], i;
                    for(i = 0; i < 3; i++){
                        dados[i] = tirarDados();
                    }
                    lanzamientos++;
                    contadorLanzamientos++;
                    if(lanzamientos > maxLanzamiento2){
                        maxLanzamiento2 = lanzamientos;
                    }
                    cout << "\t\n LANZAMIENTO #" << lanzamientos << endl;
                    for(i = 0; i < 3; i++){
                        dibujarDados(dados[i]);
                    }
                    if((dados[0] == dados[1] && dados[1] == dados[2]) && dados[0] != 1){
                        cout << "\t\n MULTIPLICAS TUS TRUFAS, HICISTE UN OINK";
                        for(int i = 0; i < 3; i++){
                            trufas += dados[i];
                        }
                        trufas *= 2;
                        contadorTrufas2 += trufas;
                        trufasTotales[0] += trufas;
                        contadorOinks2++;
                        pasarDeRonda = 2;
                    }else if( (dados[0] == dados[1] && dados[1] == dados[2]) && dados[0] == 1){
                        cout << "\t\n PERDISTE TUS TRUFAS Y SE LAS CEDES AL OTRO";
                        trufasTotales[0] += trufasTotales[1];
                        trufasTotales[1] = 0;
                        pasarDeRonda = 1;
                    }else if( (dados[0] == dados[1] && dados[0] == 1) || (dados[1] == dados[2] && dados[1] == 1) || (dados[0] == dados[2] && dados[0] == 1) ){
                        cout << "\t\n TE HUNDISTE EN EL BARRO, PERDES TODAS TUS TRUFAS";
                        trufasTotales[1] = 0;
                        pasarDeRonda = 1;
                    }else if( dados[0] != 1 && dados[1] != 1 && dados[2] != 1 ){
                        cout << "\t\n SUMAS TUS TRUFAS";
                        for(int i = 0; i < 3; i++){
                            trufas += dados[i];
                        }
                        contadorTrufas2 += trufas;
                        trufasTotales[1] += trufas;
                    }else if( dados[0] == 1 || dados[1] == 1 || dados[2] == 1 ){
                        cout << "\t\n PERDISTE LAS TRUFAS DE LA RONDA ACTUAL";
                        trufasTotales[1] -= contadorTrufas2;
                        contadorTrufas2 = 0;
                        pasarDeRonda = 1;
                    }
                    cout << "\t\n ¡SUMASTE " << trufas << " TRUFAS!";
                    if(pasarDeRonda == 0){
                        cout << "\t\n ¿CONTINUAR?(S/N): ";
                        cin >> continuar;
                        continuar = toupper(continuar);
                        Beep(500, 100);
                        while(continuar != 'S' && continuar != 'N'){
                            cout << "\t\n TECLA INCORRECTA, ¿CONTINUAR?(S/N): ";
                            cin >> continuar;
                            continuar = toupper(continuar);
                            Beep(500, 100);
                        }
                        if(continuar == 'N'){
                            banderaTirar = 0;
                        }

                    }else if(pasarDeRonda == 1){
                        cout << "\t\n PERDISTE TU TURNO,  ";
                        cout << "\t\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                        getch();
                        Beep(500, 100);
                        banderaTirar = 0;
                    }else{
                        cout << "\t\n ESTAS OBLIGADO A TIRAR DE NUEVO ";
                        cout << "\t\n PRESIONE CUALQUIER TECLA PARA CONTINUAR. ";
                        getch();
                        Beep(500, 100);
                        banderaTirar = 1;
                    }
                    limpiarConsola();

                }
                lanzamientosJug2[contadorRondas - 1] = lanzamientos;
            }
        }
        if(empieza){
            empieza = false;
        }else{
            empieza = true;
        }

    }
    promedioLanzamientos = contadorLanzamientos / 10;
    mostrarGanador(nombresJugadores, trufasTotales, contadorOinks1, contadorOinks2, maxLanzamiento1, maxLanzamiento2, nombreGanador, nombreGanador2,puntaje, promedioLanzamientos,lanzamientosJug1, lanzamientosJug2);
}

void mostrarGanador(string nombresJugadores[],int trufasTotales[], int contadorOinks1, int contadorOinks2, int maxLanzamiento1,
                   int maxLanzamiento2, string &nombreGanador, string &nombreGanador2, int &puntaje, int &promedioLanzamientos, int lanzamientosJug1[], int lanzamientosJug2[]){
    limpiarConsola();
    int mayorLanzador, contador1 = 0, contador2 = 0, PDV1 = 0, PDV2 = 0, superarPromedio1 = 0, superarPromedio2 = 0;
    int trufas1 = trufasTotales[0], trufas2 = trufasTotales[1];
    string oinkFinal;
    cout << "\t\t\n GRAN CERDO";
    cout << "\t\t\n -----------------------------------------------------------------------------------------------------------------------";
    cout << "\t\t\n HITO\t\t\t\t " << nombresJugadores[0] << " \t\t\t\t " << nombresJugadores[1];
    cout << "\t\t\n -----------------------------------------------------------------------------------------------------------------------";
    if(trufasTotales[0] > trufasTotales[1]){
        cout << "\t\t\n MÁS TRUFAS EN TOTAL \t" << " 5 PDV (" << trufasTotales[0] << " TRUFAS)\t\t\t 0 PDV (" << trufasTotales[1] << " TRUFAS)";
        PDV1 += 5;
    }else if(trufasTotales[1] > trufasTotales[0]){
        cout << "\t\t\n MÁS TRUFAS EN TOTAL \t" << " 0 PDV (" << trufasTotales[0] << " TRUFAS)\t\t\t 5 PDV (" << trufasTotales[1] << " TRUFAS)";
        PDV2 += 5;
    }else if(trufasTotales[1] == 0 && trufasTotales[0] == 0){
        cout << "\t\t\n MÁS TRUFAS EN TOTAL \t" << " 0 PDV (" << trufasTotales[0] << " TRUFAS)\t\t\t 0 PDV (" << trufasTotales[1] << " TRUFAS)";
    }else{
        cout << "\t\t\n MÁS TRUFAS EN TOTAL \t" << " 5 PDV (" << trufasTotales[0] << " TRUFAS)\t\t\t 5 PDV (" << trufasTotales[1] << " TRUFAS)";
        PDV1 += 5;
        PDV2 += 5;
    }
    while(trufas1 >= 50){
        contador1++;
        trufas1 -= 50;
    }
    while(trufas2 >= 50){
        contador2++;
        trufas2 -= 50;
    }
    PDV1 += contador1 + (contadorOinks1 * 2);
    PDV2 += contador2 + (contadorOinks2 * 2);
    cout << "\t\t\n CADA 50 TRUFAS\t\t " << contador1 << " PDV (" << trufasTotales[0] - trufas1 << " TRUFAS)\t\t\t "<< contador2 << " PDV (" << trufasTotales[1] - trufas2<< " TRUFAS)";
    cout << "\t\t\n OINKS\t\t\t " << 2 * contadorOinks1 << " PDV (" << contadorOinks1 << " OINKS)\t\t\t "<< 2 * contadorOinks2 << " PDV (" << contadorOinks2 << " OINKS)";
    if(maxLanzamiento1 > maxLanzamiento2){
        mayorLanzador = 0;
        cout << "\t\t\n CERDO CODICIOSO\t " << "3 PDV (" << maxLanzamiento1 << " LANZAMIENTOS)\t\t\t 0 PDV (" << maxLanzamiento2 << " LANZAMIENTOS)";
        PDV1 += 3;
    }else if(maxLanzamiento1 < maxLanzamiento2){
        mayorLanzador = 1;
        cout << "\t\t\n CERDO CODICIOSO\t " << "0 PDV (" << maxLanzamiento1 << " LANZAMIENTOS)\t\t\t 3 PDV (" << maxLanzamiento2 << " LANZAMIENTOS)";
        PDV2 += 3;
    }else{
        cout << "\t\t\n CERDO CODICIOSO\t " << "3 PDV (" << maxLanzamiento1 << " LANZAMIENTOS)\t\t\t 3 PDV (" << maxLanzamiento2 << " LANZAMIENTOS)";
        PDV1 += 3;
        PDV2 += 3;
    }
    for(int i = 0; i < 5; i++){
        if(lanzamientosJug1[i] > promedioLanzamientos){
            superarPromedio1++;
        }
    }
    for(int i = 0; i < 5; i++){
        if(lanzamientosJug2[i] > promedioLanzamientos){
            superarPromedio2++;
        }
    }
    cout << "\t\n BONUS EXAMEN\t\t " << superarPromedio1 << " PDV (" << superarPromedio1 << " LANZAMIENTOS)\t\t\t" << superarPromedio2 << " PDV (" << superarPromedio2 << " LANZAMIENTOS)";
    PDV1 += superarPromedio1;
    PDV2 += superarPromedio2;
    cout << "\t\t\n -----------------------------------------------------------------------------------------------------------------------";
    cout << "\t\t\n TOTAL \t\t\t\t" << PDV1 << " PDV \t\t\t\t\t" << PDV2 << " PDV";
    cout << endl << endl;
    if(PDV1 > PDV2){
        cout << "\t\t\n ¡GANADOR DEL JUEGO: " << nombresJugadores[0] << " CON " << PDV1 << " PUNTOS!. ";
        nombreGanador = nombresJugadores[0];
        nombreGanador2 = nombresJugadores[0];
        puntaje = PDV1;
    }else if(PDV2 > PDV1){
        cout << "\t\t\n ¡GANADOR DEL JUEGO: " << nombresJugadores[1] << " CON " << PDV2 << " PUNTOS!. ";
        nombreGanador = nombresJugadores[1];
        nombreGanador2 = nombresJugadores[1];
        puntaje = PDV2;
    }else{
        cout << "\t\t\n ¡EMPATARON EL JUEGO!. ";
        nombreGanador = nombresJugadores[0];
        nombreGanador2 = nombresJugadores[1];
        puntaje = PDV2;
    }
    cin.ignore();

    do{
    cout << "\t\n INGRESE OINK PARA CONTINUAR: ";
    getline(cin, oinkFinal);
    Beep(500, 100);
    }while(oinkFinal != "OINK" && oinkFinal != "oink");
}



int tirarDados(){
    int valor = 0;
    srand(time(NULL) + rand());
    valor = (rand() % 6) + 1;
    return valor;
}

void dibujarDados(int a){
    switch(a){
    case 1:
        cout<<"\t"<<"+-------+"<<endl;
        cout<<"\t"<<"|       |"<<endl;
        cout<<"\t"<<"|   *   |"<<endl;
        cout<<"\t"<<"|       |"<<endl;
        cout<<"\t"<<"+-------+"<<endl;
        break;
    case 2:
        cout<<"\t"<<"+-------+"<<endl;
        cout<<"\t"<<"|   *   |"<<endl;
        cout<<"\t"<<"|       |"<<endl;
        cout<<"\t"<<"|   *   |"<<endl;
        cout<<"\t"<<"+-------+"<<endl;
        break;
    case 3:
        cout<<"\t"<<"+-------+"<<endl;
        cout<<"\t"<<"|   *   |"<<endl;
        cout<<"\t"<<"|   *   |"<<endl;
        cout<<"\t"<<"|   *   |"<<endl;
        cout<<"\t"<<"+-------+"<<endl;
        break;
    case 4:
        cout<<"\t"<<"+-------+"<<endl;
        cout<<"\t"<<"| *   * |"<<endl;
        cout<<"\t"<<"|       |"<<endl;
        cout<<"\t"<<"| *   * |"<<endl;
        cout<<"\t"<<"+-------+"<<endl;
        break;
    case 5:
        cout<<"\t"<<"+-------+"<<endl;
        cout<<"\t"<<"| *   * |"<<endl;
        cout<<"\t"<<"|   *   |"<<endl;
        cout<<"\t"<<"| *   * |"<<endl;
        cout<<"\t"<<"+-------+"<<endl;
        break;
    case 6:
        cout<<"\t"<<"+-------+"<<endl;
        cout<<"\t"<<"| *   * |"<<endl;
        cout<<"\t"<<"| *   * |"<<endl;
        cout<<"\t"<<"| *   * |"<<endl;
        cout<<"\t"<<"+-------+"<<endl;
        break;
    }
}

void limpiarConsola() {
    system("cls");
}
