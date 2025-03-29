/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 26 de septiembre de 2024, 23:48
 */


#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int cod_libro[100], cod_autor[400], libro[400];
    double precio_libro[100], porcentaje[400];
    int cant_libros, cant_autores, fecha_ini, fecha_fin;
    
    leerLibros(cod_libro, precio_libro, cant_libros, "Libros.txt");
    
    leerAutores(cod_autor, libro, porcentaje, cant_autores, "Autores.txt");
    
    pedirFechas(fecha_ini, fecha_fin);
    
    emitirReporte(cod_libro, cod_autor, libro, precio_libro, porcentaje,
            cant_libros, cant_autores, fecha_ini, fecha_fin, "Reporte.txt",
            "Ventas-0431-0432_Laboratorio4.txt");

    return 0;
}

