/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: santi
 *
 * Created on 17 de noviembre de 2024, 12:22
 */

#ifndef LIBRO_H
#define LIBRO_H

struct Libro{
    char *codigo;
    char *titulo;
    char *autor;
    double precio;
    struct Venta *ventas;
    int librosVendidos;
    int sumaDeCalificaciones;
    int ranking;
};

#endif /* LIBRO_H */

