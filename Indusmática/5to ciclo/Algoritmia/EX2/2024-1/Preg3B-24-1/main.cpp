/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 9 de julio de 2025, 13:25
 */

#include "Lista.h"
#include "funcionesLista.h"
#include <iostream>

using namespace std;

/*
 * 
 */

void eliminaKesimo(Lista &lista,int k){
    
    int multiplo = 1, numeroNodo = 1;
    Nodo *ant = lista.cola, *rec = lista.cabeza, *aux;
    
    while(lista.longitud > 1){
        if(numeroNodo == k * multiplo){
            aux = rec;
            rec = rec->siguiente;
            ant->siguiente = rec;
            delete aux;
            multiplo++;
            lista.longitud--;
        }
        else{
            ant = rec;
            rec = rec->siguiente;
        }
        numeroNodo++;
    }
    lista.cabeza = ant;
    lista.cola = ant;
}


int main(int argc, char** argv) {
    
    Lista lista;
    construir(lista);
    int cantEmpleados = 10, k = 7;
    for(int i = 1; i <= cantEmpleados; i++)
        insertarAlFinal(lista,i);
    
    //imprime(lista);
    
    eliminaKesimo(lista,k);
    cout << "En una lista de " << cantEmpleados << " empleados, para k = " <<
            k << ", el elegido es: ";
    imprime(lista);

    return 0;
}

