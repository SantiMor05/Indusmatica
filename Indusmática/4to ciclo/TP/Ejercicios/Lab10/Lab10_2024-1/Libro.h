/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: santi
 *
 * Created on 24 de noviembre de 2024, 11:47
 */

#ifndef LIBRO_H
#define LIBRO_H

#include "Venta.h"

struct Libro{
    char codigo[8];
    char titulo[65];
    char autor[40];
    double precio;
    struct Venta ventas[10];
    int librosVendidos;
    struct Fecha fechaMasReciente;
    int sumaCalificaciones;
    int ranking;
};

#endif /* LIBRO_H */

