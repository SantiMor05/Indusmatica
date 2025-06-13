/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ESTEBAN
 * COD: 20231348
 *
 * Created on 22 de abril de 2025, 06:45 PM
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "funcionesAux.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    char*** libros,***pedidosLibros;
    int**stock,**pedidosClientes;
    bool** pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    
    atencionPedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,
            pedidosAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    
    ordenarPedidosClientes(pedidosClientes);
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt",pedidosClientes,pedidosLibros,
            pedidosAtendidos);
    
    return 0;
}

