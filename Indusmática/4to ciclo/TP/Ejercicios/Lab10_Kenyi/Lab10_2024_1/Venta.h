/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Venta.h
 * Author: kenyi
 *
 * Created on 24 de noviembre de 2024, 02:07 PM
 */

#include "Fecha.h"

#ifndef VENTA_H
#define VENTA_H
struct Venta{
    int dni;
    char nombre[60];
    struct Fecha fecha;
    int calificacion;
};
#endif /* VENTA_H */

