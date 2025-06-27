/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NEstante.h
 * Author: Lenovo
 *
 * Created on 26 de junio de 2025, 05:24 PM
 */

#ifndef NESTANTE_H
#define NESTANTE_H

#include <vector>
#include <fstream>
#include "NLibro.h"
using namespace std;

class NEstante {
    
private:
    int id;
    double capacidad;
    double disponible;
    vector<class NLibro> vLibros;
    class NEstante *izq;
    class NEstante *der;
public:
    NEstante();
    NEstante(const NEstante& orig);
    virtual ~NEstante();
    void SetDisponible(double disponible);
    double GetDisponible() const;
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;

    friend class Arbol;
    
    void leerLibros(ifstream &arch);
    void imprime(ofstream &arch);
    void imprimirLinea(ofstream &arch, char linea);
};

#endif /* NESTANTE_H */

