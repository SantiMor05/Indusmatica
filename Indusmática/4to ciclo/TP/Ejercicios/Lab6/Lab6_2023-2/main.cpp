/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 27 de octubre de 2024, 21:56
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define MAX_ALUMNOS 100
#define MAX_CURSOS 50
#define MAX_ESCALAS 30

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int alumnos[MAX_ALUMNOS], num_cursos[MAX_ALUMNOS]{};
    char escala_alum[MAX_ALUMNOS];
    double total_creditos[MAX_ALUMNOS]{}, pago[MAX_ALUMNOS]{};
    
    int curso[MAX_CURSOS];
    double creditos[MAX_CURSOS];
    
    int ciclo[MAX_ESCALAS];
    char escala[MAX_ESCALAS];
    double costo[MAX_ESCALAS];
    
    int ciclo_usuario, cant_alumnos,cant_cursos, cant_escalas;
    
    ciclo_usuario = pedirCiclo();
    
    leerAlumnos(cant_alumnos, alumnos, escala_alum, "Alumnos_lab6.txt");
    leerCursos(cant_cursos, curso, creditos, "Cursos_lab6.txt");
    leerEscalas(cant_escalas, ciclo, escala,costo, "Escalas_lab6.txt");
    
    leerMatricula(ciclo_usuario, cant_alumnos, alumnos, escala_alum, num_cursos, 
            total_creditos, cant_cursos, curso, creditos, cant_escalas, ciclo, 
            escala, costo, pago,"Matricula_lab6.txt");
    
    emitirReporte(ciclo_usuario, cant_alumnos, alumnos,escala_alum, num_cursos, 
            total_creditos, pago, "AlumnosNombres.txt", "AlumnosApellidos.txt", 
            "ReporteDePagoPorAlumno.txt");

    return 0;
}

