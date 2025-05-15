/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arreglos_genericos.cpp
 * Author: santi
 * 
 * Created on 15 de mayo de 2025, 10:37
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "arreglos_genericos.h"

using namespace std;

enum Heroe{COD, NOMB, ROL, CAT, PUNT};

void llenar_arreglo_heroes(void *&arreglo_heroes, int &cant, 
            const char *nombArch){
    
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    
    void *buffer[300]{}, *dato;
    cant = 0;
    while(true){
        dato = leerHeroe(arch);
        if(dato == nullptr)break;
        buffer[cant] = dato;
        cant++;
    }
    void **registro = new void *[cant + 1]{};
    for(int i = 0; i < cant; i++)
        registro[i] = buffer[i];
    
    arreglo_heroes = registro;
}


void *leerHeroe(ifstream &arch){
    
    int cod, *codigo;
    char *nombre, *rol, *categoria;
    double *puntaje;
    void **registro;
    arch >> cod;
    if(arch.eof())return nullptr;
    codigo = new int{cod};
    puntaje = new double;
    
    arch.get();
    nombre = leerCadenaExacta(arch, ',');
    rol = leerCadenaExacta(arch, ',');
    categoria = leerCadenaExacta(arch, ',');
    arch >> *puntaje;
    
    registro = new void *[5];
    registro[COD] = codigo;
    registro[NOMB] = nombre;
    registro[ROL] = rol;
    registro[CAT] = categoria;
    registro[PUNT] = puntaje;
    return registro;
}


char *leerCadenaExacta(ifstream &arch, char deli){
    
    char buffer[200], *cad;
    arch.getline(buffer, 200, deli);
    if(arch.eof())return nullptr;
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
    
}

int cmp_multicriterio_void(const void *dato1, const void *dato2){
    
    void **puntero1 = (void **)dato1;
    void **puntero2 = (void **)dato2;
    
    void **registro1 = (void **)puntero1[0];
    void **registro2 = (void **)puntero2[0];
    
    char *nombre1 = (char *)registro1[NOMB], *nombre2 = (char *)registro2[NOMB];
    double *puntaje1 = (double *)registro1[PUNT],
            *puntaje2 = (double *)registro2[PUNT];
    
    int comparacion = strcmp(nombre1,nombre2);
    if(comparacion != 0)
        return comparacion;
    
    return *puntaje2 - *puntaje1;
    
    
}



void *leer_registro_heroe(void *heroe){
    
    void **nodo = new void*[2]{};
    nodo[0] = heroe;
}


void imprimir_registro_heroe(const void *dato, ofstream &arch){
    
    void **registro = (void **)dato;
    
    char *nombre = (char *)registro[NOMB], *rol = (char *)registro[ROL],
            *categoria = (char *)registro[CAT];
    int *cod = (int *)registro[COD];
    double *puntaje = (double *)registro[PUNT];
    
    arch << left << setw(20) << nombre << setw(10) << rol << setw(5) << 
            categoria << right << setw(6) << *puntaje << setw(5) << *cod << endl;
    
}


bool eliminar_registro(const void *datoAnt, void *dato){
    
    
    void **registroAnt = (void **)datoAnt;
    void **registro = (void **)dato;
    
    char *nombreAnt = (char *)registroAnt[NOMB];
    char *nombre = (char *)registro[NOMB];
    
    if(strcmp(nombreAnt, nombre) == 0){
        //Eliminamos todo el  registro dato;
        char *rol = (char *)registro[ROL], *categoria = (char *)registro[CAT];
        int *cod = (int *)registro[COD];
        double *puntaje = (double *)registro[PUNT];
        
        delete rol;
        delete nombre;
        delete categoria;
        delete cod;
        delete puntaje;
        delete registro;
        
        return true;
    }
    
    return false;
}