/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: kenyi
 *
 * Created on 19 de junio de 2025, 04:08 PM
 */

#ifndef ARBOL_H
#define ARBOL_H
#include <fstream>
using namespace std;
#include "Escala.h"
#include "Boleta.h"
#include "Nodo.h"

class Arbol {
private:
    Nodo *raiz;
    Escala lescala[10];
    void eliminaR(Nodo *raiz);
    void insertarR(Nodo *&raiz,Boleta &boleta);
    void imprimeR(Nodo *raiz,ofstream &arch);
    void actualizarR(Nodo *raiz);
public:
    Arbol();
    virtual ~Arbol();
    void elimina();
    void crear(ifstream &arch);
    void imprime(ofstream &arch);
    void cargarEscala(const char*nombArch);
    void actualizar();
};

#endif /* ARBOL_H */

