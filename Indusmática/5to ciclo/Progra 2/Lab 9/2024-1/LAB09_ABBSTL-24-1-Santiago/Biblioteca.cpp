/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.cpp
 * Author: santi
 * 
 * Created on 25 de junio de 2025, 22:35
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Biblioteca.h"
#include "NEstante.h"

Biblioteca::Biblioteca() {
}

//Biblioteca::Biblioteca(const Biblioteca& orig) {
//}

Biblioteca::~Biblioteca() {
}


void Biblioteca::carga(){
    
    ifstream archEstantes("Estantes3.csv", ios::in);
    if(!archEstantes){
        cout << "ERROR: No se pudo abrir el archivo estante" << endl;
        exit(1);
    }
    
    ifstream archLibros("Libros31.csv", ios::in);
    if(!archLibros){
        cout << "ERROR: No se pudo abrir el archivo libros" << endl;
        exit(1);
    }
    AEstante.carga(archEstantes, archLibros);
}


void Biblioteca::muestra(){
    
    ofstream arch("Reporte.txt", ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo reporte" << endl;
        exit(1);
    }
    arch << setprecision(2) << fixed;
    AEstante.imprime(arch);
    
}

void Biblioteca::prueba(double num){
    ofstream arch("ReportePrueba.txt", ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo reporte" << endl;
        exit(1);
    }
    
    arch << setprecision(2) << fixed;
   
    AEstante.busca(arch, num);
    
}