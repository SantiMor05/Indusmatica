/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesRegistros.cpp
 * Author: santi
 * 
 * Created on 7 de mayo de 2025, 21:50
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesRegistros.h"

using namespace std;



void *leeregistro(ifstream &arch){
    
    int n, *pedido, *dni;
    char *libro, car;
    void **registro;
    arch >> n;
    if(arch.eof())return nullptr;
    pedido = new int{n};
    dni = new int;
    arch >> car >> *dni >> car;
    libro = leerCadenaExacta(arch, '\n');
    
    registro = new void*[3];
    registro[0] = pedido;
    registro[1] = dni;
    registro[2] = libro;
    
    return registro;
}

char *leerCadenaExacta(ifstream &arch, char deli){
    
    char buffer[200], *cad;
    arch.getline(buffer, 200, deli);
    if(arch.eof())return nullptr;
    cad = new char [strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
    
}

void imprimeRegistro(void *dato, ofstream &arch){
    
    void **registro = (void **)dato;
    int *dni = (int *)registro[1], *pedido = (int *)registro[0];
    char *libro = (char *)registro[2];
    
    arch << setw(4) << *pedido << setw(12) << *dni  << setw(10) << libro 
            << endl;
    
}

int cmpregistro(const void *dato1, const void *dato2){
    void **reg1 = (void **)dato1, **reg2 = (void **)dato2;
    int *pedido1 = (int *)reg1[0];
    int *pedido2 = (int *)reg2[0];
    
    return *pedido1 - *pedido2;
}