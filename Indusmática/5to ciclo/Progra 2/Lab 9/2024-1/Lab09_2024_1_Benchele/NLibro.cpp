/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NLibro.cpp
 * Author: Lenovo
 * 
 * Created on 26 de junio de 2025, 05:23 PM
 */

#include <iostream>
#include <fstream>
#include "NLibro.h"
#include "Libro.h"
#include "Novela.h"
#include "Revista.h"
#include "Enciclopedia.h"
using namespace std;

NLibro::NLibro() {
    pLibro = nullptr;
}

NLibro::NLibro(const NLibro& orig) {
    this->pLibro= orig.pLibro;
}

NLibro::~NLibro() {
    
}

void NLibro::asignaMemoria(char tipo){
    switch (tipo){
        case 'N':
            pLibro = new Novela;
            break;
        case 'R':
            pLibro = new Revista;
            break;
        case 'E':
            pLibro = new Enciclopedia;
            break;
    }
}
void NLibro::leer(ifstream &arch){
    pLibro->lee(arch);
}

double NLibro::getPeso()const{
    return pLibro->GetPeso();
}

void NLibro::imprimir(ofstream &arch){
    pLibro->imprime(arch);
    arch<<endl;
}