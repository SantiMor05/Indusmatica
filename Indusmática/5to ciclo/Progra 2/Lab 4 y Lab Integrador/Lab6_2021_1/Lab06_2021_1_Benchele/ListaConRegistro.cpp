/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ListaConRegistro.cpp
 * Author: Lenovo
 * 
 * Created on 9 de mayo de 2025, 12:03 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesComunes.h"
#include "ListaConRegistro.h"
using namespace std;

enum CONDUCTOR{LIC, NOM};

enum FALTAS{LICF, PLA, FEC, INFRA};

/*
 88854166,H3E-885,11/10/2019,164
 13628871,F3E-797,13/01/2020,302
 FALTAS{LICF, PLA, FEC, INFRA};
 */
void *leeReg(ifstream &arch){
    void **reg;
    int *lic, auxLic, dd, mm, aa, *fecha, *numInfra;
    char *placa, c;
    
    arch>>auxLic;
    if(arch.eof())return nullptr;
    lic = new int{auxLic};
    fecha = new int;
    numInfra = new int;
    arch>>c;
    placa = leerCadenaExacta(arch, ',');
    arch>>dd>>c>>mm>>c>>aa>>c>>*numInfra;
    *fecha = aa*10000+mm*100+dd;
    
    //FALTAS{LICF, PLA, FEC, INFRA};
    reg = new void*[4]{};
    reg[LICF] = lic;
    reg[PLA] = placa;
    reg[FEC] = fecha;
    reg[INFRA] = numInfra;
    
    return reg;
}

int cmpReg(const void*a, const void*b){
    void **ai = (void **)a,
         **bi = (void **)b;
    int *fechaA = (int *)ai[FEC],
        *fechaB = (int *)bi[FEC];
    return *fechaA - *fechaB;
}

void imprimeReg(ofstream &arch, void*anterior, void*actual){
    void **regAnt = (void **)anterior,
         **regAct = (void **)actual;

    int fechaAnioYMesAct = *(int *)regAct[FEC]/100, fechaAnioYMesAnt;
        
    if(anterior == nullptr){
        imprimirEncabezado(arch, fechaAnioYMesAct*100);
        imprimirRegistro(arch, regAct);
    }else{
        fechaAnioYMesAnt = *(int *)regAnt[FEC]/100;
        if(fechaAnioYMesAnt!=fechaAnioYMesAct){
            imprimirEncabezado(arch,fechaAnioYMesAct*100);
        }
        imprimirRegistro(arch,regAct);
    }
}

void imprimirEncabezado(ofstream &arch, int fecha){
    int dd, mm, aa;
    sacarDiaMesAnio(dd, mm, aa, fecha);
    imprimirLinea(arch, '=');
    arch<<endl;
    arch<<"Año: "<<aa<<"  Mes: "<<right<<setfill('0')<<setw(2)<<mm<<endl<<setfill(' ');
    imprimirLinea(arch, '-');
    arch<<left<<setw(10)<<"FECHA"<<setw(8)<<" "<<"LICENCIA"<<setw(8)<<" "<<setw(64)<<
                "         NOMBRE"<<"FALTA"<<endl;
    imprimirLinea(arch, '=');
}

void sacarDiaMesAnio(int &dia, int &mes, int &anio, int fecha){
    anio = fecha/10000;
    mes = (fecha - anio*10000)/100;
    dia = fecha - anio*10000 - mes*100;
}

void imprimirRegistro(ofstream &arch, void **reg){
    //Archivo conuctores para buscar el nombre
    ifstream archCond("Conductores.csv", ios::in);
    verificar_Apertura_I(archCond, "Conductores.csv");
    
    //FALTAS{LICF, PLA, FEC, INFRA};
    int *fecha= (int*)reg[FEC],
        *licencia = (int *)reg[LICF],
        *infra = (int *)reg[INFRA];
    char *placa = (char *)reg[PLA];
    
    int dd, mm, aa;
    sacarDiaMesAnio(dd, mm, aa, *fecha);
    
    char *nombCond = buscarConductor(archCond, *licencia); 
    if(nombCond){
        arch<<aa<<'/'<<right<<setfill('0')<<setw(2)<<mm<<'/'<<setw(2)<<dd<<"  "<<setfill(' ')
            <<setw(6)<<" "<<*licencia<<setw(12)<<" "<<left<<setw(61)<<nombCond<<*infra<<endl;
    }
}

/*
 32090869,SUELDO ANTEZANO LUIS JESUS
 66849703,MERCADO CORONEL ELIA
 LICENCIA, NOMBRE
 */
char* buscarConductor(ifstream &arch, int licencia){
    //Empezar a buscar otra vez desde el inicio
    //Pero no es necesario porque se abre el archivo cada vez que se llama a "imprimirRegistro"
    //arch.clear();
    //arch.seekg(0, ios::beg);
    
    int licenciaCond;    
    char *nombre;
    while(true){
        arch>>licenciaCond;
        if(arch.eof())break;
        arch.get();
        if(licenciaCond == licencia){
            nombre = leerCadenaExacta(arch);
            return nombre;
        }
        else{
            while(arch.get() != '\n');
        }
    }
    return nullptr;
}
