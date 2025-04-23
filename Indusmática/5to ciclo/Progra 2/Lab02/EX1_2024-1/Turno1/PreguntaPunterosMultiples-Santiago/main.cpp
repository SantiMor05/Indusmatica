/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 22 de abril de 2025, 22:10
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "PunterosMultiples1Examen01Pregunta01.h"

using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    
    char **ventasLibroCodigo, ***libro;
    int **ventasDniFechaPuntaje;
    
    cargarVentas(ventasLibroCodigo, ventasDniFechaPuntaje, "Ventas.csv");
    pruebaDeCargaDeVentas(ventasLibroCodigo, ventasDniFechaPuntaje, 
            "PruebaVentas.txt");

    cargaLibros(libro,"Libros.csv");
    pruebaDeCargaDeLibros(libro, "PruebaLibros.txt");
    
    return 0;
}

