/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 12 de septiembre de 2024, 21:44
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream archDatos;
    ofstream archReporte;
    
    abrirArchivos(archDatos, archReporte, "Datos.txt", "Reporte.txt");
    
    imprimirEncabezado(archDatos,archReporte);
    leerProcesarImprimirReporte(archDatos, archReporte);

    return 0;
}

