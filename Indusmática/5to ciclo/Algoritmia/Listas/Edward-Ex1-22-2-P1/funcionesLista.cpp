///* 
// * File:   FuncionesAuxiliares.cpp
// * Author: ANA RONCAL
// * Created on 11 de abril de 2025, 2:45 PM
// */
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Lista.h"
#include "Elemento.h"
#include "funcionesLista.h"
using namespace std;
///*Valores iniciales de la lista*/
void construir(struct Lista & tad) {
    tad.cabeza = nullptr;
    tad.longitud = 0;
}
//
///*devuelve si la lista esta vacia 1, caso contrario 0 */
bool esListaVacia(const struct Lista & tad) {
    return tad.cabeza == nullptr;
}
//
///*devuelve la longitud de la lista*/
//int longitud(const struct Lista  & tad) {
//    return tad.longitud;
//}
//
///*inserta un  struct Nodo * nuevoNodo = new struct Nodo; nodo siempre al inicio de la lista*/
//void insertarAlInicio(struct Lista & tad, int numero) {
//
//    struct Elemento elemento;
//    elemento.numero = numero;
//  
//    struct Nodo * nuevoNodo = crearNodo(elemento, tad.cabeza);
//    tad.cabeza = nuevoNodo;
//    tad.longitud++;
//}
//
///*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(const struct Elemento & elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}
//
///*inserta un nodo siempre al final de la lista*/
//void insertarAlFinal(struct Lista & tad, int numero) {
//
//    struct Elemento elemento;
//    elemento.numero = numero;
//   
//    struct Nodo * ultimoNodo = obtenerUltimoNodo(tad);
//    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);
//
//    if (ultimoNodo == nullptr) /*Si la lista está vacia*/
//        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
//    else //La lista ya tiene nodos
//        ultimoNodo->siguiente = nuevoNodo;
//    tad.longitud++;
//}
//
////Notar que esta función retorna nulo cuando la lista es vacía
//
///*Obtiene el último nodo de la lista*/
struct Nodo * obtenerUltimoNodo(const struct Lista & tad) {
    struct Nodo * ultimo = nullptr;
    struct Nodo* recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}
//
///*inserta nodos al inicio de la lista desde un archivo*/
//void insertarAlInicioArchivo(const char * nombArchText, struct Lista & tad) {
//    ifstream archText(nombArchText, ios::in);
//    if (not archText.is_open()) {
//        cout << "ERROR: No se puede abrir el archivo";
//        exit(1);
//    }
//
//    int numero;
//    while (true) {
//        archText>>numero; //lee el elemento del archivo
//        if (archText.eof()) break;
//        insertarAlInicio(tad, numero);
//    }
//}
//
///*inserta un nodo en orden*/
//
///*retorna el anterior al que tiene el elemento*/
//struct Nodo * obtenerNodoAnterior(const struct Lista & tad, int elemento) {
//    struct Nodo * anterior = nullptr;
//    struct Nodo * recorrido = tad.cabeza;
//    while ((recorrido != nullptr) and (recorrido->elemento.numero < elemento)) {
//        anterior = recorrido;
//        recorrido = recorrido->siguiente;
//    }
//    return anterior;
//}
//
//struct Nodo * seEncuentra(const struct Lista & tad, int elemento) {
//    struct Nodo * recorrido = tad.cabeza;
//
//    /*retorna el nodo correspondiente al elemento buscado*/
//    while ((recorrido != nullptr) and (recorrido->elemento.numero != elemento)) {
//        recorrido = recorrido->siguiente;
//    }
//    return recorrido;
//}
//
//int retornaCabeza(const struct Lista & lista){
//    return lista.cabeza->elemento.numero;
//}
//
///*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    const char* dia;
    if (esListaVacia(tad)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas después de la cabeza*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.hora;
            cout <<"("<< recorrido->elemento.sucursal<<") ";
            dia=hallarDia(recorrido->elemento.dia);
            cout<<"("<<dia<<")";
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

const char*hallarDia(int num){
    
    switch(num){
        case 0:
            return "Lunes";
            break;
        case 1:
            return "Martes";
            break;
        case 2:
            return "Miercoles";
            break;
        case 3:
            return "Jueves";
            break;
        case 4:
            return "Viernes";
            break;
        default:
            cout<<"AAAA";
            break;
    }
}
