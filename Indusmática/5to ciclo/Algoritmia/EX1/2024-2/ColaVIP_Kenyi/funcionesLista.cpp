/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 12:11 PM
 */

#include <iostream>
#include <iomanip> /*formato de números*/
#include <fstream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

/*Valores iniciales de la lista*/
void construir(struct Lista & tad) {
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.longitud = 0;
}

void construirPrioridad(struct Lista & tad) {
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.vip = nullptr;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
const bool esListaVacia(const struct Lista & tad) {
    return tad.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista  & tad) {
    return tad.longitud;
}

/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & tad, int elemento) {

    /*Se va cambiar por la función crear nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = tad.cabeza;

    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

/*inserta un nodo siempre al final de la lista*/
void insertarAlFinal(struct Lista & tad, int elemento) {

    struct Nodo * ultimoNodo = obtenerUltimoNodo(tad);
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

    if (ultimoNodo == nullptr) /*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    tad.longitud++;
}
/*inserta un nodo siempre al final de la cola*/
void insertarencola(struct Lista & tad, int elemento) {

    struct Nodo * ultimoNodo = tad.cola;
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

    if (ultimoNodo == nullptr){/*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
        tad.cola = nuevoNodo;
    } 
    else{ //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
        tad.cola = nuevoNodo;
    }
    tad.longitud++;
}

void insertarencolaPrioridad(struct Lista & tad, int elemento, char prioridad) {
    struct Nodo * nuevoNodo = crearNodoPrioridad(elemento, prioridad, nullptr);
    if (esListaVacia(tad)){
        tad.cabeza = nuevoNodo;
        tad.cola = nuevoNodo;
        if (prioridad=='V'){
            tad.vip = nuevoNodo;
        }
    }
    else{
        if (prioridad=='V'){
            if (tad.vip == nullptr){
                nuevoNodo->siguiente = tad.cabeza;
                tad.cabeza = nuevoNodo;
                tad.vip = nuevoNodo;
            }
            else{
                if (tad.vip->siguiente==nullptr){
                    tad.cola = nuevoNodo;
                }
                nuevoNodo->siguiente = tad.vip->siguiente;
                tad.vip->siguiente = nuevoNodo;
                tad.vip = nuevoNodo;
            }
        }
        else{
            tad.cola->siguiente = nuevoNodo;
            tad.cola = nuevoNodo;        
        }
    }
    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(int elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodoPrioridad(int elemento, char prioridad, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    nuevoNodo->prioridad = prioridad;
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

/*inserta nodos al inicio de la lista desde un archivo*/
void insertarAlInicioArchivo(const char * nombArchText, struct Lista & tad) {
    ifstream archText(nombArchText, ios::in);
    if (not archText.is_open()) {
        cout << "ERROR: No se puede abrir el archivo";
        exit(1);
    }

    int elemento;
    while (true) {
        archText>>elemento; //lee el elemento del archivo
        if (archText.eof()) break;
        insertarAlInicio(tad, elemento);
    }
}

/*inserta un nodo en orden*/
void insertarEnOrden(struct Lista & tad, int elemento) {

    struct Nodo * nodoAnterior = obtenerNodoAnterior(tad, elemento);
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);
    /*Si nodoAnterior es igual a nulo, la lista está vacia, se debe
     insertar al inicio, no hay nodos menores que elemento*/
    if (nodoAnterior == nullptr) { /*la lista está vacia*/
        nuevoNodo->siguiente = tad.cabeza;
        tad.cabeza = nuevoNodo;
    } else {
        nuevoNodo->siguiente = nodoAnterior->siguiente;
        nodoAnterior->siguiente = nuevoNodo;
    }
    tad.longitud++;
}

/*retorna el anterior al que tiene el elemento*/
struct Nodo * obtenerNodoAnterior(const struct Lista & tad, int elemento) {
    struct Nodo * anterior = nullptr;
    struct Nodo * recorrido = tad.cabeza;
    while ((recorrido != nullptr) and (recorrido->elemento < elemento)) {
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    return anterior;
}

struct Nodo * seEncuentra(const struct Lista & tad, int elemento) {
    struct Nodo * recorrido = tad.cabeza;

    /*retorna el nodo correspondiente al elemento buscado*/
    while ((recorrido != nullptr) and (recorrido->elemento != elemento)) {
        recorrido = recorrido->siguiente;
    }
    return recorrido;
}

char retornaCabeza(const struct Lista & tad){
    return tad.cabeza->prioridad;
}


void eliminaNodo(struct Lista & tad, int elemento) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * recorrido = tad.cabeza;
    /*Avanzo hasta encontrar el elemento*/
    /*Si no lo encuentra no elimina nada*/
    while ((recorrido != nullptr) and (recorrido->elemento != elemento)) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr) /*Estoy al inicio de la lista*/
            tad.cabeza = recorrido->siguiente;
        else
            ultimo->siguiente = recorrido->siguiente;
        delete recorrido; /*libera la memoria*/
        tad.longitud--;
    }
}

void eliminaCabeza(struct Lista & tad) {
    struct Nodo * nodoAEliminar = tad.cabeza;
    if (nodoAEliminar != nullptr) {
        tad.cabeza = tad.cabeza->siguiente;
        delete nodoAEliminar;
        tad.longitud--;
    }
}

/*Elimina el último elemento de la lista, es llamado cola*/
void eliminaCola(struct Lista & tad) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * penultimo = nullptr;
    struct Nodo * recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        if (ultimo != nullptr)
            penultimo = ultimo;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (ultimo != nullptr) {
        //Si no hay penultimo, se está¡ eliminando el Único nodo de la lista
        if (penultimo == nullptr)
            tad.cabeza = nullptr;
        else
            penultimo->siguiente = nullptr;
        delete ultimo;
        tad.longitud--;
    }
}

void destruir(struct Lista & tad) {
    /*recorrido apunta al inicio del tad*/
    struct Nodo * recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la prOteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo tad.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(tad)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

void imprimePrioridad(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(tad)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << "(" << recorrido->elemento << "," << recorrido->prioridad << ") ";
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}