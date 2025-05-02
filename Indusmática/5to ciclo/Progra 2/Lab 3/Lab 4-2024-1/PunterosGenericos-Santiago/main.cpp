/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 1 de mayo de 2025, 10:30
 */

#include <iostream>
#include <iomanip>
#include "MuestraPunteroGenerico.h"
#include "PunterosGenericos.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    void *clientes, *reserva;
    
    cargaclientes(clientes);
    muestraclientes(clientes);
    
    creareserva(reserva);
    muestrareservas(reserva);
    
    cargareservar(clientes, reserva);
    reportefinal(reserva);

    return 0;
}

