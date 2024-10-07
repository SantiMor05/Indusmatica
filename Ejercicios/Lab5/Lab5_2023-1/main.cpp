/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 6 de octubre de 2024, 11:47
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
    
    int cod_prod[MAX_PROD], codigo_almacen[MAX_PROD], stock[MAX_PROD];
    int ingresos[MAX_PROD]{}, salidas[MAX_PROD]{}, enviado[MAX_PROD]{}, 
            recibido[MAX_PROD]{};
    int cant_prod;
    
    int fecha_ini, fecha_fin;
    
    leerStock(cant_prod, cod_prod, codigo_almacen, stock, "StockProductos.txt");
    probarDatos(cant_prod, cod_prod, codigo_almacen, stock, 
            "ReportePrueba.txt");
    
    pedirDatos(fecha_ini, fecha_fin);
    actualizarDatos(fecha_ini, fecha_fin, "Transacciones.txt");
    
    return 0;
}

