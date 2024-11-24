/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 8 de noviembre de 2024, 22:27
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define MAX_ALUMNOS 100

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    char *facu1, *facu2;
    
    int arrCodigoAlumnos[MAX_ALUMNOS], arrNumCursos[MAX_ALUMNOS]{};
    double arrSumaPonderada[MAX_ALUMNOS]{}, arrNumCreditos[MAX_ALUMNOS]{},
            promedio[MAX_ALUMNOS]{};
    char *arrAlumnos[MAX_ALUMNOS], *arrFacultad[MAX_ALUMNOS];
    int cant_alumnos;
    
    pedirDatos(facu1, facu2);
    
    leerCalificaciones(cant_alumnos, arrCodigoAlumnos, arrNumCursos,
            arrSumaPonderada, arrNumCreditos, 
            "Calificaciones_laboratorio7.txt");
    
    leerAlumnos(cant_alumnos, arrCodigoAlumnos, arrAlumnos, arrFacultad,
            "Alumnos_laboratorio7.csv");
    
    emitirReporte(facu1, facu2, cant_alumnos, arrCodigoAlumnos, arrNumCursos,
            arrSumaPonderada, arrNumCreditos, arrAlumnos, arrFacultad, promedio, 
            "ReporteDePagoPorAlumno.txt", "Facultades_laboratorio7.txt");
    
    return 0;
}

