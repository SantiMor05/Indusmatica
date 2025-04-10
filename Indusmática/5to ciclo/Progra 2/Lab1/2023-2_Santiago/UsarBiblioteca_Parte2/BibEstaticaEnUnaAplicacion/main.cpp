/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 10 de abril de 2025, 13:08
 */

#include <iostream>
#include <iomanip>
#include "AperturaDeArchivos.h"
#include "FuncionesAuxiliares.h"
#include "FuncionesSobrecargadas.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    struct Cliente clientes[150];
    struct Producto productos[200];
    
    leerCliente(clientes);
    leerProductoas(productos);
    leerPedidos(clientes, productos);
    
    imprimirReporte(clientes, productos);

    return 0;
}

