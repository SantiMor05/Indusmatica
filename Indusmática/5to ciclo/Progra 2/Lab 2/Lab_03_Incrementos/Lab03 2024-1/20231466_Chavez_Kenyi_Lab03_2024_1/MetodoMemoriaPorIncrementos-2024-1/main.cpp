/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 20231466 Chavez Kenyi
 *
 * Created on 24 de abril de 2025, 04:10 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "MetodoIncremetalDeMemoria.h"
/*
 * 
 */
int main(int argc, char** argv) {

    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;

    lecturaDeLibros("Libros.csv", libros, stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt", libros, stock);

    atencionDePedidos("Pedidos.txt", libros, stock, pedidosClientes, pedidosLibros,
            pedidosAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt", libros, stock);

    ordenarPedidosClientes(pedidosClientes);
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt", pedidosClientes,
            pedidosLibros, pedidosAtendidos);


    return 0;
}

