/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 22 de mayo de 2025, 09:49
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Elemento.h"
#include "Nodo.h"
#include "Elemento.h"
#include "funcionesLista.h"
#include "Lista.h"

#define N 6

/*
 * 
 */

bool hayEscaladaPrivilegios(int madre,int hijo, Lista *arreglo){
    Elemento elemento;
    elemento.numero = hijo-1;
//    cout<<"VERIFICACIÓN: de computadora "<<madre<<" a "<<hijo<<endl;
    Nodo* recorrido = arreglo[madre-1].cabeza;
    while(recorrido!=nullptr){
        if (recorrido->elemento.numero == hijo-1) return true;
        else{
            if (hayEscaladaPrivilegios(recorrido->elemento.numero+1,hijo,arreglo))
                return true;
            else recorrido = recorrido->siguiente;
        }
    }
    return false;
}

void imprimirRed(Lista *arreglo){
    for (int i = 0; i < N; i++) {
        cout<<"Conexion "<<i+1<<": ";
        imprimir(arreglo[i]);
        cout<<endl;
    }
}

void eliminarConexion(int madre,int hijo, Lista *arreglo){
    Elemento elemento;
    elemento.numero = hijo - 1;
    eliminaNodo(arreglo[madre-1],elemento);
    cout<<"Se desconectó la computadora "<<madre<<" con la computadora "<<hijo<<endl;
}

void agregarConexion(int madre,int hijo, Lista *arreglo){
    Elemento elemento;
    elemento.numero = hijo-1;
    insertarAlFinal(arreglo[madre-1],elemento);
    cout<<"Se conectó la computadora "<<madre<<" con la computadora "<<hijo<<endl;
}

int main(int argc, char** argv) {
    int origen, destino;
    Lista arreglo[N]{};
    agregarConexion(1,2,arreglo);
    agregarConexion(1,3,arreglo);
    agregarConexion(2,4,arreglo);
    agregarConexion(5,6,arreglo);
    cout<<endl;
    imprimirRed(arreglo);
    cout<<endl;
    cout<<"Ingrese la computadora origen y destino a evaluar: ";
    cin>>origen>>destino;
    cout<<"VERIFICACIÓN: de computadora "<<origen<<" a "<<destino<<endl;
    if (hayEscaladaPrivilegios(1,6,arreglo))
        cout<<"Resultado: Si hay escalada de privilegios"<<endl;
    else cout<<"Resultado: No hay escalada de privilegios"<<endl;
    cout<<endl;
    agregarConexion(3,5,arreglo);
    eliminarConexion(5,6,arreglo);
    cout<<endl;
    imprimirRed(arreglo);
    cout<<endl;
    cout<<"Ingrese la computadora origen y destino a evaluar: ";
    cin>>origen>>destino;
    cout<<"VERIFICACIÓN: de computadora "<<origen<<" a "<<destino<<endl;
    if (hayEscaladaPrivilegios(1,6,arreglo))
        cout<<"Resultado: Si hay escalada de privilegios"<<endl;
    else cout<<"Resultado: No hay escalada de privilegios"<<endl;
    cout<<endl;
    agregarConexion(4,6,arreglo);
    imprimirRed(arreglo);
    cout<<"Ingrese la computadora origen y destino a evaluar: ";
    cin>>origen>>destino;
    cout<<"VERIFICACIÓN: de computadora "<<origen<<" a "<<destino<<endl;
    if (hayEscaladaPrivilegios(1,6,arreglo))
        cout<<"Resultado: Si hay escalada de privilegios"<<endl;
    else cout<<"Resultado: No hay escalada de privilegios"<<endl;
    
    return 0;
}

