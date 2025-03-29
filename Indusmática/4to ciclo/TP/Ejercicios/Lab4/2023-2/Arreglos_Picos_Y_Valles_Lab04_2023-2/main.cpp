/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 26 de septiembre de 2024, 21:31
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int anhos[200], ganancias[200], numDat;
    
    leerDatos(anhos, ganancias, numDat, "ganancias.txt");
    
    reporteDePrueba(anhos, ganancias, numDat, "Prueba.txt");
    
    emitirReporte(anhos, ganancias, numDat, "Reporte2-lab4-2023-2.txt");

    return 0;
}

