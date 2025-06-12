/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tesoreria.h
 * Author: Usuario
 *
 * Created on 10 de junio de 2025, 15:57
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Alumno.h"
#include "Escala.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

class Tesoreria {
private:
    Presencial lpresencial[100];
    Semipresencial lsemipresencial[100];
    Virtual lvirtual[100];
    Escala lescala[10];
public:
    Tesoreria();
    virtual ~Tesoreria();
    void cargaEscalas(const char* nomArch);
    void cargaAlumnos(const char* nomArch);
    void leer_alumnos(ifstream &arch, char c, int &numPres,int &numSemi, int &numVirt);
    void actualiza();
    void imprime(const char* nomArch);
};

void imprimir_linea(ofstream &arch,char c, int n);

#endif /* TESORERIA_H */

