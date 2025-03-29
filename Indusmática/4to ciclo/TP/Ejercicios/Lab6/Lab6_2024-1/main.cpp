/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 23 de octubre de 2024, 20:45
 */


#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define MAX_CAR_FACU 35
#define MAX_ALUMNOS 100

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int arrCodigoAlumnos[MAX_ALUMNOS], arrNumCursos[MAX_ALUMNOS]{}; 
    double arrSumaPonderada[MAX_ALUMNOS]{}, arrNumCreditos[MAX_ALUMNOS]{};
    int num_alumnos = 0, facu;
    
    char *facultad;
    
    facultad = pedirFacultad();
    
    cout << "La facultad ingresada es " << facultad;
    
    leerAlumnos(num_alumnos, arrCodigoAlumnos, arrNumCursos, arrSumaPonderada,
            arrNumCreditos, "Calificaciones.txt");
    
    imprimirReporte("Alumnos.txt", facultad, num_alumnos, arrCodigoAlumnos, 
            arrNumCursos, arrSumaPonderada, arrNumCreditos, 
            "ReporteDePagoPorAlumno.txt");

    return 0;
}

