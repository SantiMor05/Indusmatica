/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinisterioTransportes.cpp
 * Author: 00123
 * 
 * Created on 26 de junio de 2025, 03:24 PM
 */
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#include "Cola.h"
#include "MinisterioTransportes.h"

//MinisterioTransportes::MinisterioTransportes() {
//}
//
//MinisterioTransportes::MinisterioTransportes(const MinisterioTransportes& orig) {
//}
//
//MinisterioTransportes::~MinisterioTransportes() {
//}

void MinisterioTransportes::cargarConductores() {

    ifstream arch("Conductores.csv",ios::in);
    if(!arch){
        cout<<"Error en "<<"Conductores.csv";exit(1);
    }
    Conductor condu;
    while(true){
        condu.leer(arch);
        if(arch.eof())break;
        colaConductores.encolar(condu);
    }
}

//void MinisterioTransportes::cargarUnidades() {
//
//    ifstream arch("Unidades.csv",ios::in);
//    if(!arch){
//        cout<<"Error en "<<"Unidades.csv";exit(1);
//    }
//    int dni;
//    Conductor condu;
//    while(true){
//        arch>>dni;
//        if(arch.eof())break;
//        arch.get();
//        arch>>placa;
//        condu=buscarCondu(dni)
//    }
//}

void MinisterioTransportes::cargarInfracciones() {

    ifstream arch("Infracciones.csv",ios::in);
    if(!arch){
        cout<<"Error en "<<"Infracciones.csv";exit(1);
    }
    Infraccion infrac;
    while(true){
        infrac.leer(arch);
        if(arch.eof())break;
        infracciones.push_back(infrac);
    }
    
}

void MinisterioTransportes::destinarFaltas() {

    ifstream arch("Faltas.csv",ios::in);
    if(!arch){
        cout<<"Error en "<<"Faltas.csv";exit(1);
    }
    int dni;
    int codigoInfrac;
    Conductor condu;
    Infraccion infrac;
    while(true){
        arch>>dni;
        if(arch.eof())break;
        arch.get();
        condu=buscarCondu(dni);
        
        arch>>codigoInfrac;
        arch.get();        
        infrac=buscarInfrac(codigoInfrac);
        
        condu.actualizar(arch,infrac);
        
        colaConductores.encolar(condu);
    }
}

Conductor MinisterioTransportes::buscarCondu(int dni) {

    Conductor condu;
    while(true){
        condu=colaConductores.desencolar();
        if(condu.GetDni()==dni)
            return condu;
        else
            colaConductores.encolar(condu);
    }
    cout<<"nada"<<endl;
}

Infraccion MinisterioTransportes::buscarInfrac(int codigo) {

    for(auto infrac:infracciones){
        if(infrac.GetCodigo()==codigo)return infrac;
    }
    cout<<"nada2"<<endl;
}



void MinisterioTransportes::impirmir() {

    ofstream arch("Reporte.txt",ios::out);
    if(!arch){
        cout<<"Error en "<<"Reporte.txt";exit(1);
    }
    Conductor condu;
    while(!colaConductores.esVacia()){
        condu=colaConductores.desencolar();
        condu.imprimir(arch);
        arch<<endl;
    }
}


