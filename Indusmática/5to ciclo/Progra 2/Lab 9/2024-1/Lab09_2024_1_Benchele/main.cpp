/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 26 de junio de 2025, 05:17 PM
 */

#include <cstdlib>
#include "Biblioteca.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Biblioteca bli;

    bli.carga("Libros31.csv", "Estantes3.csv");
    bli.imprime("Reporte.txt");
    bli.prueba("ReporteEspacio.txt", 8);
    
    return 0;
}

