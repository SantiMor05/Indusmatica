/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 1 de mayo de 2025, 04:41 PM
 */

#include <iostream>

using namespace std;
#include "MuestraPunteroGenerico.h"
#include "FuncionesAux.h"
#include "AperturaDeArchivos.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *clientes,*reserva;
    
    cargaclientes(clientes);
    creareserva(reserva);
    cargareservar(clientes,reserva);
    reportefinal(reserva);
    
    return 0;
}

