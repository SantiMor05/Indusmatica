/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Oracion.cpp
 * Author: 00123
 * 
 * Created on 23 de junio de 2025, 05:05 PM
 */

#include <iostream>
#include <string>
#include <vector> 
using namespace std;
#include "Palabra.h"
#include "Oracion.h"

Oracion::Oracion() {
    cantidad_palabras=0;
    polaridad_total=0;
}
//
//Oracion::Oracion(const Oracion& orig) {
//}
//
//Oracion::~Oracion() {
//}

void Oracion::agregar(string aux, int pola) {

    Palabra palabra;
    palabra.SetTexto(aux);
    palabra.SetPolaridad(pola);
    palabras.push_back(palabra);
    cantidad_palabras++;
    polaridad_total+=pola;
}

void Oracion::estadistico(int& posi, int& nega, int& neutros) {

    for(auto palabra:palabras){
        if(palabra.GetPolaridad()>0)posi++;
        else if(palabra.GetPolaridad()<0)nega++;
        else neutros++;
    }
}
