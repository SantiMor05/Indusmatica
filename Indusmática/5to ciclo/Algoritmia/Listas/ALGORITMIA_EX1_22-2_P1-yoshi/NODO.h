/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   NODO.h
 * Author: Usuario
 *
 * Created on 2 de mayo de 2025, 17:16
 */

#ifndef NODO_H
#define NODO_H

#include "ELEMENTO.h"

struct Nodo{
    struct Elemento elemento;
    Nodo* siguiente;
};

#endif /* NODO_H */

