/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 14:34
 */

#include "Flota.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Flota::Flota() {
}

//Flota::Flota(const Flota& orig) {
//}

Flota::~Flota() {
}

void Flota::cargaflota(){
     
    ifstream arch("Vehiculos.csv", ios::in);
    if(!arch){
        cout << "ERROR: NO se pudo abrir el archivo vehiculos" << endl;
        exit(1);
    }
    lista.cargaFlota(arch);
    
 }


void Flota::muestracarga(){
    
    ofstream arch("ReporteFinal.txt", ios::out);
    if(!arch){
        cout << "ERROR: NO se pudo abrir el archivo reporte" << endl;
        exit(1);
    }
    
    arch << setprecision(2) << fixed;
    
    lista.imprime(arch);
}

void Flota::cargaPedidos(){
    
    bool encontrado;
    
    ifstream arch("Pedidos3.csv", ios::in);
    if(!arch){
        cout << "ERROR: NO se pudo abrir el archivo vehiculos" << endl;
        exit(1);
    }
    int cli;
    while(true){
        arch >>cli;
        if(arch.eof())break;
        arch.get();
        encontrado = lista.buscaActaulizaCliente(arch, cli);
        if(!encontrado) while(arch.get() != '\n');
    }
}