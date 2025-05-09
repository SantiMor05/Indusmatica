/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: Usuario
 * 
 * Created on 8 de mayo de 2025, 18:20
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
using namespace std;
#include "BibliotecaGenerica.h"
enum LISTA {CABL,COLL,CABG,COLG,CABM,COLM};
enum REG {NUM,DES,NIV,MON};
enum NODO {DAT,SIG};

void crearLista(void *&lis, const char* nomArch){
    ifstream arch(nomArch,ios::in);
    if (not arch.is_open()){
        cout<<"ERROR: No se puede abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    construirLista(lis);
    void* registro, **lista = (void**)lis;
    while(true){
        registro = leer_registro(arch);
        if (arch.eof()) break;
        insertar_dato(registro,lista);
    }
    unirColasFinal(lista);
}

void insertar_dato(void *registro, void**lista){
    void* cabeza = buscar_familia(registro,lista);
    void** recorrido = (void**)cabeza;
    void** anterior = recorrido, **nuevoNodo = new void*[2];
    nuevoNodo[DAT] = registro;
    while(recorrido!=nullptr){
        if (comparaReg(registro,recorrido[DAT])<0){
            if (anterior==lista[CABL] or anterior==lista[CABG] or anterior==lista[CABM]){
                if (anterior==lista[CABL]){
                    nuevoNodo[SIG] = lista[CABL];
                    lista[CABL] = nuevoNodo;
                }else{
                    if (anterior==lista[CABG]){
                        nuevoNodo[SIG] = lista[CABG];
                        lista[CABG] = nuevoNodo;
                    }else{
                        nuevoNodo[SIG] = lista[CABM];
                        lista[CABM] = nuevoNodo;
                    }
                }
            }else{
                anterior[SIG] = nuevoNodo;
                nuevoNodo[SIG] = recorrido;
            }
            return;
        }else{
            anterior = recorrido;
            recorrido = (void**)recorrido[SIG];
        }
    }
    if (anterior==nullptr){ //llena el primer dato de cada familia (lista vacia)
        llenar_dato_extraordinario(registro,lista,1);
    }else{ // Ha llegado al final de su familia (se inserta al final)
        llenar_dato_extraordinario(registro,lista,0);
    }
}

void unirColasFinal(void *lis){
    void** lista = (void**)lis;
    void** colaLeve = (void**)lista[COLL], **cabGrave = (void**)lista[CABG];
    colaLeve[SIG] = cabGrave;
    void** colaGrave = (void**)lista[COLG], **cabMuyG = (void**)lista[CABM];
    colaGrave[SIG] = cabMuyG;
}


void llenar_dato_extraordinario(void* reg, void **lista, int opcion){
    void** registro = (void**)reg;
    char* nivelInfraccion = (char*)registro[NIV];
    void**nuevoNodo = new void*[2];
    void** cola;
    nuevoNodo[DAT] = registro;
    nuevoNodo[SIG] = nullptr;
    if (strcmp(nivelInfraccion,"Leve")==0){
        if (opcion) lista[CABL] = nuevoNodo; //si es lista vacia
        else{ //si va al final, conecta con la cabeza del siguiente
            nuevoNodo[SIG] = lista[CABG];
            cola = (void**) lista[COLL];
            cola[SIG] = nuevoNodo;
        }
        lista[COLL] = nuevoNodo;
    }
    else if (strcmp(nivelInfraccion,"Grave")==0){
        if (opcion){ // si es lista vacia
            lista[CABG] = nuevoNodo;
            if (!esListaVacia(lista[COLL])){
                cola = (void**) lista[COLL];
                cola[SIG] = nuevoNodo;
            }
        }else{ //si va al final, conecta con la cabeza del siguiente
            nuevoNodo[SIG] = lista[CABM];
            cola = (void**) lista[COLG];
            cola[SIG] = nuevoNodo;
        }
        lista[COLG] = nuevoNodo;
    }
    else if (strcmp(nivelInfraccion,"Muy Grave")==0){
        if (opcion){ // si es lista vacia
            lista[CABM] = nuevoNodo;
            if (!esListaVacia(lista[COLG])){
                cola = (void**) lista[COLG];
                cola[SIG] = nuevoNodo;
            }
        }else{
                cola = (void**) lista[COLM];
                cola[SIG] = nuevoNodo;
        }
        lista[COLM] = nuevoNodo;
    }
}

bool esListaVacia(void *lista){
    if (lista==nullptr) return true;
    return false;
}

int comparaReg(void *reg, void* dat){
    void** registro = (void**)reg, **dato = (void**)dat;
    int* numA = (int*)registro[NUM], *numB = (int*)dato[NUM];
    return *numA - *numB;
}

void* buscar_familia(void *reg, void** lista){
    void** registro = (void**)reg;
    char* nivelInfraccion = (char*)registro[NIV];
    if (strcmp(nivelInfraccion,"Leve")==0)
        return lista[CABL];
    else if (strcmp(nivelInfraccion,"Grave")==0)
        return lista[CABG];
    else if (strcmp(nivelInfraccion,"Muy Grave")==0)
        return lista[CABM];
}

void* leer_registro(ifstream &arch){
    void** registro;
    int *numero, num;
    char* descripcion, *nivelInfraccion;
    double* monto;
    arch>>num;
    if (arch.eof()) return nullptr;
    arch.get();
    numero = new int;
    *numero = num;
    descripcion = leer_cadena(arch,',');
    nivelInfraccion = leer_cadena(arch,',');
    monto = new double;
    arch>>*monto;
    registro = new void*[4];
    registro[NUM] = numero;
    registro[DES] = descripcion;
    registro[NIV] = nivelInfraccion;
    registro[MON] = monto;
    return registro;
}

char * leer_cadena(ifstream &arch, char flag){
    char *cad, buffer[250];
    arch.getline(buffer,250,flag);
    cad = new char[strlen(buffer)+1]{};
    strcpy(cad,buffer);
    return cad;
}

void construirLista(void *&lis){
    void**lista = (void**)lis;
    lista = new void*[6];
    lista[CABL] = nullptr;
    lista[COLL] = nullptr;
    lista[CABG] = nullptr;
    lista[COLG] = nullptr;
    lista[CABM] = nullptr;
    lista[COLM] = nullptr;
    lis = lista;
}

void imprimeLista(void *lis,const char* nomArch){
    ofstream arch(nomArch,ios::out);
    if (not arch.is_open()){
        cout<<"ERROR: No se puede abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    void** lista = (void**)lis;
    void** recorrido = (void**)lista[CABL];
    while(recorrido!=nullptr){
        imprimir_registro(recorrido[DAT],arch);
        recorrido = (void**)recorrido[SIG];
    }
}

void imprimir_registro(void *reg, ofstream &arch){
    void**registro =  (void**)reg;
    int* numero = (int*)registro[NUM];
    char* descripcion = (char*)registro[DES], *nivel = (char*)registro[NIV];
    double* monto = (double*)registro[MON];
    arch<<*numero<<"   "<<"   "<<descripcion<<"   "<<nivel<<"    "<<*monto<<endl;
}