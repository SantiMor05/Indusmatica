/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Lenovo
 * 
 * Created on 26 de junio de 2025, 05:25 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbol.h"
#include "NEstante.h"
using namespace std;

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
}

/*
 1,20
 2,10
 ID CAPACIDAD
 */
void Arbol::carga(ifstream &archEstante, ifstream &archLibro){
    class NEstante *nodo;
    int id;
    double capa;
    while (true) {
        archEstante >> id;
        if(archEstante.eof())break;
        archEstante.get();
        archEstante>>capa;
        nodo = new NEstante;
        nodo->SetId(id);
        nodo->SetCapacidad(capa);
        nodo->SetDisponible(capa);
        nodo->leerLibros(archLibro);
        insertarR(raiz, nodo);
        
    }

}

void Arbol::insertarR(class NEstante *&arbol, class NEstante *nuevo){
    if(arbol == nullptr){
        arbol = new class NEstante;
        arbol = nuevo;
        return;
    }
    if(nuevo->GetDisponible() < arbol->GetDisponible()){
        insertarR(arbol->izq, nuevo);
    }
    else{
        insertarR(arbol->der, nuevo);
    }
}

void Arbol::imprimir(ofstream &arch){
    imprimirRec(arch, raiz);
}
void Arbol::imprimirRec(ofstream &arch, class NEstante *arbol){
    if(arbol){
        imprimirRec(arch, arbol->izq);
        arbol->imprime(arch);
        imprimirRec(arch, arbol->der);
    }
}

void Arbol::esAsignado(ofstream &arch, double peso){
    bool encontrado = false;
    encontrarEImprimirR(arch, peso, raiz, encontrado);
    if(not encontrado){
        arch << "No es posible colocar el libro" << endl;
    }
}

void Arbol::encontrarEImprimirR(ofstream &arch, double peso, class NEstante *arbol, bool &encontrado){
    if (arbol == nullptr) return;

    encontrarEImprimirR(arch, peso, arbol->izq, encontrado);

    if (arbol->disponible >= peso) {
        arch<<"Si hay espacio"<<endl;
        arbol->imprime(arch);
        encontrado = true;
    }

    encontrarEImprimirR(arch, peso, arbol->der, encontrado);
}