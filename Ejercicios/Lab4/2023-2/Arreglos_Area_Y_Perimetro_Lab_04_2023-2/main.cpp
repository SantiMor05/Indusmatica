/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 26 de septiembre de 2024, 20:12
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int numDat;
    double x[20], y[20];
    
    leerDatos(x,y,numDat, "Poligono.txt");
    
    probarDatos(x,y, numDat ,"Prueba.txt");
    
    imprimirReporteFinal(x,y,numDat, "Reporte-Lab4_2023-2.txt");

    return 0;
}

