
/* 
 * File:   arreglos_genericos.cpp
 * Author: Usuario
 * 
 * Created on 8 de mayo de 2025, 03:20 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "arreglos_genericos.h"
#define INCREMENTO 5

void llenar_arreglo_heroes(void *&arr, int &cant, const char* nomarch){
    ifstream arch(nomarch, ios::in);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nomarch << endl;
        exit(1);
    }
    void **arreglo = nullptr, *reg;
    int cap=0;
    cant = 0;
    while(true){
        reg = leerRegistro(arch);
        if(arch.eof())break;
        if(cant == cap) incrementarCap(arreglo, cant, cap);
        arreglo[cant] = reg;
        cant++;
    }
    arr = arreglo;
    
}

void incrementarCap(void **&arreglo,int cant,int &cap){
    void **aux;
    cap += INCREMENTO;
    if(arreglo == nullptr){
        arreglo = new void*[cap]{};
    } else{
        aux = new void*[cap]{};
        for (int i = 0; i < cant; i++) aux[i] = arreglo[i];
        delete arreglo;
        arreglo = aux;
    }
}

void * leerRegistro(ifstream &arch){
    void **quiteta;
    int *codigo, cod; 
    char *nombre, *rol, *categoria;
    double *puntaje, punt;
    arch >> cod;
    if(arch.eof()) return nullptr;;
    arch.get();
    nombre = leerExacto(arch, 30, ',');
    rol = leerExacto(arch, 10, ',');
    categoria = leerExacto(arch, 5, ',');
    arch >> punt;
    codigo = new int{cod};
    puntaje = new double{punt};
    quiteta = new void*[5];
    quiteta[0]=codigo;
    quiteta[1]=nombre;
    quiteta[2]=rol;
    quiteta[3]=categoria;
    quiteta[4]=puntaje;
    return quiteta;
}

char*leerExacto(ifstream &arch, int max, char del){
    char *cod, buff[max];
    arch.getline(buff, max, del);
    if(arch.eof()) return nullptr;
    cod = new char[strlen(buff)+1];
    strcpy(cod, buff);
    return cod;
}

int cmp_multicriteriovoid(const void*dato1, const void*dato2){
    void **datos1 = (void**)dato1, **datos2=(void**)dato2;
    void **reg1 = (void**)*datos1, **reg2 = (void**)*datos2;
    int *num1=(int*)reg1[0];
    char* nombre1 = (char*)reg1[1], *nombre2 = (char*)reg2[1];
    double *punt1 = (double*)reg1[4], *punt2 = (double*)reg2[4];
    if(strcmp(nombre1, nombre2)==0){
        return *punt2-*punt1;
    }else{
        return strcmp(nombre1, nombre2);
    }
 
}

void imprimirarr(const void *arr, const char*nomarch, int nd){
    ofstream arch(nomarch, ios::out);
    if(not arch.is_open()){
        cout << "ERROR: No se pudo abrir el archivo " << nomarch << endl;
        exit(1);
    }
    void **arreglo = (void**)arr, **quinteta;
    char*nombre, *rol, *cat;
    int*cod;
    double *punt;
    arch << fixed << setprecision(2);
    for (int i = 0; i < nd; i++) {
        quinteta = (void**) arreglo[i];
        cod = (int*) quinteta[0];
        nombre = (char*) quinteta[1];
        rol = (char*) quinteta[2];
        cat = (char*) quinteta[3];
        punt = (double*) quinteta[4];
        arch << left << setw(10) << *cod << setw(30) << nombre << setw(10) << rol
                << setw(10) << cat << *punt << endl;
    }

    
}

void *leer_heroes(void *arr){
    void **arreglo = (void**)arr;
    char * nombre = (char*)arreglo[1];
    
    return arreglo;
}

void imprimirLista(void *arr, ofstream &arch){
    void **arreglo = (void**)arr;
    int *cod = (int*)arreglo[0];
    char *nombre = (char*)arreglo[1];
    char *rol = (char*)arreglo[2];
    char *cat = (char*)arreglo[3];
    double *puntaje = (double*)arreglo[4];
    
    arch << left << setw(10) << *cod << setw(30) << nombre << setw(10) << rol
                << setw(10) << cat << *puntaje << endl;
}

int eliminar_registro(const void*dato1, const void* dato2 ){
    
    
    void **reg1 = (void**)dato1, **reg2 = (void**)dato2;
    char* nombre1 = (char*)reg1[1], *nombre2 = (char*)reg2[1];
    return strcmp(nombre1, nombre2);
}