/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 20 de septiembre de 2024, 22:18
 */

//Programa que lee datos de una empresa médica de dos archivos, los procesan y
//los muestra en un reporte


#include <iostream>
#include <fstream>
#include <iomanip>
#include "FuncionesAuxiliares.h"


using namespace std;



/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream archCitas, archMed;
    ofstream archReporte;
    
    abrirArchivos(archCitas, archMed, archReporte, 
            "CitasMedicas_laboratorio3.txt", "Medicos_laboratorio3.txt",
            "Reporte-2024-1.txt");
    
    
    leerProcesarImpirmirDatos(archCitas, archMed, archReporte);
    

    return 0;
}

