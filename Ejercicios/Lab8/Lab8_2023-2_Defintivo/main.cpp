/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 9 de noviembre de 2024, 11:35
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define MAX_ALUMNOS 100
#define MAX_CURSOS 100
#define MAX_ESCALAS 30

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int semestre;
    struct Alumno alumnos[MAX_ALUMNOS];
    struct Curso cursos[MAX_CURSOS];
    struct Escala escalas[MAX_ESCALAS];
    int cant_alumnos, cant_cursos, cant_escalas;
    
    semestre = pedirSemestre();
    
    leerDatosAlumnos(cant_alumnos, alumnos, "Alumnos_lab8.csv");
    leerDatosCurso(cant_cursos, cursos, "Cursos_lab8.csv");
    leerDatosEscalas(cant_escalas, escalas, "Escalas_lab8.csv");
    
    procesarMatricula(semestre, cant_alumnos, alumnos, cant_cursos, cursos, 
            cant_escalas, escalas, "Matricula_lab8.csv");
    
    ordenarCursos(cant_cursos, cursos);
    
    emitirReporte(semestre, cant_cursos, cursos, "ReporteDePagoPorCurso.txt");

    return 0;
}

