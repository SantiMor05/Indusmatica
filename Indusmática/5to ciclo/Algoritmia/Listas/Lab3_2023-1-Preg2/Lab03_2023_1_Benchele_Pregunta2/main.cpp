/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 14 de mayo de 2025, 05:35 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "funcionesLista.h"
#include "Lista.h"
using namespace std;

/*
 * 
 */

void leerDatos(const char*nombArch, struct Lista *listas){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo: "<<nombArch<<endl;
        exit(1);
    }
    
    struct Elemento elemento;
    //1 A 15 A 13 A 12 A 11
    char cat;
    int imp, linea;
    int numLista = 0;
    
    while (true) {
        arch>>linea;
        if(arch.eof())break;
        while (true) {
            arch>>cat>>imp;
            elemento.categoria = cat;
            elemento.impacto = imp;
            insertarAlFinal(listas[numLista], elemento);
            if(arch.get() == '\n')break;
        }
        numLista++;        
    }
}

bool condicion(Lista &l1, Lista &l2, int tipo){
    switch (tipo){
        case 1: //Condicion cola L1 > cabeza L2
            if(l1.cola->elemento.impacto > l2.cabeza->elemento.impacto or l1.cola->elemento.impacto == l2.cabeza->elemento.impacto
               and l1.cola->elemento.categoria < l2.cabeza->elemento.categoria){
                return true;
            }
            break;
        case 2: //Condicion cola L2 > cabeza L1
            if(l2.cola->elemento.impacto > l1.cabeza->elemento.impacto or l2.cola->elemento.impacto == l1.cabeza->elemento.impacto
               and l2.cola->elemento.categoria < l1.cabeza->elemento.categoria){
                return true;
            }
            break;
        case 3: //Condicion cabeza L1 > cabeza L2
            if(l1.cabeza->elemento.impacto > l2.cabeza->elemento.impacto or l2.cabeza->elemento.impacto == l1.cabeza->elemento.impacto
               and l1.cabeza->elemento.categoria < l2.cabeza->elemento.categoria){
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}

void fusionar(struct Lista &l1, struct Lista &l2){
    if(condicion(l1, l2, 1)){
        l1.cola->siguiente = l2.cabeza;
        l1.cola = l2.cola;
    }
    else{
        if(condicion(l1, l2, 2)){
            l2.cola->siguiente = l1.cabeza;
            l1.cabeza = l2.cabeza;
        }
        else{
            struct Nodo *ini = nullptr, *fin = nullptr;
            while (!esListaVacia(l1) and !esListaVacia(l2)) {
                if(condicion(l1, l2, 3)){
                    if(ini == nullptr){
                        ini = l1.cabeza;
                        fin = l1.cabeza;
                    }
                    else{
                        fin->siguiente = l1.cabeza;
                        fin = l1.cabeza;
                    }
                    l1.cabeza = l1.cabeza->siguiente;
                }
                else{
                    if(ini == nullptr){
                        ini = l2.cabeza;
                        fin = l2.cabeza;
                    }
                    else{
                        fin->siguiente = l2.cabeza;
                        fin = l2.cabeza;
                    }
                    l2.cabeza = l2.cabeza->siguiente;
                }
            }
            if(!esListaVacia(l1)){
                fin->siguiente = l1.cabeza;
                fin = l1.cola;
            }
            if(!esListaVacia(l2)){
                fin->siguiente = l2.cabeza;
                fin = l2.cola;
            }
            l1.cabeza = ini;
            l1.cola = fin;
        }
    }
}

void fusionarListas(struct Lista *listas){
    //Fusionar todas sobre la lista 1 (listas[0])
    for (int i = 0; i < 5; i++) {
        fusionar(listas[0], listas[i]);
    }
}
int main(int argc, char** argv) {
    struct Lista listas[5]{};
    
    for (int i = 0; i < 5; i++) {
        construir(listas[i]);
    }
    
    //Pregunta a
    //Cargar datos a las listas
    leerDatos("Datos.txt", listas);
    
    //Verificacion datos
    for (int i = 0; i < 5; i++) {
        cout<<"Lista "<<i + 1<<": ";
        imprime(listas[i]);
    }
    
    //Pregunta b
    //Fusionar listas
    fusionarListas(listas); //Sobre la primera lista (listas[0])
    
    //Pregunta c
    //Impresion lista fusionada
    cout<<"--------------------------"<<endl;
    cout<<"Lista reorganizada: "<<endl;
    imprime(listas[0]);
    
    return 0;
}

