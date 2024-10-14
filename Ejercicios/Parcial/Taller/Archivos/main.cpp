/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 11 de octubre de 2024, 13:40
 */


#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    procesarDatos("Productos.txt", "Almacen.txt", "StockProductos.txt", 
            "Transacciones.txt", "ReporteProductos.txt");

    return 0;
}

