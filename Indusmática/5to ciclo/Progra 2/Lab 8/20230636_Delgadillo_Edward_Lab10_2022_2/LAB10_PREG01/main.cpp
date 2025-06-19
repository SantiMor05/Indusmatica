/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 18 de junio de 2025, 07:45 PM
 */

#include "Almacen.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Almacen almacen;
    almacen.carga("medicamentos.csv");
    almacen.imprime("reporte.txt");
    almacen.actualiza("recarga.csv");
    almacen.imprime("reporte2.txt");
    
    return 0;
}

