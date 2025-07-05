/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Lista.h"
#include "Elemento.h"
#include "funcionesLista.h"
#include "NodoArbol.h"
#include "Cola.h"
using namespace std;


void encolar(struct Cola & cola, NodoArbol* elemento){
    insertarAlFinal(cola.lista, elemento); // se utiliza el puntero cola
}

NodoArbol* desencolar(struct Cola & cola){
    if(not cola.lista.cabeza){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(11);
    }
    NodoArbol* elemento = cola.lista.cabeza->elemento;
    eliminaCabeza(cola.lista);
    return elemento;
}


