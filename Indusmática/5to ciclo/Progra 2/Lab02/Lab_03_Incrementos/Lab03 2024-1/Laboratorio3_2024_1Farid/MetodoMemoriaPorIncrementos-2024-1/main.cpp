/* 
 * File:   main.cpp
 * Author: Farid Oswaldo - 20231467
 *
 * Created on 24 de abril de 2025, 03:10 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "MetodoIncrementalDeMemoria.h"

/*
 * 
 */

int main(int argc, char** argv) {

    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;

    lecturaDeLibros("Libros.csv", libros, stock);
    
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt", libros, stock);
    

    atencionDePedidos("Pedidos.txt", libros, stock, pedidosClientes,
            pedidosLibros, pedidosAtendidos);
    
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt", libros, stock);
    
    ordenarPedidosClientes(pedidosClientes);
    
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt", pedidosClientes,
            pedidosLibros, pedidosAtendidos);
    
    return 0;
}

