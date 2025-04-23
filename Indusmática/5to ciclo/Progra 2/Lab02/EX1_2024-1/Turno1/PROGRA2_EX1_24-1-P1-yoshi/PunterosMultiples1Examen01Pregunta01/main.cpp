/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 23 de abril de 2025, 10:58 AM
 */

#include <fstream>
using namespace std;
#include "Funciones auxiliares.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char**ventasLibroCodigo,***libro;
    int **ventasDNIFechaPuntaje;
    cargar_vemtas(ventasLibroCodigo,ventasDNIFechaPuntaje,"Ventas.csv");
    pruebaCargaVentas(ventasLibroCodigo,ventasDNIFechaPuntaje,"PruebaVentas.txt");
    cargaLibros(libro,"Libros.csv");
    pruebaCargaLibros(libro,"PruebaLibros.txt");
    return 0;
}

