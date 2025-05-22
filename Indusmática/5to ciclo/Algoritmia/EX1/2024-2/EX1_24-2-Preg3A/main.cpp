/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 21 de mayo de 2025, 13:53
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "Elemento.h"
#include "funcionesLista.h"

using namespace std;

#define N 6

/*
 * 
 */

void imprimirRed(Lista *listas){
    
    for(int i = 0; i < N; i++){
        cout << "Computadora " << i + 1 << ": ";
        imprime(listas[i]);
    }
    cout << endl;
}

void agregarConexion(Lista *listas, int origen, int destino){
    insertarAlFinal(listas[origen - 1], destino - 1);
    cout << "Se conectó la computadora " << origen << " con la computadora "
            << destino << endl;
}

void eliminarConexion(Lista *listas, int origen, int destino){
    
    eliminaNodo(listas[origen - 1], destino - 1);
    cout << "Se desconecto la computadora " << origen << " con la compuatadora "
            << destino << endl;
    
}


bool encontrar(Lista *listas, int origen, int destino){
    
    Nodo *recorrido = listas[origen].cabeza;
    bool encontrado = false;
    
    for(int i = 0; i <listas[origen].longitud; i++){
        if(recorrido->elemento.numero == destino){
            encontrado = true;
            break;
        }
        encontrado = encontrar(listas, recorrido->elemento.numero, destino);
        if(encontrado)break;
        recorrido = recorrido->siguiente;
    }
    return encontrado;
    
}

void  hayEscaladaPrivilegios(Lista *listas, int origen, int destino){
   
    bool encontrado;
    cout << endl;
    cout << "VERIFICACION: de computadora " << origen << " a " << destino
            << endl;
    
    encontrado = encontrar(listas, origen - 1, destino - 1);
    
    if(encontrado)
        cout << "Resultado: Si hay escala de privilegios" << endl;
    else 
        cout << "Resultado: No hay escala de privilegios" << endl;
    
}

int main(int argc, char** argv) {
    
    int n;
    Lista listas[N];
    for(int i = 0; i < N; i++)
        construir(listas[i]);
    
    agregarConexion(listas, 1,2);
    agregarConexion(listas, 1,3);
    agregarConexion(listas, 2,4);
    agregarConexion(listas, 5,6);    
    imprimirRed(listas);
    hayEscaladaPrivilegios(listas, 1,6);
    
    agregarConexion(listas, 3,5);
    eliminarConexion(listas, 5,6);
    imprimirRed(listas);
    hayEscaladaPrivilegios(listas, 1,6);
    
    agregarConexion(listas, 4,6);
    imprimirRed(listas);
    hayEscaladaPrivilegios(listas, 1,6);
    return 0;
}

