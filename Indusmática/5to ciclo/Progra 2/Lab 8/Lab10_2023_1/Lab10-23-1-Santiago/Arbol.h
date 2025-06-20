/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 21:32
 */

#ifndef ARBOL_H
#define ARBOL_H

#include <fstream>
using namespace std;

#include "Boleta.h"
#include "Nodo.h"
#include "Escala.h"


class Arbol {
private:
    Nodo *raiz;
    Escala lescala[5];
    void insertaR(Nodo *&raiz, Boleta &boleta);
    void imprimeR(Nodo *raiz, ofstream &arch);
    void recorreActualiza(Nodo *raiz);
public:
    Arbol();
//    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void cargaalumnos(ifstream &arch);
    void imprimeBoletas(ofstream &arch);
    void leerEscalas(ifstream &arch);
    void actualizaArbol();
};

#endif /* ARBOL_H */

