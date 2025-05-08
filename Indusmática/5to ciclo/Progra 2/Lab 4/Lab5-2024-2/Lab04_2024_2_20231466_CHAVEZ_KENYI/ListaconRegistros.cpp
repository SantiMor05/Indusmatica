/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ListaconRegistros.cpp
 * Author: kenyi
 * 
 * Created on 8 de mayo de 2025, 12:51 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ListaconRegistros.h"

void* leeregistro(ifstream &arch) {
    void **tripleta;
    char *cod;
    cod = leerExacto(arch, 7, ',');
    if (arch.eof())return nullptr;
    tripleta = new void*[3] {
    };
    tripleta[0] = cod;
    tripleta[1] = leerExacto(arch, 60, ',');
    ;
    tripleta[2] = leerExacto(arch, 20, '\n');
    ;
    return tripleta;
}

char *leerExacto(ifstream &arch, int max, char del) {
    char buff[max], *cad;
    arch.getline(buff, max, del);
    if (arch.eof())return nullptr;
    cad = new char[strlen(buff) + 1];
    strcpy(cad, buff);
    return cad;
}

int compruebaregistro(const void*dato1, const void*dato2) {
    void **reg1 = (void**) dato1;
    char *cod1 = (char*) reg1[0];
    char *cod2 = (char*) dato2;

    return strcmp(cod1, cod2);
}

void *leeordenes(ifstream &arch) {
    void **dupla, **dato;
    int dni, cant;
    char c;
    arch>>dni;
    if (arch.eof())return nullptr;
    arch >> c >> cant>>c;
    dupla = new void*[2];
    dato = new void*[3] {
    };
    dato[0] = new int{dni};
    dato[1] = new int{cant};
    dato[2] = leerExacto(arch, 8, ',');
    dupla[0] = leerExacto(arch, 8, '\n');
    dupla[1] = dato;
    return dupla;
}

void imprimeregistros(const void *dato, ofstream &arch) {
    void **dupla = (void**) dato;
    void **arr = (void**) dupla[1];
    void **repartidor = (void**) dupla[0];
    char *cod = (char*) repartidor[0], *nom = (char*) repartidor[1],
            *veh = (char*) repartidor[2];
    void **tripleta;
    int *cant, *dni;
    char *plat;
    arch << left << setw(16) << cod << setw(40) << nom << setw(20) <<
            veh << endl;
    arch << "Ordenes:" << endl;
    for (int i = 0; arr[i]; i++) {
        tripleta = (void **) arr[i];
        dni = (int *) tripleta[0];
        cant = (int *) tripleta[1];
        plat = (char *) tripleta[2];

        arch << setw(20) << left << *dni << setw(6) << *cant
                << setw(8) << plat << endl;
    }
    arch << endl;
}

