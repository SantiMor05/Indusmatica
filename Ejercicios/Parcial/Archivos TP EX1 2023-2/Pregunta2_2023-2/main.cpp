/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 14 de octubre de 2024, 12:54
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define MAX_ALUM 100
#define MAX_CURSOS 50
#define MAX_ESCALAS 30

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int alumno[MAX_ALUM];
    char escala[MAX_ALUM];
    
    int curso[MAX_CURSOS];
    double creditos[MAX_CURSOS];
    
    int anho[MAX_ESCALAS], ciclo[MAX_ESCALAS],cant_alumn_escalas[MAX_ESCALAS]{};
    char escala_escala[MAX_ESCALAS];
    double costo[MAX_ESCALAS], cant_creditos[MAX_ESCALAS]{},
            total_ingresos[MAX_ESCALAS]{};
    
    int cant_alumnos, cant_cursos, cant_escalas;
    
    
    leerAlumnos(cant_alumnos, alumno, escala, "Alumnos.txt");
    leerCursos(cant_cursos, curso, creditos, "Cursos.txt");
    leerEscalas(cant_escalas, anho, ciclo, escala_escala, costo, "Escalas.txt");
    
    reportePrueba(cant_escalas, anho, ciclo, escala_escala, costo, 
            "Prueba.txt");
    
    actualizarDatos(cant_alumnos, alumno, escala, cant_cursos, curso, creditos,
            cant_escalas, anho, ciclo, escala_escala, costo, cant_alumn_escalas,
            cant_creditos, total_ingresos, "Matricula.txt");
    
    ordenar(cant_escalas, anho, ciclo, escala_escala, costo, cant_alumn_escalas,
            cant_creditos, total_ingresos);
    
    imprimirReporte(cant_escalas, anho, ciclo, escala_escala, costo, 
            cant_alumn_escalas, cant_creditos, total_ingresos, 
            "Reporte_Ingresos_Ciclos_Escalas.txt");
    
    return 0;
}

