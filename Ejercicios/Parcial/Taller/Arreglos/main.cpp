/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 13 de octubre de 2024, 13:44
 */


#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define MAX_PROD 300

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int almacen[MAX_PROD], producto[MAX_PROD], stock[MAX_PROD],
            salidas[MAX_PROD]{},ingresos[MAX_PROD]{},enviados[MAX_PROD]{},
            recibidos[MAX_PROD]{}, stock_final[MAX_PROD]{};
    int fecha_ini, fecha_fin;
    int cant_prods;
    
    leerStock(cant_prods, almacen, producto, stock, "StockProductos.txt");
    
    probarDatos(cant_prods, almacen, producto, stock, "Prueba.txt");
    
    solicitarFechas(fecha_ini,fecha_fin);
    
    actualizarDatos(fecha_ini,fecha_fin, cant_prods, almacen, producto, stock,
            salidas, ingresos, enviados, recibidos, "Transacciones.txt");

    calcularStockFinal(cant_prods, salidas, ingresos, enviados, recibidos, 
            stock_final, stock);
    
    ordenar(cant_prods, almacen, producto, stock, salidas, ingresos, 
            enviados, recibidos, stock_final);
    
    emitirReporte(fecha_ini,fecha_fin, cant_prods, almacen, producto, stock, 
            salidas, ingresos, enviados, recibidos, stock_final, "Reporte.txt");
    
    
    eliminar(cant_prods, almacen, producto, stock, salidas, ingresos, 
            enviados, recibidos, stock_final);
    
    emitirReporte(fecha_ini,fecha_fin, cant_prods, almacen, producto, stock, 
            salidas, ingresos, enviados, recibidos, stock_final, 
            "ReporteMejores.txt");
    return 0;
}

