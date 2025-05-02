/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 1 de mayo de 2025, 09:32 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
#include "PunterosVoid.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    struct PuntGenericos puntGenericos;
    //Cargar productos
    cargarProductos("Productos2.csv", puntGenericos.productos);
    //Cargar clientes
    cargaCliente("Clientes2.csv", puntGenericos.clientes);
    //Cargar pedidos
    cargaPedidos("Pedidos2.csv", puntGenericos.productos, puntGenericos.clientes);
    //Imprimir reporte
    imprimirReporte("Reporte.txt", puntGenericos.clientes);
    return 0;
}

