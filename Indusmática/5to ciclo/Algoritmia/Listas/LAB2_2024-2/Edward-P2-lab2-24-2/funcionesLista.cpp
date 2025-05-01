/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Lista.h"
#include "Elemento.h"
#include "funcionesLista.h"
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

/*inserta un  struct Nodo * nuevoNodo = new struct Nodo; nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & tad, Elemento &elemento) {
    
    struct Nodo * nuevoNodo = crearNodo(elemento, tad.cabeza);
    
    if(not tad.cabeza){
        tad.cola=nuevoNodo;
    }
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(const struct Elemento & elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

/*inserta un nodo siempre al final de la lista*/
void insertarAlFinal(struct Lista & tad, Elemento &elemento) {

//    struct Nodo * ultimoNodo = obtenerUltimoNodo(tad);
//    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);
//
//    if (ultimoNodo == nullptr) /*Si la lista está vacia*/
//        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
//    else //La lista ya tiene nodos
//        ultimoNodo->siguiente = nuevoNodo;
//    tad.longitud++;
//    tad.cola = nuevoNodo;
}

//Notar que esta función retorna nulo cuando la lista es vacía

/*Obtiene el último nodo de la lista*/
struct Nodo * obtenerUltimoNodo(const struct Lista & tad) {
//    struct Nodo * ultimo = nullptr;
//    struct Nodo* recorrido = tad.cabeza;
//
//    while (recorrido != nullptr) {
//        ultimo = recorrido;
//        recorrido = recorrido->siguiente;
//    }
//    return ultimo;
}

/*inserta nodos al inicio de la lista desde un archivo*/
void insertarAlInicioArchivo(const char * nombArchText, struct Lista & tad) {
    ifstream archText(nombArchText, ios::in);
    if (not archText.is_open()) {
        cout << "ERROR: No se puede abrir el archivo";
        exit(1);
    }

    Elemento elemento;
    while (true) {
        archText>>elemento; //lee el elemento del archivo
        if (archText.eof()) break;
        insertarAlInicio(tad, elemento);
    }
}


//----------NUEVO
void operator >>(ifstream &arch,Elemento &elemento){
    
    arch.getline(elemento.id,5,',');
    if(arch.eof())return;
    completarElemento(arch,elemento);
}


//P001, m, 1, 12.5, 0
void completarElemento(ifstream &arch,Elemento &elemento){
    
    char complejidad,c;
    int perDispo,esPunta;
    double distancia;
    
    arch>>complejidad>>c>>perDispo>>c>>distancia>>c>>esPunta;
    arch.get();
    
    elemento.tiempoPrepa=hallarPrepa(complejidad,perDispo);
    elemento.tiempoEstViaje=hallarEstViaje(distancia,esPunta);
}

int hallarPrepa(char complejidad,int perDispo){
    
    int tiempo;
    if(complejidad=='b')tiempo=10;
    else if(complejidad=='m')tiempo=20;
    else tiempo=30;
    
    if(perDispo)tiempo+=5;
    return tiempo;
}

int hallarEstViaje(double distancia,int esPunta){
    
    int tiempo;
    
    tiempo=(distancia/45)*60;
    
    if(esPunta)tiempo+=10;
    return tiempo;
}


//------------------------

/*retorna el anterior al que tiene el elemento*/
struct Nodo * obtenerNodoAnterior(const struct Lista & tad, int elemento) {
//    struct Nodo * anterior = nullptr;
//    struct Nodo * recorrido = tad.cabeza;
//    while ((recorrido != nullptr) and (recorrido->elemento.numero < elemento)) {
//        anterior = recorrido;
//        recorrido = recorrido->siguiente;
//    }
//    return anterior;
}

struct Nodo * seEncuentra(const struct Lista & tad, int elemento) {
//    struct Nodo * recorrido = tad.cabeza;
//
//    /*retorna el nodo correspondiente al elemento buscado*/
//    while ((recorrido != nullptr) and (recorrido->elemento.numero != elemento)) {
//        recorrido = recorrido->siguiente;
//    }
//    return recorrido;
}

int retornaCabeza(const struct Lista & lista){
//    return lista.cabeza->elemento.numero;
}

void destruir(struct Lista & tad) {
//    /*recorrido apunta al inicio del tad*/
//    struct Nodo * recorrido = tad.cabeza;
//
//    while (recorrido != nullptr) {
//        /*Nodo auxiliar que va servir para eliminar los nodos*/
//        struct Nodo * nodoAEliminar = recorrido;
//        recorrido = recorrido->siguiente;
//        delete nodoAEliminar;
//    }
//    /*la lista queda vacia*/
//    tad.cabeza = nullptr;
//    tad.longitud = 0;
}

/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la prOteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo tad.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    int tiempoTot;
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
            tiempoTot=recorrido->elemento.tiempoEstViaje+
                    recorrido->elemento.tiempoPrepa;
            cout<<recorrido->elemento.id<<" ";
            cout << tiempoTot;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

void ordenar(Lista &lista,bool condi){
    
    Nodo *aux=nullptr;
    Nodo *ant=lista.cabeza;
    if(not ant)return;
    Nodo *p=ant->siguiente;
    if(not p)return;
    int tiempoP,tiempoAnt;
    int digitoP,digitoAnt;
    int n=lista.longitud;
    for (int i = 1; i < n; i++) {
        while(p){
            tiempoP=p->elemento.tiempoEstViaje+ p->elemento.tiempoPrepa;
            tiempoAnt=ant->elemento.tiempoEstViaje+ant->elemento.tiempoPrepa;
            sacarDigitos(digitoP,digitoAnt,tiempoP,tiempoAnt,condi);
            if(digitoP<digitoAnt){
                ant->siguiente=p->siguiente;
                p->siguiente=ant;
                if(not aux) lista.cabeza=p;
                else aux->siguiente=p;
                aux=p;
                p=ant->siguiente;
            }
            else{
                aux=ant;
                ant=p;
                p=p->siguiente;
            }
        }
        aux=nullptr;
        ant=lista.cabeza;
        p=ant->siguiente;
    }
}

void sacarDigitos(int &digitoP,int &digitoAnt,int tiempoP,int tiempoAnt,
        bool condi){
    
    if(condi){
        digitoP=tiempoP%10;
        digitoAnt=tiempoAnt%10;
    }
    else{
        digitoP=tiempoP/10;
        digitoAnt=tiempoAnt/10;
    }
}
