/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 18 de junio de 2025, 02:07 PM
 */

#include <cstdlib>
#include "Tesoreria.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Tesoreria caja{};
    
    caja.cargaAlumnos("Alumnos.csv");
    caja.cargaEscalas("escalas.csv");
    caja.actualiza(20);
    caja.imprimirBoleta("Reporte.txt");

    return 0;
}

