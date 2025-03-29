/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Articulo.h
 * Author: kenyi
 *
 * Created on 24 de noviembre de 2024, 05:41 PM
 */

#ifndef ARTICULO_H
#define ARTICULO_H

struct Articulo{
   char codigo[8];
   char descripcion[60];
   double precio;
   int cantidadVendidos;
   double monto;
};

#endif /* ARTICULO_H */

