/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: santi
 * 
 * Created on 25 de junio de 2025, 22:33
 */

#include "Arbol.h"
#include "NLibro.h"
#include "NEstante.h"
#include <iomanip>

#define MAX_CAR 100

Arbol::Arbol() {
    inicializa();
}
//
//Arbol::Arbol(const Arbol& orig) {
//}

Arbol::~Arbol() {

}

void Arbol::inicializa() {
    raiz = nullptr;
}

void Arbol::carga(ifstream &arch, ifstream &archLibros) {

    NEstante *estante;
    int id;
    while (true) {
        arch >> id;
        if (arch.eof())break;
        estante = new NEstante;
        estante->id = id;
        arch.get();
        arch >> estante->capacidad;
        estante->disponible = estante->capacidad;

        leerLibros(archLibros, estante);
        insertarR(raiz, estante);

    }

}

void Arbol::insertarR(NEstante *&raiz, NEstante *estante) {

    if (raiz == nullptr) {
        raiz = new NEstante;
        raiz = estante;
    } else {
        if (raiz->GetDisponible() > estante->GetDisponible())
            insertarR(raiz->izq, estante);
        else
            insertarR(raiz->der, estante);
    }
}

void Arbol::leerLibros(ifstream &archLibros, NEstante *estante) {

    char car;
    NLibro libro;

    for (int i = 0; i < 10; i++) {
        archLibros >> car;
        archLibros.get();
        libro.asignaTipo(car);
        libro.lee(archLibros);
        if (estante->disponible - libro.getPeso() >= 0) {
            estante->vlibros.push_back(libro);
            estante->disponible -= libro.getPeso();
        }

        //        vlibros.push_back(libro);
    }
    libro.inicializa();
}

void Arbol::imprime(ofstream &arch) {

    imprimeR(arch, raiz);
}

void Arbol::imprimeR(ofstream &arch, NEstante *raiz) {

    if (raiz == nullptr)return;

    imprimeR(arch, raiz->izq);
    imprimeEstante(arch, raiz);
    imprimeR(arch, raiz->der);



}

void Arbol::imprimirLinea(ofstream &arch, char car) {

    for (int i = 0; i < MAX_CAR; i++)
        arch.put(car);
    arch << endl;
}

void Arbol::busca(ofstream &arch, double num) {

    buscaR(arch, num, raiz);

}

void Arbol::buscaR(ofstream &arch, double num, NEstante*raiz) {

    if (raiz == nullptr) {
        arch << "No es posible colocar el libro" << endl;
        return;
    }

    if (raiz->disponible >= num) 
        imprimeEstante(arch, raiz);
    else
        buscaR(arch, num, raiz->der);

}

void Arbol::imprimeEstante(ofstream &arch, NEstante *raiz) {

    arch << "Estante: " << raiz->id << endl;
    arch << "Capacidad: " << setw(4) << raiz->capacidad << setw(20) <<
            "Disponible: " << setw(5) << raiz->disponible << endl;
    imprimirLinea(arch, '=');
    for (auto &x : raiz->vlibros) {
        x.imprime(arch);
        arch << endl;

    }
}