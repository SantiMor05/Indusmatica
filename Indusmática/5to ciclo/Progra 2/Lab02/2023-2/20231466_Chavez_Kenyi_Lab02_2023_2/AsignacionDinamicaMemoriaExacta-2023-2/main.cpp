/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Chavez Kenyi
 * 20231466
 *
 * Created on 18 de abril de 2025, 08:01 PM
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

#include "AsignacionDinamicaMemoriaExacta.h"

/*
 * 
 */
int main(int argc, char** argv) {

    char ***productos, ***codigoPedidos;
    int *stock, *fechaPedidos, ***dniCantPedidos;
    double *precios;

    lecturaDeProductos("Productos.csv", productos, stock, precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt", productos, stock, 
            precios);
    
    lecturaDePedidos("Pedidos.csv",fechaPedidos,codigoPedidos,dniCantPedidos);
    pruebaDeLecturaDePedidos("ReporteDePedidos.txt",fechaPedidos,codigoPedidos,
            dniCantPedidos);
    reporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt",productos,stock,
            precios,fechaPedidos,codigoPedidos,dniCantPedidos);
    
    pruebaDeLecturaDeProductos("ReporteDeProductosFinal.txt", productos, stock, 
            precios);
    
    
    return 0;
}

