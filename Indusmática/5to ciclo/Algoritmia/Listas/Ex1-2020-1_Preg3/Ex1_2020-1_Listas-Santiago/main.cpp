/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 30 de abril de 2025, 21:54
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesLista.h"
#include "Elemento.h"

using namespace std;

/*
 * 
 */


int encontrarPos(char car){
    
    switch(car){
        case 'L':
            return 0;
            break;
        case 'M':
            return 1;
            break;
        case 'X':
            return 2;
            break;
        case 'J':
            return 3;
            break;
        case 'V':
            return 4;
            break;
    }
    
}

void leerDatos(Lista *listas, const char *nombArch){
    
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "Error: No se pudo abrir el archivo" << endl;
        exit(1);
    }
    int pos;
    Elemento elemento;
    while(true){
        while(arch.get() != '\n'){
            if(arch.eof())return;
            arch.unget();
            arch >> elemento.hora;
            if(arch.eof())return;
            arch >> elemento.dia;
            pos = encontrarPos(elemento.dia);
            insertarAlFinal(listas[pos], elemento);
        }
    }
    
}

void juntar(Lista &lista1, Lista &lista2){
    
    Nodo *aux = nullptr, *ini = nullptr;
    int pos1, pos2;
    if(lista1.cola->elemento.hora < lista2.cabeza->elemento.hora){
        lista1.cola->siguiente = lista2.cabeza;
        lista1.cola = lista2.cola;
        lista2.cabeza = lista2.cola = nullptr;
        lista2.longitud = 2;
    }
    else if(lista1.cabeza->elemento.hora > lista2.cola->elemento.hora){
        aux = lista1.cabeza;
        lista1.cabeza = lista2.cabeza;
        lista2.cola->siguiente = aux;
        lista2.cabeza = lista2.cola  = nullptr;
    }
    
    else{
        while(!esListaVacia(lista1) and !esListaVacia(lista2)){
            pos1 = encontrarPos(lista1.cabeza->elemento.dia);
            pos2 = encontrarPos(lista2.cabeza->elemento.dia);
            
            if(lista1.cabeza->elemento.hora < lista2.cabeza->elemento.hora
                    or (lista1.cabeza->elemento.hora == lista2.cabeza->elemento.hora
                    and pos1 < pos2)){
                if(ini == nullptr){
                    ini = lista1.cabeza;
                    aux = lista1.cabeza;
                }
                else{
                    aux->siguiente = lista1.cabeza;
                    aux = lista1.cabeza;
                }  
                lista1.cabeza = lista1.cabeza->siguiente;
            }
            else {
                if(ini == nullptr){
                    ini = lista2.cabeza;
                    aux = lista2.cabeza;
                }
                else{
                    aux->siguiente = lista2.cabeza;
                    aux = lista2.cabeza;
                }  
                lista2.cabeza = lista2.cabeza->siguiente;
            }
            
        }
        if(esListaVacia(lista1)){
            aux->siguiente = lista2.cabeza;
            aux = lista2.cola;
        }
        else{
            aux->siguiente = lista1.cabeza;
            aux =lista1.cola;
        }
        lista1.cabeza = ini;
        lista1.cola = aux;
        lista2.cola = lista2.cabeza = nullptr;
        
    }
    
}

void fusionListas(Lista *listas){
    
    for(int i = 1; i < 5; i++){
        if(!esListaVacia(listas[0]) and !esListaVacia(listas[i]))
            juntar(listas[0], listas[i]); //Todo lo juntamos en el arreglo 0
    }
        
    
}

int main(int argc, char** argv) {
    
    Lista listas[5];
    
    for(int i = 0; i < 5; i++)
        construir(listas[i]);
    
    leerDatos(listas, "Datos.txt");
    for(int i = 0; i < 5; i++)
        imprime(listas[i]);

    fusionListas(listas);
    imprime(listas[0]);
    
    return 0;
}

