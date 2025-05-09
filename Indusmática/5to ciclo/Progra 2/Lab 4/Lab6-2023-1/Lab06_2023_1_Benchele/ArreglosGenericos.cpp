/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ArreglosGenericos.cpp
 * Author: Lenovo
 * 
 * Created on 8 de mayo de 2025, 06:05 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <memory>
#include "FuncionesComunes.h"
#include "ArreglosGenericos.h"
using namespace std;

enum REG{COD, NOM, ROL, CAT, PUNT};
        
enum LISTA{CAB, COL};

enum NODO{DAT, SIG};

void llenarArregloHeroes(void *&arrHer, int &cant, const char*nombArch){
    ifstream arch(nombArch, ios::in);
    verificar_Apertura_I(arch, nombArch);
    
    //Metodo memoria exacta
    void *arrHeroes[300]{}, **her; 
    void *reg;
    cant = 0;
    while (true) {
        reg = leerRegistro(arch);
        if(arch.eof())break;
        arrHeroes[cant] = reg;
        cant++;
    }
    her = new void*[cant + 1]{};
    for (int i = 0; i < cant; i++) {
        her[i] = arrHeroes[i];
    }
    arrHer = her;
}


 /*
    133,Malzahar,MID,A,53.65
    195,Akali,TOP,B,41.14
    148,Morgana,SUPPORT,God,80.11
    //REG{COD, NOM, ROL, CAT, PUNT};
*/
void *leerRegistro(ifstream &arch){
    void **reg;
    int *cod, auxCod;
    double *punta;
    char *nomb, *rol, *cat, c;
    
    arch>>auxCod;
    if(arch.eof())return nullptr;
    cod = new int;
    cat = new char;
    punta = new double;
    *cod = auxCod;
    arch.get();
    nomb = leerCadenaExacta(arch, ',');
    rol = leerCadenaExacta(arch, ',');
    cat = leerCadenaExacta(arch, ',');
    arch>>*punta;
    
    //REG{COD, NOM, ROL, CAT, PUNT};
    reg = new void*[5]{};
    reg[COD] = cod;
    reg[NOM] = nomb;
    reg[ROL] = rol;
    reg[CAT] = cat;
    reg[PUNT] = punta;
    
    return reg;
}

int cmpMulticriterioVoid(const void*a, const void*b){
    void **ai = (void **)a, **bi = (void **)b;
    void **aii = (void **)ai[0], **bii = (void **)bi[0];
    char *nombA = (char *)aii[NOM], 
         *nombB = (char *)bii[NOM];
    double *sueA = (double *)aii[PUNT], 
           *sueB = (double *)bii[PUNT];
    
    int cmp = strcmp(nombA, nombB);
    if(cmp != 0){
        return cmp;
    }
    else{
        return *sueA - *sueB;
    }
}

void imrpimriHeros(void *arrHeroes){ //Esto es para probar si el arreglo esta bien definido
    void **heroes = (void **)arrHeroes;
    void **aux;
    int *cod;
    char *nomb;
    double *suedl;
    for (int i = 0; heroes[i]; i++) {
        aux = (void **)heroes[i];
        cod = (int *)aux[COD]; 
        nomb = (char *)aux[NOM]; 
        suedl = (double *)aux[PUNT]; 
        cout<<*cod<<"    "<<setw(20)<<nomb<<"  "<<*suedl<<endl;
    }

}

