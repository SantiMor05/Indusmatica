/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesEnteras.cpp
 * Author: Lenovo
 * 
 * Created on 7 de mayo de 2025, 11:28 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesComunes.h"
#include "FuncionesEnteras.h"
using namespace std;

void *leeNum(ifstream &arch){
    int *num, aux;
    arch>>aux;
    if(arch.eof())return nullptr;
    num = new int;
    *num = aux;
    return num;
}

void imprimeNum(ofstream &arch, void *dato){
    int *num = (int *)dato;
    arch<<setw(4)<<"- "<<*num<<endl;
}

int cmpNum(const void*a, const void *b){
    int *ai = (int *)a, *bi = (int *) b;
    return *ai - *bi;
}