/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 9 de noviembre de 2024, 11:36
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include "Alumno.h"
#include "Cursos.h"
#include "Escala.h"

#include <fstream>
using namespace std;

int pedirSemestre();
void leerDatosAlumnos(int &cant_alumnos, struct Alumno *alumnos, 
        const char *nombAlum);
void leerAlumno(ifstream &archAlum, struct Alumno &alumnos);
void leerDatosCurso(int &cant_cursos, struct Curso *cursos, 
        const char *nombCurso);
void leerCurso(ifstream &archCurso, struct Curso &cursos);
void leerDatosEscalas(int &cant_escalas, struct Escala *escalas, 
        const char *nombEscala);
void leerEscala(ifstream &archEscala, struct Escala &escalas);
void procesarMatricula(int semestre, int cant_alumnos, struct Alumno *alumnos, 
        int cant_cursos, struct Curso *cursos, int cant_escalas,  
        struct Escala *escalas, const char *nombMatri);
void ordenarCursos(int cant_cursos, struct Curso *cursos);
void emitirReporte(int semestre, int cant_cursos, struct Curso *cursos,
        const char *nombReporte);
void intercambiarCadenas(char *cad1, char *cad2);
void intercambiarDouble(double &num1, double &num2);
void intercambiarInt(int &num1, int &num2);
int buscarEscala(char escala, int n, struct Escala *escalas);
int buscarCurso(int cod_curso, int n, struct Curso *cursos);
int buscarAlumno(int cod, int n, struct Alumno *alumno);
void imprimirEncabezado(ofstream &archReporte, int semestre);
void imprimirCaracter(char car, ofstream &archReporte) ;
void modificarTexto(char *cadena);

#endif /* FUNCIONESAUXILIARES_H */

