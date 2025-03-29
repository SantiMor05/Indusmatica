/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 1 de noviembre de 2024, 15:44
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define MAX_ALUMNOS 100
#define MAX_CURSOS 50
#define MAX_ESCALAS 50

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int ciclo, alumno[MAX_ALUMNOS], cursos_alum[MAX_ALUMNOS]{};
    double creditos_alum[MAX_ALUMNOS]{}, monto[MAX_ALUMNOS]{};
    char *nombre[MAX_ALUMNOS], escala_alum[MAX_ALUMNOS];
    
    int curso[MAX_CURSOS];
    double creditos[MAX_CURSOS];
    
    int ciclo_escala[MAX_ESCALAS];
    char escala[MAX_ESCALAS];
    double costo[MAX_ESCALAS];
    int cant_alumnos, cant_cursos, cant_escalas;
    
    ciclo = pedirCiclo();
    
    leerAlumnos(cant_alumnos, alumno, nombre, escala_alum, "Alumnos_lab7.txt");
    
//    for(int i = 0; i < cant_alumnos;i++){
//        cout << nombre[i] << endl;
//    }
    
    leerCursos(cant_cursos, curso, creditos, "Cursos_lab7.txt");
    leerEscalas(cant_escalas, ciclo_escala, escala, costo, "Escalas_lab7.txt");
    
    ordenarAlumnos(cant_alumnos, alumno, nombre, escala_alum);
    ordenarCursos(cant_cursos, curso, creditos);
    
    leerMatricula(ciclo, cant_alumnos, alumno, escala_alum, cursos_alum, 
            creditos_alum, monto, cant_cursos, curso, 
            creditos, cant_escalas, ciclo_escala, escala, costo, 
            "Matricula_lab7.txt");
    
    ordenarArreglos(cant_alumnos, alumno, nombre, escala_alum, cursos_alum, 
            creditos_alum, monto);
    
    emitirReporte(ciclo, cant_alumnos, alumno, nombre, escala_alum, cursos_alum, 
            creditos_alum, monto, "ReporteDePagoPorAlumno.txt");
    
    return 0;
}

