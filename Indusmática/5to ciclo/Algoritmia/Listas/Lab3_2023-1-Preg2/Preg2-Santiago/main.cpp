/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 30 de abril de 2025, 19:14
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


void leerDatos(Lista *listas, const char *nombArch){
    
    
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo" << endl;
        exit(1);
    }
    
    Elemento elemento;
    int n = 0;
    while(true){
        while(arch.get() != '\n'){
            if(arch.eof())return;
            arch.unget();
            arch >> elemento.categoria;
            if(arch.eof())return;
            arch >> elemento.impacto;
            insertarAlFinal(listas[n], elemento);
        }
        n++;
    }
    
}

bool listasVacias(Lista *listas){
    int cont = 0;
    for(int i = 0; i < 5; i++)
        if(esListaVacia(listas[i]))
            cont++;
    return cont == 4;
}

void fusionar(Lista &lista1, Lista &lista2){
    
    if(lista1.cola->elemento.impacto > lista2.cabeza->elemento.impacto){
        lista1.cola->siguiente = lista2.cabeza;
        lista1.cola = lista2.cola;
        lista2.cabeza = nullptr;
        lista2.longitud = 0;
        lista2.cola =  nullptr;
    }
    else{
        Nodo *ini = nullptr, *aux = nullptr;
        while(!esListaVacia(lista1) and !esListaVacia(lista2)){
            if(lista1.cabeza->elemento.impacto > lista2.cabeza->elemento.impacto or
                    (lista1.cabeza->elemento.impacto == lista2.cabeza->elemento.impacto
                    and lista1.cabeza->elemento.categoria < lista2.cabeza->elemento.categoria)){
                if(ini == nullptr){
                    ini = lista1.cabeza;
                    aux = lista1.cabeza;
                }
                else{
                    aux->siguiente = lista1.cabeza;
                    aux = lista1.cabeza;
                }
                lista1.cabeza =  lista1.cabeza->siguiente;
            }
            else if(lista1.cabeza->elemento.impacto < lista2.cabeza->elemento.impacto
                    or (lista1.cabeza->elemento.impacto == lista2.cabeza->elemento.impacto
                    and lista1.cabeza->elemento.categoria > lista2.cabeza->elemento.categoria)){
                if(ini == nullptr){
                    ini = lista2.cabeza;
                    aux = lista2.cabeza;
                    lista2.cabeza =  lista2.cabeza->siguiente;
                }
                else{
                    aux->siguiente = lista2.cabeza;
                    aux = lista2.cabeza;
                    lista2.cabeza =  lista2.cabeza->siguiente;;
                }
            }
            
        }
        
        if(esListaVacia(lista1)){
            aux->siguiente = lista2.cabeza;
            aux = lista2.cola;
            lista2.cabeza = nullptr;
            lista2.cola = nullptr;
        }
        else{
            aux->siguiente = lista1.cabeza;
            aux = lista1.cola;
        }
        lista1.cabeza = ini;
        lista1.cola = aux;
    }
    
    
}

int reorganizar(Lista *listas){
    
  
    int posMayor1 = 0, posMayor2 = 0;
    int mayor1 = 0, mayor2 = 0;
    while(!listasVacias(listas)){
        for(int i = 0; i < 5; i++){
            //Buscamos las cateegorias con maayor indices
            if(!esListaVacia(listas[i])){
                if(listas[i].cabeza->elemento.impacto >= mayor1){
                    posMayor1 = i;
                    mayor1 = listas[i].cabeza->elemento.impacto;
                }
                
                else if(listas[i].cabeza->elemento.impacto > mayor2){
                    posMayor2 = i;
                    mayor2 = listas[i].cabeza->elemento.impacto;
                }
                
            }
            
        } 
        fusionar(listas[posMayor1], listas[posMayor2]);
        posMayor2 = 0;
        mayor2 = 0;
        //imprime(listas[posMayor1]);
    }
    return posMayor1;
}

int main(int argc, char** argv) {
    
    struct Lista listas[5];
    for(int i = 0; i  < 5; i++)
        construir(listas[i]);
    
    leerDatos(listas, "Datos.txt");

    for(int i = 0; i < 5; i++)
        imprime(listas[i]);
    
    int posMayor1 = reorganizar(listas);
    
    imprime(listas[posMayor1]);
    
    
    return 0;
}

