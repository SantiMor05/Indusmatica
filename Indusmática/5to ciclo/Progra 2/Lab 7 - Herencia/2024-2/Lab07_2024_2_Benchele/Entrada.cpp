/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Entrada.cpp
 * Author: Lenovo
 * 
 * Created on 12 de junio de 2025, 05:21 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Entrada.h"
#include "Producto.h"
using namespace std;

Entrada::Entrada() {
    picante = false;
}

Entrada::~Entrada() {
}

void Entrada::SetPicante(bool picante) {
    this->picante = picante;
}

bool Entrada::IsPicante() const {
    return picante;
}

/*
 142,E,Bruschetta,4,picante
 */
//Leer datos
void Entrada::leerDatos(ifstream &arch){
    Producto::leerDatos(arch); //Herencia
    
    char aux[60], pic[60] = "picante";
    arch.getline(aux, 60);
    
    if(strcmp(aux, pic) == 0)picante = true;
    
}

//Imprimir
void Entrada::imprimir(ofstream &arch){
    Producto::imprimir(arch); //Herencia
    arch<<"PICANTE: ";

    if(picante)arch<<right<<setw(7)<<"SI";
    else arch<<right<<setw(7)<<"NO";
    arch<<endl;
}