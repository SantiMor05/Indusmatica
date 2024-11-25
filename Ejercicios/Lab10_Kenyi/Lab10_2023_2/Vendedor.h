/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Vendedor.h
 * Author: kenyi
 *
 * Created on 24 de noviembre de 2024, 05:42 PM
 */
#include "ArticuloVendido.h"

#ifndef VENDEDOR_H
#define VENDEDOR_H
struct Vendedor{
    int codigo;
    char nombre[60];
    double porcentaje;
    double cuotaMinima;
    struct ArticuloVendido articulosVendidos[10];
    int cantidadArr;
    double totalVendido;
    bool superoCuota;
};


#endif /* VENDEDOR_H */

