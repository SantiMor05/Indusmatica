/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: kenyi
 *
 * Created on 24 de noviembre de 2024, 02:07 PM
 */
#include "Fecha.h"
#include "Venta.h"

#ifndef LIBRO_H
#define LIBRO_H
struct Libro{
    char codigo[10];
    char titulo[60];
    char autor[60];
    double precio;
    struct Venta ventas[10];
    int librosVendidos;
    struct Fecha fechaMasReciente;
    int sumaDeCalificaciones;
    int ranking;
};


#endif /* LIBRO_H */

