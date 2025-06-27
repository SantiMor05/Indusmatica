/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Revista.cpp
 * Author: Lenovo
 * 
 * Created on 26 de junio de 2025, 05:22 PM
 */

#include <iostream>
#include <iomanip>
#include "Revista.h"
using namespace std;

Revista::Revista() {
}

Revista::Revista(const Revista& orig) {
}

Revista::~Revista() {
}

void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}

void Revista::SetISSN(int ISSN) {
    this->ISSN = ISSN;
}

int Revista::GetISSN() const {
    return ISSN;
}

/*
 N,Diamantes y pedernales,120,0.7,  Jose Maria Arguedas
 E,ENCICLOPEDIA SALVAT,2000,12,     78323,2015
 R,Educacion,48,0.2,    10199403,2024,6
   NOMBRE  PAGINAS   PESO
 */
void Revista::lee(ifstream &arch){
    Libro::lee(arch);
    char c;
    arch>>ISSN>>c>>anho>>c>>numero;
    arch.get();
}
void Revista::imprime(ofstream &arch){
    Libro::imprime(arch);
    arch<<"ISSN: "<<left<<setw(15)<<ISSN<<"Anho: "<<anho<<endl;
}
