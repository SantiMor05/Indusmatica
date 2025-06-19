/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Marca.cpp
 * Author: 00123
 * 
 * Created on 18 de junio de 2025, 07:47 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Marca.h"
#include "Medicamento.h"
using namespace std;

Marca::Marca() {
    
    laboratorio=nullptr;
}

//Marca::Marca(const Marca& orig) {
//}

Marca::~Marca() {
    
    if(laboratorio)delete laboratorio;
}

void Marca::SetLaboratorio(char* cad) {
    
    if(laboratorio)delete laboratorio;
    laboratorio=new char[strlen(cad)+1];
    strcpy(laboratorio,cad);
}

void Marca::GetLaboratorio(char*cad) const {
    
    if(laboratorio)strcpy(cad,laboratorio);
    else cad[0]=0;
}

void Marca::SetLote(int lote) {
    this->lote = lote;
}

int Marca::GetLote() const {
    return lote;
}

void Marca::leer(ifstream& arch){
    
    Medicamento::leer(arch);
    char cad[60];
    arch.getline(cad,60,',');
    SetLaboratorio(cad);
    arch>>lote;
}

void Marca::imprimir(ofstream& arch) {

    Medicamento::imprimir(arch);
    arch<<left<<setw(30)<<laboratorio<<"  "<<lote<<endl;
}

bool Marca::esDeMarca() {

    return true;
}
