/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 24 de abril de 2025, 15:02
 */


#include <iostream>
#include <iomanip>
#include "MetodoExactoDeMemoria.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    char ***libros, ***pedidoLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv", libros, stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt", libros, stock);
    
    atencionDePedidos("Pedidos.txt", libros, stock, pedidosClientes, 
            pedidoLibros, pedidosAtendidos);
    
    
    reporteDeEntregaDePedidos("antes.txt", pedidosClientes,
            pedidoLibros,pedidosAtendidos);
    
    ordenarPedidosClientes(pedidosClientes);
    
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt", pedidosClientes,
            pedidoLibros,pedidosAtendidos);

    return 0;
}

