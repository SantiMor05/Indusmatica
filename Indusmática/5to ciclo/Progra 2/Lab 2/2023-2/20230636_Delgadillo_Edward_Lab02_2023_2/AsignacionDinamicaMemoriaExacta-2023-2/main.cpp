/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Edward Delgadillo
 * Codigo: 20230636
 * Created on 18 de abril de 2025, 09:32 PM
 */

#include "AsignacionDinamicaMemoriaExacta.h"

using namespace std;

int main(int argc, char** argv) {

    char***productos,***codigoPedidos;
    int *stock,*fechaPedidos,***dniCantPedidos;
    double *precios;
    
    lecturaDeProductos("Productos.csv",productos,stock,precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt",productos,stock,precios);
    
    lecturaDePedidos("Pedidos.csv",fechaPedidos,codigoPedidos,dniCantPedidos);
    pruebaDeLecturaDePedidos("ReporteDePedidos.txt",
            fechaPedidos,codigoPedidos,dniCantPedidos);
    
    reporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt",
            productos,stock,precios,
            fechaPedidos,codigoPedidos,dniCantPedidos);
    
    pruebaDeLecturaDeProductos("ReporteDeProductosFinal.txt",
            productos,stock,precios);

    return 0;
}

