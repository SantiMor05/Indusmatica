/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Lenovo
 *
 * Created on 26 de junio de 2025, 05:26 PM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <fstream>
#include "Arbol.h"
using namespace std;

class Biblioteca {
    
private:
    class Arbol AEstante;
public:
    void carga(const char*nombArchLibro, const char*nombArchEstante);

    void imprime(const char*nombArch);
    void imprimirLinea(ofstream &arch, char linea);
    
    //Prueba
    void prueba(const char*nombArch, double peso);
};

#endif /* BIBLIOTECA_H */

