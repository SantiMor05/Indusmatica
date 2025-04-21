/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Edward Delgadillo
 * Codigo: 20230636
 * Created on 20 de abril de 2025, 12:48 PM
 */

#include "MetodoDinamicoExacto.h"

using namespace std;

int main(int argc, char** argv) {

    char**alumnoNombre,**cursoNombre,*alumnoModalidad;
    int *alumnoCodigo,*alumnoPorcentaje,*alumnoEscala;
    int **cursoAlumnos;
    double *cursoCredito;
    
    lecturaAlumnos("alumnos.csv",
            alumnoCodigo,alumnoNombre,alumnoModalidad,alumnoPorcentaje,
            alumnoEscala);
    pruebaLecturaAlumnos("ReporteAlumnos.txt",
            alumnoCodigo,alumnoNombre,alumnoModalidad,alumnoPorcentaje,
            alumnoEscala);
    
    lecturaCursos("alumnos_cursos.csv",
            alumnoCodigo,alumnoEscala,cursoNombre,cursoCredito,cursoAlumnos);
    pruebaDeLecturaCursos("ReporteCursos.csv",
            cursoNombre,cursoCredito,cursoAlumnos);
    
    reporteDeRecaudacionPorModalidad("ReporteDeRecaudacionPorModalidad.txt",
            alumnoCodigo,alumnoNombre,alumnoModalidad,alumnoPorcentaje,
            cursoNombre,cursoCredito,cursoAlumnos);
    
    return 0;
}

