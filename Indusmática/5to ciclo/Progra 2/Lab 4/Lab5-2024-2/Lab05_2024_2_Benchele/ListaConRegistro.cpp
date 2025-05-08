/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ListaConRegistro.cpp
 * Author: Lenovo
 * 
 * Created on 6 de mayo de 2025, 11:49 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesComunes.h"
#include "ListaConRegistro.h"
using namespace std;

enum DUPLA{DAT, ARR};

enum REG{COD, NOM, VEH};

enum DATOS{DNI, CANT, PLA};

enum ORDEN{REP, DATOS};

/*
 JNV387,Justino Norabuena Virginia Karina,Motocicleta
 PRT150,Pairazaman Raffo Tatiana Delicia,Bicicleta
 */
void *leeRegistros(ifstream &arch){
    void **reg;
    char *cod, *nomb, *vehi;
    cod = leerCadenaExacta(arch, ',');
    if(arch.eof())return nullptr;
    
    //REG{COD, NOM, VEH};
    reg = new void*[3]{};
    reg[COD] = cod;
    reg[NOM] = leerCadenaExacta(arch, ',');
    reg[VEH] = leerCadenaExacta(arch);
    return reg;
}

// ->                //Dentro de la lista     //Leida
int compruebaRegistro(const void*a, const void*b){
    void **ai = (void **)a; 
    char *aii = (char *)ai[COD];
    char *cod = (char *)b;
    return strcmp(aii, cod);
}
/*
 12484697,2,AD-546,LAF361
 12484697,1,PO-751,LAF361
 */

void *leeOrdenes(ifstream &arch){
    int *dni, auxDni, *cant;
    char *codPla, *codRep, c;
    arch>>auxDni;
    if(arch.eof())return nullptr;
    dni = new int;
    *dni = auxDni;
    cant = new int;
    arch>>c>>*cant>>c;
    codPla = leerCadenaExacta(arch, ',');
    codRep = leerCadenaExacta(arch);
    
    void **datos;
    void **reg;
    
    //DATOS{DNI, CANT, PLA}
    datos = new void*[3]{};
    datos[DNI] = dni;
    datos[CANT] = cant;
    datos[PLA] = codPla;
    
    //ORDEN{REP, DATOS}
    reg = new void*[2]{};
    reg[REP] = codRep;
    reg[DATOS] = datos;
    
    return reg;
}


void imprimeRegistros(ofstream &arch, void *dato){
    void **registro = (void **)dato;
    void **repartidor = (void **)registro[REP], 
         **ordenes = (void **)registro[DATOS];
    imprimirRepartidor(arch, repartidor);
    imprimirOrdenes(arch, ordenes);
    arch<<endl;
}


void imprimirRepartidor(ofstream &arch, void **repartidor){
    //REG{COD, NOM, VEH};
    char *nombre = (char *)repartidor[NOM];
    char *cod = (char *)repartidor[COD];
    char *vehi = (char *)repartidor[VEH];
    arch<<left<<setw(10)<<cod<<setw(40)<<nombre<<setw(10)<<" "<<vehi<<endl;
}
void imprimirOrdenes(ofstream &arch, void **ordenes){
    arch<<endl<<"Ordenes: "<<endl<<endl;
    for (int i = 0; ordenes[i]; i++) {
            imprimirOrden(arch, ordenes[i]);
        }
}
void imprimirOrden(ofstream &arch, void *ord){
    //DATOS{DNI, CANT, PLA};
    
    void **orden = (void **)ord;
    int *dni = (int *)orden[DNI];
    int *cant = (int *)orden[CANT];
    char *pla = (char *)orden[PLA];
    arch<<right<<*dni<<setw(12)<<*cant<<setw(16)<<pla<<endl;
}


