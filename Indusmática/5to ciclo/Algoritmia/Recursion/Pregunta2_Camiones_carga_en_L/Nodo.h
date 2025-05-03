/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Usuario
 *
 * Created on 2 de mayo de 2025, 08:39 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Elemento.h"

struct Nodo{
    struct Elemento elemento;
    struct Nodo *siguiente;
};

#endif /* NODO_H */

