/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.cpp
 * Author: kenyi
 * 
 * Created on 19 de junio de 2025, 04:19 PM
 */

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "Tesoreria.h"

void Tesoreria::cargaalumnos() {
    ifstream arch("Alumnos.csv", ios::in);
    if (!arch) {
        cout << "Error al abrir el arhivo alumnos.csv";
        exit(1);
    }
    aboleta.crear(arch);
}

void Tesoreria::imprimeboleta() {
    ofstream arch("Reporte.txt", ios::out);
    if (!arch) {
        cout << "Error al abrir el arhivo alumnos.csv";
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    aboleta.imprime(arch);
}

void Tesoreria::actualizaboleta() {
    aboleta.cargarEscala("escalas.csv");
    aboleta.actualizar();
    
}
