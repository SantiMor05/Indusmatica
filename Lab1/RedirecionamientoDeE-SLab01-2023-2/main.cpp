/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 7 de septiembre de 2024, 17:41
 */
//
//Proyecto que ordena los datos de los cliente que tienen un contrato de 
//de televisión por cable para conocer sus preferencias y las de sus 
//familiares

#include <iostream>
#include <iomanip>
#include "FuncionesAuxliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    imprimirEncabezado();
    
    procesarEImprimirReporte();

    return 0;
}

