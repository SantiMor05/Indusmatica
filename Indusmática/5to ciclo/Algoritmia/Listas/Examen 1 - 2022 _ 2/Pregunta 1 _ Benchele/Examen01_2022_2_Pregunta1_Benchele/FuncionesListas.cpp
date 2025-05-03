/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Lista.h"
#include "Elemento.h"
#include "FuncionesListas.h"
using namespace std;

/*Valores iniciales de la lista*/
void construir(struct Lista & tad) {
    tad.cabeza = nullptr;
    tad.longitud = 0;
    tad.cola = nullptr;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
bool esListaVacia(const struct Lista & tad) {
    return tad.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista  & tad) {
    return tad.longitud;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(const struct Elemento & elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}


//Notar que esta función retorna nulo cuando la lista es vacía

/*Obtiene el último nodo de la lista*/
struct Nodo * obtenerUltimoNodo(const struct Lista & tad) {
    struct Nodo * ultimo = nullptr;
    struct Nodo* recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}


/*retorna el anterior al que tiene el elemento*/
struct Nodo * obtenerNodoAnterior(const struct Lista & tad, struct Elemento elemento) {
    struct Nodo * anterior = nullptr;
    struct Nodo * recorrido = tad.cabeza;
    while ((recorrido != nullptr) and (recorrido->elemento.hora < elemento.hora or 
            recorrido->elemento.hora == elemento.hora and recorrido->elemento.diaPriori < elemento.diaPriori)) {
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    return anterior;
}


/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(tad)) {
        cout << "La lista está vacía" << endl;
        return;
    } 
    else{
        bool esCabeza = false;
        struct Nodo *recorrido = tad.cabeza;
        
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas después de la cabeza*/
            if (esCabeza){
                cout << " -> ";
            }  
            esCabeza = true;
            cout << recorrido->elemento.hora<<"("<< recorrido->elemento.sucursal<<") ";
            cout<<"("<<verificarDia(recorrido->elemento.diaPriori)<<")";
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    
    }
}

char* verificarDia(int num){
    char *dia;
    switch(num){
        case 1:
            dia = new char[strlen("Lunes") + 1];
            strcpy(dia, "Lunes");
            break;
        case 2:
            dia = new char[strlen("Martes") + 1];
            strcpy(dia, "Martes");
            break;
        case 3:
            dia = new char[strlen("Miercoles") + 1];
            strcpy(dia, "Miercoles");
            break;
        case 4:
            dia = new char[strlen("Jueves") + 1];
            strcpy(dia, "Jueves");
            break;
        case 5:
            dia = new char[strlen("Viernes") + 1];
            strcpy(dia, "Viernes");
            break;
        default:
            break;
    }
    return dia;
}
