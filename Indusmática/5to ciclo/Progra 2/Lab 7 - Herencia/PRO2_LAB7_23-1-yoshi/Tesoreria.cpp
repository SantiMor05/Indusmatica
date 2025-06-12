/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tesoreria.cpp
 * Author: YOSHI
 * 
 * Created on 10 de junio de 2025, 15:57
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Tesoreria.h"

#define MAX_NUM_CAR 120

Tesoreria::Tesoreria() {
}

Tesoreria::~Tesoreria() {
}

void Tesoreria::cargaEscalas(const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    int numDat = 0;
    while(true){
        arch >> lescala[numDat];
        if (arch.eof()) break;
        numDat++;
    }
}

void Tesoreria::cargaAlumnos(const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    int i = 0;
    char c, cad[100], lic[12];
    int numPres = 0, numSemi = 0, numVirt = 0, codigo, escala;
    double monto;
    while(true){
        arch>>c;
        if (arch.eof()) break;
        arch.get();
        arch>>codigo;
        arch.get();
        arch.getline(cad,100,',');
        arch>>escala;
        arch.get();
        switch(c){
            case 'S':
                arch>>monto;
                lsemipresencial[numSemi].insertarDatoS(codigo,cad,escala,monto);
                numSemi++;
                break;
            case 'V':
                arch.getline(lic,12);
                lvirtual[numVirt].insertarDatoV(codigo,cad,escala,lic);
                numVirt++;
                break;
            case 'P':
                arch>>monto;
                lpresencial[numPres].insertarDatoP(codigo,cad,escala,monto);
                numPres++;
                break;
        }
    }
}

void Tesoreria::actualiza(){
    int escalin;
    double monto;
    for (int i = 0; lpresencial[i].getCodigo(); i++) {
        escalin = lpresencial[i].getEscala();
        monto = Busca_escala(lescala,escalin);
        lpresencial[i].actualiza(monto);
    }
    for (int i = 0; lsemipresencial[i].getCodigo(); i++) {
        escalin = lsemipresencial[i].getEscala();
        monto = Busca_escala(lescala,escalin);
        lsemipresencial[i].actualiza(monto);
    }
    for (int i = 0; lvirtual[i].getCodigo(); i++){
        escalin = lvirtual[i].getEscala();
        monto = Busca_escala(lescala,escalin);
        lvirtual[i].actualiza(monto);
    }

}

void Tesoreria::imprime(const char* nomArch){
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    arch<<"Codigo"<<setw(30)<<"Nombre"<<setw(25)<<"Escala"<<setw(15)<<"Licencia"<<setw(12)<<"Total"<<endl;
    imprimir_linea(arch,'=',MAX_NUM_CAR);
    for (int i = 0; lpresencial[i].getCodigo(); i++)
        lpresencial[i].imprimir(arch);
    for (int i = 0; lsemipresencial[i].getCodigo(); i++)
        lsemipresencial[i].imprimir(arch);
    for (int i = 0; lvirtual[i].getCodigo(); i++) {
        lvirtual[i].imprimir(arch);
    }

}

void imprimir_linea(ofstream &arch,char c, int n){
    for (int i = 0; i < n; i++) {
        arch.put(c);
    }
    arch<<endl;
}