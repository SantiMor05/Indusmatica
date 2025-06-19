/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.cpp
 * Author: 00123
 * 
 * Created on 18 de junio de 2025, 07:48 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Almacen.h"
#include "Arbol.h"
using namespace std;

//Almacen::Almacen() {
//}
//
//Almacen::Almacen(const Almacen& orig) {
//}
//
//Almacen::~Almacen() {
//}

void Almacen::carga(const char* nombArch) {

    ifstream arch(nombArch,ios::in);
    if(!arch){
        cout<<"Error en "<<nombArch; exit(1);
    }
    
    while(true){
        arbolalma.leer(arch);
        if(arch.eof())break;
    }
}

void Almacen::imprime(const char* nombArch) {

    ofstream arch(nombArch,ios::out);
    if(!arch){
        cout<<"Error en "<<nombArch; exit(1);
    }
    arbolalma.imprimir(arch);
}

void Almacen::actualiza(const char*nombArch) {

    ifstream arch(nombArch,ios::in);
    if(!arch){
        cout<<"Error en "<<nombArch; exit(1);
    }
    arbolalma.actualiza(arch);
    
}




