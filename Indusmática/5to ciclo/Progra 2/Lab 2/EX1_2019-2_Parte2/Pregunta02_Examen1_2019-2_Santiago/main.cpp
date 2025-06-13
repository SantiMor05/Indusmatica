/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 20 de abril de 2025, 22:59
 */

#include <iostream>
#include <iomanip>
#include "FuncionesParte02EX1.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int *dni;
    char **conductor, ***placas;
    double *multas, ***montoXMultas;
    
    leerConductores(dni, conductor, placas);
    imprimirConductores(dni, conductor, placas);

    leerMultas(multas);
    imprimirMultas(multas);
    
    leerInfraccionesCometidas(dni, placas,multas,montoXMultas);
    imprimirInfraccionesCometidas(dni, conductor,placas,montoXMultas);
    
    return 0;
}

