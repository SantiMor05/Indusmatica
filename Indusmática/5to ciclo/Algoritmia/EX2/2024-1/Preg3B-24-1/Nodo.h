/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#ifndef NODO_H
#define NODO_H
#include "Elemento.h"
/*Nodo esta formado por Elemento y un puntero al siguiente Nodo*/
struct Nodo {
    struct Elemento elemento; /*Dato que cambia por double, char, struct */
    struct Nodo * siguiente; /*puntero a una variable de tipo struct Nodo*/
};

#endif /* NODO_H */

