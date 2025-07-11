/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 8 de julio de 2025, 22:09
 */

#include <iostream>

using namespace std;
#include "Plato.h"
/*
 * 
 */


void cambiar(Plato &plato1, Plato &plato2){
    Plato aux = plato1;
    plato1 = plato2;
    plato2 = aux;
}


bool operator > (Plato &plato1, Plato &plato2){
    
    return plato1.porcentajeReservas > plato2.porcentajeReservas;
    
}

void quickSortRecursivo(Plato *platos, int ini, int fin){
    
    if(ini >= fin)return;
    int medio = (ini + fin) / 2;
    cambiar(platos[ini], platos[medio]);
    int limite = ini;
    
    for(int i = ini + 1; i <= fin; i++){
        if(platos[i] > platos[ini]){
            cambiar(platos[++limite], platos[i]);
        }
    }
    cambiar(platos[limite], platos[ini]);
    quickSortRecursivo(platos,  ini, limite - 1);
    quickSortRecursivo(platos,  limite + 1, fin);
}


void quickSort(Plato *platos, int n){
    
    quickSortRecursivo(platos, 0, n - 1);
    
}


void calcularPorcentaje(Plato &aux){
    
    aux.porcentajeReservas = (double)aux.cantidadReservada / aux.cantidadDisponible;
    
}

int main(int argc, char** argv) {
    
    int n = 5;
    Plato platos[n]{}, aux;
    
    aux.nombre = "Lomo Saltado";
    aux.cantidadDisponible = 50;
    aux.cantidadReservada = 30;
    calcularPorcentaje(aux);
    platos[0] = aux;
    
    aux.nombre = "Ceviche";
    aux.cantidadDisponible = 40;
    aux.cantidadReservada = 35;
    calcularPorcentaje(aux);
    platos[1] = aux;
    
    aux.nombre = "Aji de Gallina";
    aux.cantidadDisponible = 30;
    aux.cantidadReservada = 10;
    calcularPorcentaje(aux);
    platos[2] = aux;
    
    aux.nombre = "Causa Limeña";
    aux.cantidadDisponible = 20;
    aux.cantidadReservada = 20;
    calcularPorcentaje(aux);
    platos[3] = aux;
    
    aux.nombre = "Arroz con Pollo";
    aux.cantidadDisponible = 60;
    aux.cantidadReservada = 45;
    calcularPorcentaje(aux);
    platos[4] = aux;
    
    quickSort(platos, n);
    cout << "TOP 3 platos con mayor porcentaje de reservas:" << endl;
    for(int i = 0; i < 3; i++){
        cout << platos[i].nombre << " - " << platos[i].porcentajeReservas * 100
                << "%"<< endl;
    }

    return 0;
}

