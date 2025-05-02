/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 1 de mayo de 2025, 11:22 AM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
#include "enums.h"
#include "pruebas.h"
#include "FuncionesAux.h"

/*
 * 
 */
int main(int argc, char** argv) {
    void *inventario, *menu;

    cargarInventario("inventario.csv", inventario);
    probarCargaInventario("prueba-inventario.txt", inventario);

    cargarMenu("menu.csv", menu);
    //    pruebaMenu("menu_inicial.txt",menu);
    pruebaCargaMenu("menu_inicial.txt", menu);
    actualizarMenu("insumos-bebidas.csv", inventario, menu);
    probarCargaInventario("prueba-inventario-final.txt", inventario);
     pruebaCargaMenu("menu-final.txt", menu);
    reporte("menu.txt", menu);



    return 0;
}

