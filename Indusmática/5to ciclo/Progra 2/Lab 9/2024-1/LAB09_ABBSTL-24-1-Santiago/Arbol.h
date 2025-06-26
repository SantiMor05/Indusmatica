/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: santi
 *
 * Created on 25 de junio de 2025, 22:33
 */

#ifndef ARBOL_H
#define ARBOL_H

//#include "NEstante.h"
#include <fstream>

#include "NEstante.h"
using namespace std;

class Arbol {
private:
    NEstante *raiz;
    void leerLibros(ifstream &archLibros, NEstante *estante);
    void insertarR(NEstante *&raiz, NEstante *estante);
    void imprimeR(ofstream &arch, NEstante *raiz);
    void imprimirLinea(ofstream &arch, char car);
    void buscaR(ofstream &arch, double num, NEstante*raiz);
    void imprimeEstante(ofstream &arch, NEstante*raiz);
public:
    Arbol();
//    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void inicializa();
    void carga(ifstream &archEstantes, ifstream &archLibros);
    void imprime(ofstream &arch);
    void busca(ofstream &arch, double num);
};

#endif /* ARBOL_H */

