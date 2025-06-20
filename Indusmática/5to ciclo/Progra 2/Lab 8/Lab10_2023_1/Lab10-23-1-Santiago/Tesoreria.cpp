/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 21:37
 */

#include "Tesoreria.h"
#include "Arbol.h"
#include <iostream>
#include <fstream>
#include <set>
#include <iomanip>
using namespace std;

Tesoreria::Tesoreria() {
}

Tesoreria::Tesoreria(const Tesoreria& orig) {
}

Tesoreria::~Tesoreria() {
}


void Tesoreria::cargaalumnos(){
    
    ifstream arch("Alumnos.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo alumnos" << endl;
        exit(1);
    }
    
    aboleta.cargaalumnos(arch);
    
}


void Tesoreria::imprimeBoleta(){
    ofstream arch("ReporteFinal.txt", ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo alumnos" << endl;
        exit(1);
    }
    arch << setprecision(2) << fixed;
    aboleta.imprimeBoletas(arch);
}


void Tesoreria::actualizaboleta(){
    
    ifstream arch("escalas.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo alumnos" << endl;
        exit(1);
    }
    
    aboleta.leerEscalas(arch);
    
    aboleta.actualizaArbol();
    
}