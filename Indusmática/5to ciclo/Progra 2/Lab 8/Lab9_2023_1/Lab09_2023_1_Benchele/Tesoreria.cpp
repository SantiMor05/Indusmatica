/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tesoreria.cpp
 * Author: Lenovo
 * 
 * Created on 18 de junio de 2025, 03:06 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Tesoreria.h"
#define MAX_LINEA 120
using namespace std;

Tesoreria::Tesoreria() {
    for (int i = 0; i < 10; i++) {
        lEscala[i].SetCodigo(0);
    }
}

Tesoreria::~Tesoreria() {
}

/*
 5,666.90
 4,556.70
*/
void Tesoreria::cargaEscalas(const char*nombArch){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    int cod;
    double prec;
    while (true) {
        arch>>cod;
        if(arch.eof())break;
        arch.get();
        arch>>prec;
        lEscala[cod - 1].asigna(cod, prec);
    }  
}

/*
 V,202319927,PATINO/MEZA/MANUEL,3,19.5,872193-E
 P,202221155,CORRALES/ZIMIC/JAIME-DANIEL,5,18,20
 S,202315724,VEGA/SAENZ/ALEXANDER-RICHARD,4,19.5,50
 */
void Tesoreria::cargaAlumnos(const char*nombArch){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    char tipo;
    int nD = 0;
    while (true) {
        arch>>tipo;
        if(arch.eof())break;
        arch.get();
        switch(tipo){ //Crea los espacios de memoria segun la clase que corresponde, esto ayuda al polimorfismo ...(*)
            case 'P':
                lBoleta[nD].asignaPresencial();
                break;
            case 'S':
                lBoleta[nD].asignaSemipresencial();
                break;
            case 'V':
                lBoleta[nD].asignaVirtual();
                break;
        }
        lBoleta[nD].lee(arch); //A cada dato de boleta se le crea su clase correspondiente
        nD++;
    }
}

void Tesoreria::actualiza(double creditos){
    int escala;
    double precio;
    for (int i = 0; not lBoleta[i].ultimo(); i++) {
        escala = lBoleta[i].GetEscala();
        precio = lEscala[escala - 1].GetPrecio();
        lBoleta[i].actualiza(precio*creditos);
    }
}

void Tesoreria::imprimirBoleta(const char*nombArch){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }

    arch<<fixed<<setprecision(2);
    
    arch<<right<<setw((MAX_LINEA + 18)/2)<<"REPORTE DE ALUMNOS"<<endl;
    
    imprimirLinea(arch, '=');
    
    arch<<left<<setw(10)<<"Codigo"<<setw(40)<<"Nombre"<<right<<setw(3)<<"Escala"
        <<right<<setw(12)<<"Licencia"<<setw(10)<<"Total"<<endl;
    
    imprimirLinea(arch,'-');
    
    for(int i=0; not lBoleta[i].ultimo(); i++){
        lBoleta[i].imprime(arch);
    }   
}

void Tesoreria::imprimirLinea(ofstream &arch, char linea){
    for (int i = 0; i < MAX_LINEA; i++)arch.put(linea);
    arch<<endl;
}