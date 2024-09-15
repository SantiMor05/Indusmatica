/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 14 de septiembre de 2024, 14:47
 */

////Programa que lee la infomarción de las personas que realizaron el préstamo
//de un libro para llevar un control y detallar aquellos usuarios que no han 
//devuelto los libros en un reporte

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
    
    abrirArchivos(archDatos, archReporte, "Biblioteca-H0431-H0432.txt",
            "Reporte-2023-1_H431.txt");
    
    leerProcesarImprimirDatos(archDatos,archReporte);

    return 0;
}

