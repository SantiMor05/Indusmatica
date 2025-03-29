/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 13 de septiembre de 2024, 23:22
 */

////Programa que analiza los datos de las citas médicas de los pacientes
//e imprime las que corresponde a pediatria y  entre un rango de duración


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
    
    abrirArchivos(archDatos, archReporte, "CitasMedicas_laboratorio2.txt", 
            "Reporte.txt");
    
    imprimirEncabezado(archReporte);
    
    leerProcesarImprimirDatos(archDatos, archReporte);

    return 0;
}

