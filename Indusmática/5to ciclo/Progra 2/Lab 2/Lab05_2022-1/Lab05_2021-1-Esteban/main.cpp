/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 23 de abril de 2025, 13:19
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include "BibManejoDinamicoDeMemoria.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    char ** conductor, ***placa;
    int *licencia, **falta;
    double **multa;
    
    cargaConductores(licencia, conductor);
    reporteConductores(licencia, conductor);
    
    cargaFaltas(licencia, placa, falta);
    reporteFaltas(licencia, conductor, placa, falta);
    
    resumenMultas(licencia, falta, multa);
    reporteMultas(licencia, conductor, multa);

    return 0;
}

