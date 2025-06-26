/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 26 de junio de 2025, 06:06 PM
 */

#include <cstdlib>

using namespace std;
#include "Cola.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Cola cola;
    cola.cargarMultas("infracciones.csv");
    cola.cargarConductores("Conductores.csv");
    cola.imprimirConductores("Reporte.txt");
    return 0;
}

