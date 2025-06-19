/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medicamento.cpp
 * Author: 00123
 * 
 * Created on 18 de junio de 2025, 07:47 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Medicamento.h"
using namespace std;

Medicamento::Medicamento() {
    
    nombre=nullptr;
}

//Medicamento::Medicamento(const Medicamento& orig) {
//}

Medicamento::~Medicamento() {
    
    if(nombre)delete nombre;
}

void Medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double Medicamento::GetPrecio() const {
    return precio;
}

void Medicamento::SetStock(int stock) {
    this->stock = stock;
}

int Medicamento::GetStock() const {
    return stock;
}

void Medicamento::SetNombre(char* cad) {
    
    if(nombre)delete nombre;
    nombre=new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void Medicamento::GetNombre(char*cad) const {
    
    if(nombre)strcpy(cad,nombre);
    else cad[0]=0;
}

void Medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medicamento::GetCodigo() const {
    return codigo;
}

void Medicamento::leer(ifstream& arch) {

    char c,nomb[100];
    arch>>codigo>>c;
    arch.getline(nomb,100,',');
    SetNombre(nomb);
    arch>>stock>>c>>precio>>c;
}

void Medicamento::imprimir(ofstream& arch) {

    arch<<codigo<<"  "<<left<<setw(70)<<nombre<<"  "<<right<<
            setw(6)<<stock<<"  "<<setw(6)<<precio<<"  ";
}


bool Medicamento::operator>(Medicamento& medi) {

    return codigo>medi.codigo;
}

void operator <<(ofstream&arch,Medicamento&medi){
    
    medi.imprimir(arch);
}