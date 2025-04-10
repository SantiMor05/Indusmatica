/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Edward Delgadillo
 * Codigo: 20230636
 * Created on 9 de abril de 2025, 09:27 PM
 */

#include <iostream>
#include <fstream>

using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "sobrecarga.h"
#include "funciones.h"
/*
 * 
 */
int main(int argc, char** argv) {

    struct Libro libros[270]{};
    struct Cliente clientes[60]{};
    leerLibros(libros,"Libros.csv");
    leerClientes(clientes,"Cientes.csv");
    procesarPedidos(libros,clientes,"Pedidos.txt");
    emitirLibros(libros,"reporteLib.txt");
    emitirClientes(clientes,"reporteClie.txt");
    
    
    return 0;
}

