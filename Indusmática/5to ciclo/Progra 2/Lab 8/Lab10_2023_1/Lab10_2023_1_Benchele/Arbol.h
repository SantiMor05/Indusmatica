/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Lenovo
 *
 * Created on 18 de junio de 2025, 08:46 PM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include <fstream>


#include "Escala.h"
using namespace std;

class Arbol {
    
private:
    class Nodo *raiz;
    class Escala lEscala[10];
    
    //Recursivos
    void insertarRec(class Nodo *&arbol, const class Boleta &boleta);
    void mostrarEnOrdenRec(ofstream &arch, class Nodo *arbol);
    void actualizaBoletaRec(class Nodo *arbol);
    void eliminaRec(class Nodo *raiz);
public:
    Arbol();
    virtual ~Arbol();
    
    void cargarEscalas(ifstream &arch);
    void crear(ifstream &arch);
    void insertar(const class Boleta &bol);
    void actualizaBoleta();
    void mostrarEnOrden(ofstream &arch);
    void imprimirLinea(ofstream &arch, char linea);
    void eliminar();
    
};

#endif /* ARBOL_H */

