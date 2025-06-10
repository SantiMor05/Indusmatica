/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 10 de junio de 2025, 15:54
 */

#include <cstdlib>

using namespace std;
#include "Tesoreria.h"

/*
 * 
 */
int main(int argc, char** argv) {
    class Tesoreria caja{};
    caja.cargaEscalas("escalas.csv");
    caja.cargaAlumnos("Alumnos.csv");
    caja.actualiza();
    caja.imprime("Reporte.txt");
    return 0;
}

