/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 27 de octubre de 2024, 16:56
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "Elemento.h"
#include "ArbolBB.h"
using namespace std;

#include "Pila.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "Cola.h"
#include "ElementoLista.h"

#define N 3

void imprimir(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    if (not tad.cabeza) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas después de la cabeza*/
            if (not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.nodo->elemento.numero;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

void llenarArbol(ArbolBinarioBusqueda &arbol){
    
    Elemento ele;
    
    ele.numero=180;
    ele.emociones[0]="alegria";
    ele.n=1;
    insertar(arbol,ele);
    
    ele.numero=120;
    ele.emociones[0]="verguenza";
    ele.emociones[1]="ansiedad";
    ele.n=2;
    insertar(arbol,ele);
    
    ele.numero=100;
    ele.emociones[0]="temor";
    ele.n=1;
    insertar(arbol,ele);
    
    ele.numero=80;
    ele.emociones[0]="tristeza";
    ele.emociones[1]="verguenza";
    ele.n=2;
    insertar(arbol,ele);
    
    ele.numero=90;
    ele.emociones[0]="aburrimiento";
    ele.n=1;
    insertar(arbol,ele);
    
    ele.numero=150;
    ele.emociones[0]="aburrimiento";
    ele.n=1;
    insertar(arbol,ele);
    
    ele.numero=140;
    ele.emociones[0]="tristeza";
    ele.n=1;
    insertar(arbol,ele);
    
    ele.numero=160;
    ele.emociones[0]="envidia";
    ele.n=1;
    insertar(arbol,ele);
    
    ele.numero=250;
    ele.emociones[0]="desagrado";
    ele.n=1;
    insertar(arbol,ele);
    
    ele.numero=230;
    ele.emociones[0]="tristeza";
    ele.emociones[1]="aburrimiento";
    ele.n=2;
    insertar(arbol,ele);
    
    ele.numero=200;
    ele.emociones[0]="alegria";
    ele.n=1;
    insertar(arbol,ele);
    
    ele.numero=240;
    ele.emociones[0]="temor";
    ele.emociones[1]="envidia";
    ele.n=2;
    insertar(arbol,ele);
    
    ele.numero=280;
    ele.emociones[0]="furia";
    ele.n=1;
    insertar(arbol,ele);
    
    ele.numero=260;
    ele.emociones[0]="ansiedad";
    ele.n=1;
    insertar(arbol,ele);
    
//    ele.numero=270;
//    ele.emociones[0]="ansiedad";
//    ele.n=1;
//    insertar(arbol,ele);
    
}


//buscar(p,combis,cant);

struct Nodo * crearNodo(const struct ElementoLista & elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

void insertarAlFinal(struct Lista & tad, const struct ElementoLista & elemento) {

    //struct Nodo * ultimoNodo = obtenerUltimoNodo(lista);
    struct Nodo * ultimoNodo = tad.cola; /*obtiene el último nodo*/
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

    if (ultimoNodo == nullptr) {/*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
        tad.cola = nuevoNodo;
    } else {//La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
        tad.cola = nuevoNodo;
    }
    tad.longitud++;
}

void encolar(struct Cola & cola, const struct ElementoLista & elemento){
    insertarAlFinal(cola.lista, elemento); // se utiliza el puntero cola
}

void eliminaCabeza(struct Lista & tad) {
    struct Nodo * nodoAEliminar = tad.cabeza;
    if (nodoAEliminar != nullptr) {
        tad.cabeza = tad.cabeza->siguiente;
        if (tad.cabeza == nullptr) /*falta añadir para que coloque*/
            tad.cola = nullptr; /*cola en null*/
        delete nodoAEliminar;
        tad.longitud--;
    }
}

struct ElementoLista desencolar(struct Cola & cola){
    if(not cola.lista.cabeza){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(11);
    }
    struct ElementoLista elemento = cola.lista.cabeza->elemento;
    eliminaCabeza(cola.lista);
    return elemento;
}

void insertarAlInicio(struct Lista & tad, const struct ElementoLista & elemento) {

    struct Nodo * nuevoNodo = crearNodo(elemento, tad.cabeza);
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

void apilar(struct Pila & pila, const struct ElementoLista & elemento) {
    insertarAlInicio(pila.lista, elemento);
}

struct ElementoLista desapilar(struct Pila & pila) {

    if (not pila.lista.cabeza) {
        cout << "La pila está vací­a, por lo tanto no se puede desapilar" << endl;
        exit(11); // valor de salida que indica que existe un error
    }

    struct ElementoLista elemento = pila.lista.cabeza->elemento;
    eliminaCabeza(pila.lista);
    return elemento;

}

void llenarPila(Pila&pila,ArbolBinarioBusqueda arbol,int nivel){
    
    Cola cola;
    cola.lista.cabeza=nullptr;
    cola.lista.cola=nullptr;
    cola.lista.longitud=0;
    
    ElementoLista ele,aux;
    
    ele.nodo=arbol.arbolBinario.raiz;
    ele.nivel=0;
    encolar(cola,ele);
    
    while(cola.lista.cabeza){
        ele=desencolar(cola);
        if(ele.nivel==nivel){
            apilar(pila,ele);
//            cout<<"si"<<endl;
        }
        else{
            if(ele.nodo->izquierda){
                aux.nodo=ele.nodo->izquierda;
                aux.nivel=ele.nivel+1;
                encolar(cola,aux);
            }
            if(ele.nodo->derecha){
                aux.nodo=ele.nodo->derecha;
                aux.nivel=ele.nivel+1;
                encolar(cola,aux);
            }
        }
    }
    
}



bool esta(string palabra,Elemento ele){
    
    for (int i = 0; i < ele.n; i++) {
        if(palabra==ele.emociones[i])
            return true;
    }
    return false;    
}

void revisar(NodoArbol*raiz,string*combi,int&cant){
    
    Pila pila;
    pila.lista.cabeza=nullptr;
    pila.lista.longitud=0;
    
    ElementoLista ele,aux;
    
    ele.nodo=raiz;
    ele.nivel=0;
    
    apilar(pila,ele);
    
    ElementoLista p;
    while(pila.lista.cabeza){
        p=desapilar(pila);
        if(esta(combi[p.nivel],p.nodo->elemento)){
            if(p.nivel==N-1)
                cant++;
            if(p.nodo->derecha){
                aux.nodo=p.nodo->derecha;
                aux.nivel=p.nivel+1;
                apilar(pila,aux);
            }
            if(p.nodo->izquierda){
                aux.nodo=p.nodo->izquierda;
                aux.nivel=p.nivel+1;
                apilar(pila,aux);
            }
        }
    }
}

void buscar(NodoArbol*raiz,string combis[][N],int&cant){
    
    for (int i = 0; i < N; i++) {
        revisar(raiz,combis[i],cant);
    }

}


int main(int argc, char** argv) {

    ArbolBinarioBusqueda arbol;
    construir(arbol);
    
    llenarArbol(arbol);
//    enOrden(arbol);
    cout<<endl;
    string combis[][N]{
    {"ansiedad","aburrimiento","tristeza"},
    {"desagrado","tristeza","temor"},
    {"temor","verguenza","aburrimiento"}
    };
    
    Pila pila;
    pila.lista.cabeza=nullptr;
    pila.lista.longitud=0;
    int cant;
    
    NodoArbol*p;
    for (int i = 0; i <N; i++) {
        llenarPila(pila,arbol,i);
        cout<<endl;
        cout<<"Nodos del nivel "<<i+1<<": ";
        imprimir(pila.lista);
        cant=0;
        while(pila.lista.cabeza){
            p=desapilar(pila).nodo;
            buscar(p,combis,cant);
        }
        cout<<"Nivel: "<<i+1<<" - "<<cant<<endl;
    }

    return 0;
}
