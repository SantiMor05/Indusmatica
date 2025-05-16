/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesEnteras.cpp
 * Author: santi
 * 
 * Created on 6 de mayo de 2025, 22:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesEnteras.h"
#include "BibliotecaGenerica.h"

using namespace std;

void *leenum(ifstream &arch){
    int n, *num;
    
    arch >> n;
    if(arch.eof())return nullptr;
    num = new int{n};
    return num;
}


void imprimenum(void *dato, ofstream &arch){
    
    int *n = (int*)dato;
    
    arch << *n << endl;
    
}

int cmpnum(const void *dato1, const void *dato2){
    int *n1 = (int *)dato1;
    int *n2 = (int *)dato2;
    
    return *n1 - *n2;
}