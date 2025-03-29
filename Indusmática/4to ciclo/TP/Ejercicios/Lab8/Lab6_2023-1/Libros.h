/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libros.h
 * Author: santi
 *
 * Created on 10 de noviembre de 2024, 19:27
 */

#ifndef LIBROS_H
#define LIBROS_H

struct Libros{
    char codigo[8];
    char titulo[40];
    char autor[40];
    int cantidad;
    int prestados;
    double precio;
};

#endif /* LIBROS_H */

