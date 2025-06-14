/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 8 de junio de 2025, 23:42
 */

#include <iostream>
#include "Almacen.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Almacen almacen;

    almacen.cargar_pedidos();
    almacen.actualizar_orden();
    almacen.imprimir_ordenes_venta();
    
    return 0;
}

