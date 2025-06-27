/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Novela.cpp
 * Author: Lenovo
 * 
 * Created on 26 de junio de 2025, 05:22 PM
 */

#include <iostream>
#include <iomanip>
#include "Novela.h"
using namespace std;

Novela::Novela() {
}

Novela::Novela(const Novela& orig) {
}

Novela::~Novela() {
}

void Novela::SetAutor(string autor) {
    this->autor = autor;
}

string Novela::GetAutor() const {
    return autor;
}

/*
 N,Diamantes y pedernales,120,0.7,  Jose Maria Arguedas
 E,ENCICLOPEDIA SALVAT,2000,12,     78323,2015
 R,Educacion,48,0.2,    10199403,2024,6
   NOMBRE  PAGINAS   PESO
 */
void Novela::lee(ifstream &arch){
    Libro::lee(arch);
    getline(arch, autor);
}
void Novela::imprime(ofstream &arch){
    Libro::imprime(arch);
    arch<<"Autor: "<<autor<<endl;
}