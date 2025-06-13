/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 23 de abril de 2025, 07:11 PM
 */

#include <cstdlib>
#include <fstream>
using namespace std;
#include "Funciones auxiliares.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int *dni;
    char **conductor, ***placas;
    double *multas, ***montoXmultas;
    leer_conductores(dni,conductor,placas);
    imprimir_conductores(dni,conductor,placas);
    leer_multas(multas);
    imprimir_multas(multas);
    leer_infracciones_cometidas(dni,placas,multas,montoXmultas);
    imprimir_infracciones_cometidas(dni,conductor,placas,montoXmultas);
    return 0;
}

