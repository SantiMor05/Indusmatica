/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Lenovo
 *
 * Created on 26 de junio de 2025, 05:25 PM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include <fstream>


using namespace std;

class Arbol {
    
private:
    class NEstante *raiz;
    
    void insertarR(class NEstante *&arbol, class NEstante *nuevo);
    void imprimirRec(ofstream &arch, class NEstante *raiz);
    void encontrarEImprimirR(ofstream &arch, double peso, class NEstante *arbol, bool &encontrado);
public:
    Arbol();
    Arbol(const Arbol& orig);
    virtual ~Arbol();

    void carga(ifstream &archEstante, ifstream &archLibro);
    void imprimir(ofstream &arch);
    void esAsignado(ofstream &arch, double peso);
};

#endif /* ARBOL_H */

