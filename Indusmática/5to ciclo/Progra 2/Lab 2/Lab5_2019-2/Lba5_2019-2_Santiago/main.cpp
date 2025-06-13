/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 18 de abril de 2025, 20:56
 */

#include <iostream>
#include <iomanip>
#include "FuncionesLaboratorio05.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    char ***almacenes, **codigoProd, **nombreProd;
    
    leerPalets(almacenes);
    imprimirPalets(almacenes);
    
    leerProductos(codigoProd, nombreProd);
    imprimirProductos(codigoProd, nombreProd);
    
    ordenarProductos(codigoProd, nombreProd);
    imprimirProductos(codigoProd, nombreProd);
    
    cuentaProductos(almacenes,codigoProd, nombreProd);

    return 0;
}

