/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 30 de abril de 2025, 06:25 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Cafeteria.h"
#include "pruebas.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *inventario, *menu;
    //Carga inventario
    cargarInventario("inventario.csv", inventario);
    probarCargaInventario("prueba-inventario.txt", inventario);
    
    //Carga menu
    cargarMenu("menu.csv", menu);
    pruebaCargaMenu("menu-inicial.txt", menu);
    
    //Actualizar menu
    actualizarMenu("insumos-bebidas.csv", inventario, menu);
    
    //Reporte
    reporteMenu("menu.txt", menu);
    return 0;
}


