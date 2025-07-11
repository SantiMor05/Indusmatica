/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 8 de julio de 2025, 10:44
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Elemento.h"
/*
 * 
 */

Elemento encontrarInicial(Elemento *arr,int ini,int fin,int cantidad){
    if (ini>=fin) return arr[fin];
    int med = (ini+fin)/2;
    if (arr[med].cant == cantidad and arr[med-1].cant < cantidad) return arr[med];
    else{
        if (cantidad <= arr[med].cant) return encontrarInicial(arr,ini,med-1,cantidad);
        else return encontrarInicial(arr,med+1,fin,cantidad);
    }
}

Elemento encontrarFinal(Elemento *arr,int ini,int fin,int cantidad){
    if (ini>=fin) return arr[fin];
    int med = (ini+fin)/2;
    if (arr[med].cant == cantidad and arr[med+1].cant < cantidad) return arr[med];
    else{
        if (cantidad < arr[med].cant) return encontrarFinal(arr,ini,med-1,cantidad);
        else return encontrarFinal(arr,med+1,fin,cantidad);
    }
}

int main(int argc, char** argv) {
    
    Elemento arr[] = {15872,3,15865,4,15866,4,14357,6,14365,6,14368,6,14370,6,19258,8,19260,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Lote inicial: "<<encontrarInicial(arr,0,n-1,3).lote<<endl;
    cout<<"Lote final: "<<encontrarFinal(arr,0,n-1,3).lote<<endl;
    
    cout<<"Lote inicial: "<<encontrarInicial(arr,0,n-1,6).lote<<endl;
    cout<<"Lote final: "<<encontrarFinal(arr,0,n-1,6).lote<<endl;
    
    cout<<"Lote inicial: "<<encontrarInicial(arr,0,n-1,8).lote<<endl;
    cout<<"Lote final: "<<encontrarFinal(arr,0,n-1,8).lote<<endl;

    return 0;
}

