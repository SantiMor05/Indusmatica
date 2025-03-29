/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Venta.h
 * Author: santi
 *
 * Created on 17 de noviembre de 2024, 12:21
 */

#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"

struct Venta{
    int dni;
    struct Fecha fecha;
    int calificacion;
};

#endif /* VENTA_H */

