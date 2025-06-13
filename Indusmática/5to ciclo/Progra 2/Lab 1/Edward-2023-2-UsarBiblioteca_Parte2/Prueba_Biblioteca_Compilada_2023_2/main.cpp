/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Edward Delgadillo
 * Codigo: 20230636
 * Created on 10 de abril de 2025, 10:55 AM
 */

#include <iostream>
#include <fstream>

using namespace std;
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "sobrecarga.h"
#include "funciones.h"


/*
 * 
 */
int main(int argc, char** argv) {

    struct Cliente clientes[140]{};
    struct Producto productos[170]{};
    
    leerClientes(clientes,"Clientes.csv");
    leerProductos(productos,"Productos.csv");
    procesarPedidos(clientes,productos,"Pedidos.csv");
    hallarMontosClie(clientes);
    emitirClientes(clientes,"reporteCli.txt");
    emitirProductos(productos,"reportePro.txt");

    return 0;
}

