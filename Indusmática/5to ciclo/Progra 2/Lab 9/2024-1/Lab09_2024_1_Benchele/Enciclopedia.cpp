/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: Lenovo
 * 
 * Created on 26 de junio de 2025, 05:21 PM
 */

#include <iostream>
#include <iomanip>
#include "Enciclopedia.h"
using namespace std;

Enciclopedia::Enciclopedia() {
}

Enciclopedia::Enciclopedia(const Enciclopedia& orig) {
}

Enciclopedia::~Enciclopedia() {
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}

/*
 N,Diamantes y pedernales,120,0.7,  Jose Maria Arguedas
 E,ENCICLOPEDIA SALVAT,2000,12,     78323,2015
 R,Educacion,48,0.2,    10199403,2024,6
   NOMBRE  PAGINAS   PESO
 */
void Enciclopedia::lee(ifstream &arch){
    Libro::lee(arch);
    char c;
    arch>>sku>>c>>anho;
    arch.get();
}

void Enciclopedia::imprime(ofstream &arch){
    Libro::imprime(arch);
    arch<<"SKU:"<<left<<setw(15)<<sku<<"Anho: "<<anho<<endl;
}
