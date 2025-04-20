/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 19 de abril de 2025, 16:22
 */

#include <fstream>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"

/*
 * 
 */
int main(int argc, char** argv) {
    char ***productos, ***CodigoPedidos;
    int *stock, *fechaPedidos, ***dniCantPedidos;
    double *precios;
    
    lecturaDeProductos("Productos.csv", productos,stock,precios);
    pruebaLecturaDeProductos("ReporteDeProductos.txt", productos,stock,precios);
    
    lecturaDePedidos("Pedidos.csv", fechaPedidos,CodigoPedidos,dniCantPedidos);
    pruebaDeLecutraDePedidos("ReporteDePedidos.txt",fechaPedidos,CodigoPedidos,dniCantPedidos);
    
    reporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt",productos,stock,precios,
            fechaPedidos,CodigoPedidos,dniCantPedidos);
    return 0;
}

