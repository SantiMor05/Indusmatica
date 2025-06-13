/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PlatoFondo.cpp
 * Author: Lenovo
 * 
 * Created on 12 de junio de 2025, 05:22 PM
 */

#include <iostream>
#include <iomanip>
#include "PlatoFondo.h"
#include "Producto.h"
using namespace std; 

PlatoFondo::PlatoFondo() {
    proteina = nullptr;
}

PlatoFondo::~PlatoFondo() {
    if(proteina != nullptr)delete proteina;
}

void PlatoFondo::SetProteina(int* proteina) {
    this->proteina = proteina;
}

int* PlatoFondo::GetProteina() const {
    return proteina;
}

/*
 142,P,Pasta Alfredo,10,0,1,0,1
 */
//Leer datos
void PlatoFondo::leerDatos(ifstream &arch){
    Producto::leerDatos(arch); //Herencia
    
    proteina = new int[4]{};
    int activo;
    int cont = 0;
    while (true) {
        arch>>activo;
        proteina[cont] = activo;
        cont++; 
        if(arch.get() != ',')break;   
    }
}

//Imprimir
void PlatoFondo::imprimir(ofstream &arch){
    Producto::imprimir(arch); //Herencia
    arch<<"PROTEINAS: ";

    if(proteina[0])arch<< "Pollo " ;
    if(proteina[1] or proteina[2] or proteina[3])arch<<" | ";
    if(proteina[1])arch<< "Carne ";
    if(proteina[2] or proteina[3])arch<<" | ";
    if(proteina[2])arch<< "Pescado ";
    if(proteina[3])arch<<" | ";
    if(proteina[3])arch<< "Lácteos ";
    
    arch<<endl;
}