/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ListaConEnteros.cpp
 * Author: Lenovo
 * 
 * Created on 8 de mayo de 2025, 11:00 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesComunes.h"
#include "ListaConEnteros.h"
using namespace std;

/*
 35912665,O2Z-308,22/07/2019,156
 32244565,M8W-853,18/11/2019,335
 */
void *leeNum(ifstream &arch){
    int dd, mm, aa, des;
    int *anio;
    char c, *desC;
    
    arch>>des;
    if(arch.eof())return nullptr;
    arch>>c;
    desC = leerCadenaExacta(arch, ',');
    arch>>dd>>c>>mm>>c>>aa>>c>>des;
    
    anio = new int;
    *anio = aa*10000+mm*100+dd;
    return anio;
    
}
int cmpNum(const void*a, const void*b){
    int *fechaA = (int *)a, 
        *fechaB = (int *)b;
    return *fechaA - *fechaB;
}

void imprimeNum(ofstream &arch, void *anterior, void *actual){
    int *fechaAnt = (int *)anterior,
        *fechaAct = (int *)actual; //Como solo existe un dato, no se hace problema
                                   //por manejar un indice de nullptr 
                                   //Sin embargo, si es un registro lo mejor sería colocarlo en "PuntoRef"
                                   //Ejemplo: int *dato = (int *)anterior[DATO]
                                   //Si anterior es nullptr, te va a dar infinito, TERRIBLE ERROR DE CONCEPTO
                                   //Por eso es mejor colocarlo en "PuntoRef"

    if(anterior == nullptr){
        arch<<"-  "<<setw(8)<<*fechaAct<<endl;
    }
    else{
        //PuntoRef
        //*fechaAct = (int *)actual;
        //Ejemplo: int *dato = (int *)anterior[DATO];
        if(*fechaAnt != *fechaAct)arch<<"-  "<<setw(8)<<*fechaAct<<endl; //Si son direntes imprime
    }
}
