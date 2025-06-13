/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: Esteban
 * Codigo: 20231348
 *
 * Created on 20 de abril de 2025, 18:46
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "funcionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    char***libros,***pedidosLibros;
    int **stock,**pedidosClientes;
    bool **pedidosAtendidos;
    
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,
            pedidosAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    
    reporteDeEntregaPedidos("ReporteDeEntregaPedidos.txt",pedidosClientes,
            pedidosLibros,pedidosAtendidos);
    
    
    
    return 0;
}

