/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: 00123
 *
 * Created on 18 de junio de 2025, 07:47 PM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include <fstream>
#include "Nodo.h"
using namespace std;

class Arbol {
public:
    Arbol();
//    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void leer(ifstream&arch);
    
    void imprimir(ofstream&arch);
    
    void actualiza(ifstream&arch);
private:
    void analizarRecur(class Nodo*p,int codigo);
    void eliminaRecur(class Nodo*raiz);
    void insertarRecur(class Nodo*&p,class Medicamento*med);
    void imprimeRecur(Nodo*p,ofstream&arch);
    class Nodo*raiz;
};

#endif /* ARBOL_H */

