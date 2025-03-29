/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 5 de octubre de 2024, 14:44
 */


#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"
#define CANT_ALUM 100
#define CANT_CURSOS 50
#define ESCALAS 10

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int cod_alum[CANT_ALUM], escala_alum[CANT_ALUM], cant_cursos_matri[CANT_ALUM]{};
    double total_creditos[CANT_ALUM]{}, pago[CANT_ALUM]{};
    
    int cod_curso[CANT_CURSOS], alum_matriculados[CANT_CURSOS]{};
    double credito_curso[CANT_CURSOS], total_ingresos[CANT_CURSOS]{};
            
    double escala[ESCALAS];
    int cant_cursos, cant_alumnos, cant_escalas;
    
    leerAlumnos(cant_alumnos,cod_alum, escala_alum, "Alumnos_lab5.txt");
    
    leerCursos(cant_cursos,cod_curso, credito_curso, "Cursos_lab5.txt");
    
    leerEscalas(cant_escalas, escala, "Escalas_lab5.txt");
    
    actualizarDatos(cant_alumnos,cod_alum, escala_alum, total_creditos,
            cant_cursos_matri, pago, cant_cursos, cod_curso, credito_curso, 
            alum_matriculados, total_ingresos, cant_escalas, escala, 
            "Matricula_lab5.txt");
    
    ordenarAlumnos(cant_alumnos,cod_alum, escala_alum, total_creditos,
            cant_cursos_matri, pago);
    
    ordenarCursos(cant_cursos, cod_curso, credito_curso, 
            alum_matriculados, total_ingresos);
    
    
    imprimirReporte(cant_alumnos,cod_alum, escala_alum, total_creditos,
            cant_cursos_matri, pago, cant_cursos, cod_curso, credito_curso, 
            alum_matriculados, total_ingresos, "Reporte.txt");
    
    return 0;
}

