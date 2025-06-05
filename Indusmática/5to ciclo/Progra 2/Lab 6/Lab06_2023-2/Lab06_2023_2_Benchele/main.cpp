/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 3 de junio de 2025, 08:06 PM
 */

#include <iostream>
#include <iomanip>
#include "Almacen.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Almacen almacen{};
    almacen.cargar_clientes("Clientes.csv");
    almacen.cargar_productos("Productos.csv");
    almacen.cargar_pedidos("Pedidos.csv");
    almacen.mostrar_datos("Reporte.txt");
    
    return 0;
}

