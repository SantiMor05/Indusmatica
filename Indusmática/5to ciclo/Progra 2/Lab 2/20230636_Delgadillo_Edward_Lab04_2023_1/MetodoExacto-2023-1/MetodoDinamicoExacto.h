/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: 00123
 *
 * Created on 20 de abril de 2025, 12:54 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <fstream>
using namespace std;


void lecturaAlumnos(const char*nombArch,int*&alumnoCodigo,char**&alumnoNombre,
        char*&alumnoModalidad,int*&alumnoPorcentaje,int*&alumnoEscala);
void apertura(bool abierto,const char*nombArch);
char*leeCadena(ifstream &arch,char deli);
void completarBufs(ifstream &arch,char &modalidad,int &porcentaje,
        int &escala);

void pasarInfo(int*&alumnoCodigo,char**&alumnoNombre,
        char*&alumnoModalidad,int*&alumnoPorcentaje,int*&alumnoEscala,
        int*bufCod,char**bufNomb,char*bufMod,int*bufPorcen,int*bufEsca,
        int nd);

void pruebaLecturaAlumnos(const char*nombArch,int*alumnoCodigo,char**alumnoNombre,
        char*alumnoModalidad,int*alumnoPorcentaje,int*alumnoEscala);
void lecturaCursos(const char*nombArch,int*alumnoCodigo,int*alumnoEscala,
        char**&cursoNombre,double*&cursoCredito,int**&cursoAlumnos);
void pruebaDeLecturaCursos(const char*nombArch,
        char**cursoNombre,double*cursoCredito,int**cursoAlumnos);

void hacerExacto(int**bufCurAl,int*cantAlenCur);
void reducirEspacio(int*&alumnos,int cant);
void pasarInfo(char**&cursoNombre,double*&cursoCredito,int**&cursoAlumnos,
            char**bufCurNomb,double*bufCurCred,int**bufCurAl,int nd);
void actualizarCurAls(int*alumnosDeCurso,int codigo,int escala,int cantAl);
int buscarCodigo(int*alumnoCodigo,int codigo);
int buscarCurso(char**cursoNombre,const char*nombCurso);
void crearCurso(const char*nombreRef,double creditoRef,
        char*&nombre,double &credito,int*&alumnosDeCurso);
void imprimirCurso(ofstream &arch,char*nombre,double credito,int*alumnos);
void imprimirAlumno(ofstream &arch,int codigo,int escala);

void reporteDeRecaudacionPorModalidad(const char*nombArch,
        int*alumnoCodigo,char**alumnoNombre,
        char*alumnoModalidad,int*alumnoPorcentaje,
        char**cursoNombre,double*cursoCredito,int**cursoAlumnos);
void imprimirCabecera(ofstream &arch);
void imprimeLinea(ofstream &arch,int n,char c);
void imprimirInfoCurso(ofstream &arch,int*alumnos,double creditos,
        int*alumnoCodigo,char**alumnoNombre,char*alumnoModalidad,
        int*alumnoPorcentaje,
        double &totalPrese,double &totalSemi,double &totalVirtu);
double hallarValor(int escala);
void imprimirGasto(ofstream &arch,double gasto,int n);


#endif /* FUNCIONES_H */

