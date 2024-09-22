/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 21 de septiembre de 2024, 11:08
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream archCanal, archTele, archPrefe;
    ofstream archReporte;
    
    abrirArchivos(archCanal, archTele, archPrefe, archReporte, "Canales.txt",
            "Televidentes.txt", "RegistroDePreferencias.txt", 
            "Reporte_2023-2.txt");
    
    leerProcesarImprimirDatos(archCanal, archTele, archPrefe, archReporte);
    

    return 0;
}

