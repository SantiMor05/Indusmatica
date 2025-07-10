/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 8 de julio de 2025, 12:48
 */

#include <iostream>
#include <string>
using namespace std;
#include "Plato.h"
/*
 * 
 */

void intercambiar(Plato &p1, Plato &p2){
    Plato aux;
    aux = p1;
    p1 = p2;
    p2 = aux;
}

void Qsort(Plato *arr,int ini,int fin){
    if (ini>=fin) return;
    int pMedio = (ini+fin)/2, limite = ini;
    intercambiar(arr[ini], arr[pMedio]);
    for (int i = ini+1; i <= fin; i++) {
        if (arr[i].porcentajeReservas > arr[ini].porcentajeReservas)
            intercambiar(arr[i], arr[++limite]);
    }
    intercambiar(arr[ini], arr[limite]);
    Qsort(arr,ini,limite-1);
    Qsort(arr,limite+1,fin);
}

int main(int argc, char** argv) {
    Plato arr [] = {"Lomo Saltado", 50, 30, 30.0/50*100,
                    "Ceviche", 40, 35, 35.0/40*100,
                    "Ají de Gallina", 30, 10, 10.0/30*100,
                    "Causa Limeña", 20, 20, 20.0/20*100,
                    "Arroz con Pollo", 60, 45, 45.0/60*100};
    int n = sizeof(arr)/sizeof(arr[0]);
    Qsort(arr,0,n-1);
    cout<<"Top 3 platos con mayor porcentaje de reserva:"<<endl<<endl;
    for (int i = 0; i < 3; i++) {
        cout << arr[i].nombre<<" - "<<arr[i].porcentajeReservas<<"%"<<endl;
    }

    return 0;
}

