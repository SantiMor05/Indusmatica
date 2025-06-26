/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NEstante.h
 * Author: santi
 *
 * Created on 25 de junio de 2025, 22:29
 */

#ifndef NESTANTE_H
#define NESTANTE_H

#include <vector>
#include "NLibro.h"
//#include "Arbol.h"
//#include "Arbol.h"

class NEstante {
private:
    int id;
    double capacidad;
    double disponible;
    vector <NLibro> vlibros;
    NEstante *izq;
    NEstante *der;
    
public:
    NEstante();
//    NEstante(const NEstante& orig);
    virtual ~NEstante();
    void SetDisponible(double disponible);
    double GetDisponible() const;
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void inicializa();   
    friend class Arbol;
    
};

#endif /* NESTANTE_H */

