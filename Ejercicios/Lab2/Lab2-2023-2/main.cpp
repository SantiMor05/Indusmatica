/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 14 de septiembre de 2024, 12:36
 */


////Programa que procesa la información de la base de datos para conocer 
//las preferencias de los clientes que tienen un contrato de televisión 
//por cable e imprime un reporte

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
    
    abrirArchivos(archDatos, archReporte, "Registro de televidentes_lab2.txt",
            "Reporte-2023-2.txt");
    
    imprimirEmcabezado(archReporte);
    
    leerProcesarImprimirDatos(archDatos, archReporte);

    return 0;
}

