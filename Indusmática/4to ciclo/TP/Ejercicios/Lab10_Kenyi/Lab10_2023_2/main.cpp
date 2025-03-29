/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 24 de noviembre de 2024, 05:36 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    leerArticulosBin("Articulos.csv","Articulos.bin");
    leerVendedoresBin("Vendedores.csv","Vendedores.bin");
    
    procesarVentas("Ventas.txt","Articulos.bin","Vendedores.bin");
    
    
    corregirVendedores("Vendedores.bin");
    
    ordenarVendedores("Vendedores.bin");
    
    emitirReporte("ReporteDePagos.txt","Articulos.bin","Vendedores.bin");
    return 0;
}

