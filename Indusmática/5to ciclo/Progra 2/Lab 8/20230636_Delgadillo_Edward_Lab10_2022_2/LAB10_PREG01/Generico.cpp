/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Generico.cpp
 * Author: 00123
 * 
 * Created on 18 de junio de 2025, 07:47 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Generico.h"
#include "Medicamento.h"
using namespace std;

Generico::Generico() {
    
    pais=nullptr;
}

//Generico::Generico(const Generico& orig) {
//}

Generico::~Generico() {
    
    if(pais)delete pais;
}

void Generico::SetPais(char* cad) {
    
    if(pais)delete pais;
    pais=new char[strlen(cad)+1];
    strcpy(pais,cad);
}

void Generico::GetPais(char*cad) const {
    
    if(pais)strcpy(cad,pais);
    else cad[0]=0;
}

void Generico::leer(ifstream& arch){
    
    Medicamento::leer(arch);
    char cad[20];
    arch.getline(cad,20);
    SetPais(cad);
}

void Generico::imprimir(ofstream& arch) {

    Medicamento::imprimir(arch);
    arch<<left<<setw(30)<<pais<<endl;
}

bool Generico::esDeMarca() {

    return false;
}
