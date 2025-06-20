/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: kenyi
 * 
 * Created on 19 de junio de 2025, 04:08 PM
 */
#include <iostream>
using namespace std;
#include "Arbol.h"
#include "Nodo.h"
#include "Boleta.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
    eliminaR(raiz);
}

void Arbol::elimina() {
    eliminaR(raiz);
}

void Arbol::eliminaR(Nodo* raiz) {
    if (raiz == nullptr)return;
    eliminaR(raiz->izq);
    eliminaR(raiz->der);
    delete raiz;
}

void Arbol::crear(ifstream& arch) {
    Boleta regBole;

    char tipo;
    while (true) {
        arch>>tipo;
        if (arch.eof())break;
        arch.get();
        regBole.leer(tipo, arch);
        insertarR(raiz, regBole);
    }
    regBole.inicializa();
}

void Arbol::imprime(ofstream& arch) {
    imprimeR(raiz, arch);
}

void Arbol::imprimeR(Nodo* arbol, ofstream& arch) {
    if (arbol) {
        imprimeR(arbol->izq, arch);
        arch << arbol->dboleta;
        imprimeR(arbol->der, arch);
    }
}

void Arbol::insertarR(Nodo*& arbol, Boleta& dato) {
    if (arbol == nullptr) {
        arbol = new Nodo;
        arbol->dboleta = dato;
        return;
    }
    if (arbol->dboleta > dato)
        insertarR(arbol->izq, dato);
    else
        insertarR(arbol->der, dato);
}

void Arbol::cargarEscala(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    int cod;
    double prec;
    while(true){
        arch>>cod;
        if(arch.eof())break;
        arch.get();
        arch>>prec;
        lescala[cod-1].SetCodigo(cod);
        lescala[cod-1].SetPrecio(prec);
    }
}

void Arbol::actualizar() {
    actualizarR(raiz);
}

void Arbol::actualizarR(Nodo* arbol) {
    if(arbol==nullptr)return;
    int esc=arbol->dboleta.getEscala();
    double prec = lescala[esc-1].GetPrecio();
    arbol->dboleta.actualiza(prec);
    actualizarR(arbol->izq);
    actualizarR(arbol->der);
}
