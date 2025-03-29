/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 17 de noviembre de 2024, 12:18
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    struct Cliente *arrClientes;
    arrClientes = new struct Cliente[60]{};
    
    struct Libro *arrLibros;
    arrLibros = new struct Libro[300]{};
    
    int num_clientes, num_libros;
    
    leerDatosClientes(arrClientes, num_clientes, "Clientes_laboratorio9.csv");
    leerDatosLibros(arrLibros, num_libros, "Libros_laboratorio9.csv");

    leerVentas(arrLibros, num_libros, "Ventas_laboratorio9.csv");
    
    determinarRankings(arrLibros, num_libros);
    
    ordenarLibros(arrLibros, num_libros);
    
    emitirReporte(arrClientes, num_clientes, arrLibros, num_libros, 
            "ReporteDeVentasPorLibro.txt");
    
    return 0;
}

