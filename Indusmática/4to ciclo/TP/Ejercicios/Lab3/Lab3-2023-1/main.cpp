/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 21 de septiembre de 2024, 14:02
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
    
    
    ifstream archCartelera, archCli;
    ofstream archReporte;
    
    abrirArchivos(archCartelera, archCli,archReporte, "CarteleraDeCines.txt",
            "ClientesCine.txt", "Reporte.txt");
    
    leerProcesarImprimirDatos(archCartelera, archCli, archReporte);

    return 0;
}

