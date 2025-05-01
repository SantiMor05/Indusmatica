/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Edward Delgadillo
 * Codigo: 20230636
 * Created on 29 de abril de 2025, 03:00 PM
 */

#include <cstdlib>
#include "cafeteria.h"
#include "pruebas.h"
using namespace std;
int main(int argc, char** argv) {
    void *inventario, *menu;
    cargarInventario("inventario.csv", inventario);
    probarCargaInventario("prueba-inventario.txt", inventario);
//    cargarMenu("menu.csv", menu);
//    pruebaCargaMenu("menu-inicial.txt", menu);
//    actualizarMenu("insumos-bebidas.csv", inventario, menu);
//    reporteMenu("menu.txt", menu);
    return 0;
}
