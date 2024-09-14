
/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 6 de septiembre de 2024, 22:51
 */

//Programa que procesa la información sobre las citas médicas de 
//los pacientes de una empresa de salud y lo imprime en un reporte

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    imprimirCabecera();
    
    calcularEImprimirReporte();

    return 0;
}

