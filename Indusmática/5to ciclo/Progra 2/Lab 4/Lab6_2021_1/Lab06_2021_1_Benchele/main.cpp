/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 8 de mayo de 2025, 10:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistro.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *lista1, *lista2;
    
    //Pregunta 1
    creaLista(lista1, leeNum, cmpNum, "RegistroDeFaltas1.csv");
    //imprimeLista(lista1, imprimeNum, "ReporteLista1Prueba.txt");
    creaLista(lista2, leeNum, cmpNum, "RegistroDeFaltas2.csv");
    //imprimeLista(lista2, imprimeNum, "ReporteLista2Prueba.txt");
    uneLista(lista1, lista2);
    imprimeLista(lista1, imprimeNum, "ReporteNum.txt");

    //Pregunta 2
    creaLista(lista1, leeReg, cmpReg, "RegistroDeFaltas1.csv");
    creaLista(lista2, leeReg, cmpReg, "RegistroDeFaltas2.csv");
    uneLista(lista1, lista2);
    imprimeLista(lista1, imprimeReg, "ReporteFalta.txt");
    return 0;
}

