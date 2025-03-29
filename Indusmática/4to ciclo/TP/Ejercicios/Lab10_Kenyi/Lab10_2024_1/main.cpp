/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 24 de noviembre de 2024, 02:04 PM
 */

#include <iostream>
#include <fstream>
#include "FuncionesAuxiliares.h"

using namespace std;
#define MAX_CLIENT

/*
 * 
 */
int main(int argc, char** argv) {
    leerClienteBin("Clientes.csv","Clientes.bin");
    leerLibrosBin("Libros.csv","Libros.bin");
    leerVentas("Ventas.csv","Clientes.bin","Libros.bin");
    determinarRanking("Libros.bin");
    ordenarBin("Libros.bin");
    emitirReporte("Libros.bin","ReporteDeVentasPorLibro.txt");
    return 0;
}

