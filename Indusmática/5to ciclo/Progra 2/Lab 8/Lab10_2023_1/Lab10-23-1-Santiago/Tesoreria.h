/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.h
 * Author: santi
 *
 * Created on 19 de junio de 2025, 21:37
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Arbol.h"

class Tesoreria {
private:
    Arbol aboleta;
    
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    
    void cargaalumnos();
    void imprimeBoleta();
    void actualizaboleta();
};

#endif /* TESORERIA_H */

