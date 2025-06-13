/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 9 de abril de 2025, 22:30
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "FuncionesSobrecargadas.h"
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    struct Cliente clientes[100];
    struct Libro libros[300];
    int nLibros = 0, nClientes = 0;
    
    leerLibros(libros, nLibros);
    leerClientes(clientes, nClientes);
    leerPedidos(libros, nLibros, clientes, nClientes);
   
    imprimriLibros(libros, nLibros);
    imprimirClientes(clientes, nClientes);
   
    return 0;
}

