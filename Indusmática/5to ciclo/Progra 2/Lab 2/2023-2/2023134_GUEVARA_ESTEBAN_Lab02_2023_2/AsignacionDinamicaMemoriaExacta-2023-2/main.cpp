/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: Esteban
 * codigo: 20231348
 *
 * Created on 19 de abril de 2025, 16:45
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
    
    char***productos,***codigosPedidos;
    int* stock,*fechaPedidos,***dniCantPedidos;
    double* precios;
    
    lecturaDeProductos("Productos.csv",productos,stock,precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt",productos,stock,precios);
    
    lecturaDePedidos("Pedidos.csv",fechaPedidos,codigosPedidos,dniCantPedidos);
    pruebaDeLecturaDePedido("ReporteDePedidos.txt",fechaPedidos,codigosPedidos,dniCantPedidos);
    
    reporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt",productos,stock,precios,
            fechaPedidos,codigosPedidos,dniCantPedidos);
    pruebaDeLecturaDeProductos("ReporteDeProductosFinal.txt",productos,stock,precios);
    return 0;
}

