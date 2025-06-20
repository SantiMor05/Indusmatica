/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.h
 * Author: kenyi
 *
 * Created on 19 de junio de 2025, 04:19 PM
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Arbol.h"


class Tesoreria {
private:
    Arbol aboleta;
public:
    void cargaalumnos();
    void actualizaboleta();
    void imprimeboleta();

};

#endif /* TESORERIA_H */

