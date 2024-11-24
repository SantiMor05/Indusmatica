/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 24 de noviembre de 2024, 11:36
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    crearBinarioClientes("Clientes_laboratorio10.csv", "Clientes.bin");
    crearBinarioLibros("Libros_laboratorio10.csv", "Libros.bin");
    
    completarDatos("Ventas_laboratorio10.csv", "Clientes.bin", "Libros.bin");
    determinarRankig("Libros.bin");
    
    ordernar("Libros.bin");
    
    emitirReporte("Libros.bin", "ReporteDeVentasPorLibro.txt");
    return 0;
}

