/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 28 de abril de 2025, 22:43
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesLista.h"
#include "Lista.h"

using namespace std;

/*
 * 
 */


void cargarDatosLista(Lista &lista, const char *nombArch){
    
    ifstream arch(nombArch, ios::in);
    if(!arch){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    char preparacion, car;
    int disponibilidad, horaPunta;
    double distancia;
    Pedido pedido; 
    while(true){
        arch.getline(pedido.id, 5,',');
        if(arch.eof())break;
        arch >> preparacion;
        arch >> car >> disponibilidad >> car;
        arch >> distancia >> car >> horaPunta;
        if(preparacion == 'b') pedido.tiempoPreparacion = 10;
        else if(preparacion == 'm') pedido.tiempoPreparacion = 20;
        else pedido.tiempoPreparacion = 30;
        if(disponibilidad == 0) pedido.tiempoPreparacion += 5;
        pedido.tiempoEstimadoViaje = distancia / 45 * 60;
        if(horaPunta == 1) pedido.tiempoEstimadoViaje += 10;
        arch.get();
        insertarAlFinal(lista, pedido);
    }
    
}

void pasarAListas(Lista &lista, Lista *listas, int opcion){
    
    Pedido pedido;
    int tiempo, pos;
    struct Nodo *aux, *ini;
    while(!esListaVacia(lista)){
        //pedido = retornaCabeza(lista);
        tiempo = lista.cabeza->pedido.tiempoEstimadoViaje + 
                lista.cabeza->pedido.tiempoPreparacion;
        if(opcion == 1)
            pos = tiempo % 10;
        else
            pos = tiempo / 10;
        
        aux = obtenerUltimoNodo(listas[pos]);
        if(aux == nullptr){
            listas[pos].cabeza = lista.cabeza;
            lista.cabeza = lista.cabeza->siguiente;
            listas[pos].cabeza->siguiente = nullptr;
        }
            
        else{
            aux->siguiente = lista.cabeza;
            lista.cabeza = lista.cabeza->siguiente;
            aux->siguiente->siguiente = nullptr;
        }
    }
    aux = nullptr;
    for(int i = 0; i < 10; i++){
        if(!esListaVacia(listas[i])){
            if(aux == nullptr){
                ini = listas[i].cabeza;
                aux = listas[i].cabeza;
            }
                
            else
                aux->siguiente = listas[i].cabeza;
            aux = obtenerUltimoNodo(listas[i]);
            listas[i].cabeza = nullptr;
        }
    }
     
    lista.cabeza = ini;
}
void ordenarLista(Lista &lista){
    
   
    Lista aux;
    Lista listas[10];
    for(int i = 0; i < 10; i++)
        construir(listas[i]);
    //Primera pasada
    pasarAListas(lista, listas, 1);
    cout << "Despues de la primera ordenacion" << endl;
    imprime(lista);
    
    //Segunda pasada
    pasarAListas(lista, listas, 0);
    cout << "Despues de la segunda ordenacion" << endl;
    imprime(lista);
    
    for(int i = 0; i < 10; i++)
        destruir(listas[i]);
}

int main(int argc, char** argv) {
    
    Lista lista;
    
    construir(lista);
    
    cargarDatosLista(lista, "Datos.txt");
    
    imprime(lista);
    
    ordenarLista(lista);

    cout << "FINAL: " << endl;
    imprime(lista);
    return 0;
}

