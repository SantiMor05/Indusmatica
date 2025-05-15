/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConEnteros.cpp
 * Author: santi
 * 
 * Created on 14 de mayo de 2025, 10:26
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "ListaConEnteros.h"

using namespace std;


void *leenum(ifstream &arch){
    int dd, mm,aa,*fecha;
    char buffer[100], car;
    
    arch.getline(buffer, 100, ',');
    if(arch.eof())return nullptr;
    arch.getline(buffer, 100, ',');
    arch >> dd >> car >> mm >> car >> aa >> car;
    arch.getline(buffer, 100, '\n');
    
    fecha = new int{aa * 10000 + mm * 100 + dd};
    return fecha;
}


int cmpnum(const void *dato1, const void *dato2){
    
    int *fecha1 = (int *)dato1;
    int *fecha2 = (int *)dato2;
    
    return *fecha1 - *fecha2;
}

void imprimenum(const void *dato, ofstream &arch){
    static int ant = 0;
    int *fecha = (int *)dato;
    if(*fecha != ant){
        arch << *fecha << endl;
        ant = *fecha;
    }
 
}