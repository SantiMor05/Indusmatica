/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ListasGenericas.cpp
 * Author: Lenovo
 * 
 * Created on 8 de mayo de 2025, 07:43 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "FuncionesComunes.h"
#include "ListasGenericas.h"
#define NO_SON_IGUALES 2
using namespace std;

enum REG{COD, NOM, ROL, CAT, PUNT};
        
enum LISTA{CAB, COL};

enum NODO{DAT, SIG};

//Funciones lista

void construirLista(void *&lista){
    void **dupla = new void*[2]{};
    lista = dupla;
}

bool esListaVacia(void *lst){
    void **lista = (void **)lst;
    return lista[CAB] == nullptr;
}

int longitudLista(void *lst){
    void **lista = (void **)lst;
    void **rec = (void **)lista[CAB];
    int cant = 0;
    while (rec) {
        rec = (void **)rec[SIG];
        cant++;
    }
    return cant;
}

void *quitaPrimerNodo(void *lst){ //No se usa xd
    void **lista = (void **)lst;
    void **nodo = (void **)lista[CAB];
    lista[CAB] = nodo[SIG];
    void *dato = nodo[DAT];
    delete nodo;
    return dato;
}

//Aqui empieza
void crearListaHeroes(void *arrHeroes, void *&listaHeroes, void *(*leer)(void*)){
    void *reg;
    int i = 0;
    void**heroes = (void **)arrHeroes;
    construirLista(listaHeroes);
    while (heroes[i]) {
        reg = leer(heroes[i]);
        insertarAlFinal(reg, listaHeroes);
        i++;
    }    
}
void *leerRegHeroe(void *dato){
    return dato;
}

void insertarAlFinal(void *reg, void *&lista){
    void **primerNodo = (void **)lista;
    void **nuevoNodo = new void*[2]{};
    void **auxNodo;
    
    //LISTA{CAB, COL};NODO{DAT, SIG};
    nuevoNodo[DAT] = reg;
    if(esListaVacia(lista)){
        //Primer dato
        primerNodo[CAB] = nuevoNodo;
        primerNodo[COL] = nuevoNodo;
        lista = primerNodo;
    }
    else{
        auxNodo = (void **)primerNodo[COL];
        auxNodo[SIG] = nuevoNodo;
        primerNodo[COL] = nuevoNodo;
    }
    
}



void imrpimirListaHeroes(void *listaHeroes, void (*imprimir)(ofstream &arch, void *dato), 
                         const char*nombArch){
    ofstream arch(nombArch, ios::out);
    verificar_Apertura_O(arch, nombArch);
    arch<<fixed<<setprecision(2);
    
    void **lista = (void **)listaHeroes;
    void **rec = (void **)lista[CAB];
    
    arch<<"Nombre"<<setw(17)<<"Rol"<<setw(23)<<"Categoria"<<setw(12)<<"Puntaje"<<setw(12)<<"Codigo"<<endl;
    imprimirLinea(arch, '=');
    
    while (rec) {
        imprimir(arch, rec[DAT]);
        rec = (void **)rec[SIG];
    }
}

void imprimirRegHeroe(ofstream &arch, void *dato){
    void**heroe = (void **)dato;
    
    //REG{COD, NOM, ROL, CAT, PUNT};
    int *cod = (int *)heroe[COD];
    char *nomb = (char *)heroe[NOM],
         *rol = (char *)heroe[ROL],
         *cat = (char *)heroe[CAT];
   
    double *punta = (double *)heroe[PUNT];
    
    arch<<left<<setw(20)<<nomb<<setw(20)<<rol<<setw(4)<<cat<<right<<setw(13)<<*punta<<setw(11)<<*cod<<endl;
}

void eliminarHeroesRepetidos(void *listaHeroes, int (*eliminar)(const void*, const void*)){
    void **lista = (void **)listaHeroes;
    void **rec = (void **)lista[CAB], **sig = nullptr;
    
    int cmpElim;
    
    while (rec and rec[SIG]) {
        sig = (void**)rec[SIG];
        cmpElim = eliminar(rec[DAT], sig[DAT]);
        if(cmpElim == 0 or cmpElim == -1 or cmpElim == 1){
            if(0 <= cmpElim){
                rec[SIG] = sig[SIG];
            }
            else{
                //O esto
                //*rec = *sig;
                //O esto
                
                rec[SIG] = sig[SIG];
                rec[DAT] = sig[DAT];
            }
        }
        else{
            //Avanzar porque no son iguales los nombres
            rec = (void **)rec[SIG];
        }   
    }    
}

int eliminarRegistro(const void*a, const void*b){
    void **ai = (void **)a, **bi = (void **)b;
    char *nomA = (char *)ai[NOM],
         *nomB = (char *)bi[NOM];
    double *puntA = (double *)ai[PUNT],
           *puntB = (double *)bi[PUNT];
    
    if(strcmp(nomA, nomB) == 0){
        if (*puntA > *puntB) return 1; //Caso: actual > siguiente
        if (*puntA < *puntB) return -1; //Caso: actual < siguiente
        return 0; //Caso mismo nombre y mismo puntaje
    }
    return NO_SON_IGUALES;
}