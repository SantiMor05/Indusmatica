/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 8 de septiembre de 2024, 12:13
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int distrito1, distrito2, hh,min,seg, duracion;
    char alimentos;
    
    lecturaEImpresionDatosUsuario(distrito1, distrito2, hh,min,seg, 
            duracion, alimentos);
    leerYProcesarDatosArchivo(distrito1, distrito2, hh,min,seg, duracion,
            alimentos);

    return 0;
}

