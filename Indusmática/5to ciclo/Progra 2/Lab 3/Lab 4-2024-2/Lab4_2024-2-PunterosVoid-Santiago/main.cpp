/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 29 de abril de 2025, 21:48
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "pruebas.h"
#include "cafeteria.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    void *inventario, *menu;
    
    cargarInventario("inventario.csv", inventario);
    probarCargaInventario("prueba-inventario.txt", inventario);

    cargarMenu("menu.csv", menu);
    pruebaCargaMenu("menu-inicial.txt", menu);
    
    actualizarMenu("insumos-bebidas.csv", inventario, menu);
    
//    pruebaCargaMenu("menu-final.txt", menu);
//    probarCargaInventario("prueba-final.txt", inventario);
    
    reporteMenu("menu.txt", menu);
    
    return 0;
}

