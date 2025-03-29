/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 10 de octubre de 2024, 23:46
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define MAX_PACIENTES 100
#define MAX_MEDICINAS 250

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int dni[MAX_PACIENTES], distrito[MAX_PACIENTES], 
            cant_citas[MAX_PACIENTES]{}, num_medicinas[MAX_PACIENTES]{};
    char clasificacion[MAX_PACIENTES];
    double descuento[MAX_PACIENTES], pago[MAX_PACIENTES]{};
    
    int medicina[MAX_MEDICINAS];
    double costo[MAX_MEDICINAS];
    
    int cant_pacientes, cant_medicinas;
    
    
    leerPacientes(cant_pacientes, dni, distrito, clasificacion, descuento, 
            "Pacientes.txt");
    
    leerMedicinas(cant_medicinas, medicina, costo, "Medicinas.txt");
    
    emitiirPrueba(cant_pacientes, dni, distrito, clasificacion, descuento,
            cant_medicinas, medicina, costo, "Prueba.txt");
    
    actualizarDatos(cant_pacientes, dni, distrito, clasificacion, descuento, 
            cant_citas,  num_medicinas, pago,cant_medicinas, medicina, costo,
            "CitasMedicas.txt");
    
    ordenarArreglos(cant_pacientes, dni, distrito, clasificacion, descuento, 
            cant_citas,  num_medicinas, pago);

    
    imprimirReporte(cant_pacientes, dni, distrito, clasificacion, descuento, 
            cant_citas,  num_medicinas, pago, "ConsolidadoPacientes.txt");
    
    return 0;
}

