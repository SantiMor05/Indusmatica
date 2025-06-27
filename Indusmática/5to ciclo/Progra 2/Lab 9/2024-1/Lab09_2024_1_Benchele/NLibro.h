/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NLibro.h
 * Author: Lenovo
 *
 * Created on 26 de junio de 2025, 05:23 PM
 */

#ifndef NLIBRO_H
#define NLIBRO_H

#include <fstream>
#include "NEstante.h"
using namespace std;


class NLibro {
    
private:
    class Libro *pLibro;
public:
    NLibro();
    NLibro(const NLibro& orig);
    virtual ~NLibro();

    void asignaMemoria(char tipo);
    void leer(ifstream &arch);
    
    double getPeso()const;
    
    void imprimir(ofstream &arch);
};

#endif /* NLIBRO_H */

