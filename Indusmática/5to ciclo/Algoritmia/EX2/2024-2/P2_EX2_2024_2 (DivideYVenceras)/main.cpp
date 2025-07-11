/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kalef Mandujano
 *
 * Descripción del código
 * 
 * Created on 7 de julio de 2025, 08:10 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "string.h"


struct Plato{
    string nombre;
    int cantidadDisponible;
    int cantidadReservada;
    double porcentjaReservas;
};

void intercambiar(Plato &a,Plato &b){
    Plato aux;
    aux = a;
    a = b;
    b = aux;
}



void ordenamientoRapido(struct Plato *arr,int ini,int fin){
    if(ini >= fin) return;
    int med = (ini+fin)/2;
    
    intercambiar(arr[ini],arr[med]);
    int limite = ini;
    
    for (int i = ini+1; i <= fin; i++) {
        if(arr[ini].porcentjaReservas < arr[i].porcentjaReservas)
            intercambiar(arr[++limite],arr[i]);

    }
    intercambiar(arr[ini],arr[limite]);
    
    ordenamientoRapido(arr,ini,limite-1);
    ordenamientoRapido(arr,limite+1,fin);
    
}



int main(int argc, char** argv) {

    Plato plato1,plato2,plato3,plato4,plato5;

    plato1.nombre = "Lomo Saltado";
    plato1.cantidadDisponible = 50;
    plato1.cantidadReservada = 30;
    plato1.porcentjaReservas = double(plato1.cantidadReservada)*100/plato1.cantidadDisponible;
    
    
    plato2.nombre = "Ceviche";
    plato2.cantidadDisponible = 40;
    plato2.cantidadReservada = 35;
    plato2.porcentjaReservas = double(plato2.cantidadReservada)*100/plato2.cantidadDisponible;
    
    plato3.nombre = "Aji de Gallina";
    plato3.cantidadDisponible = 30;
    plato3.cantidadReservada = 10;
    plato3.porcentjaReservas = double(plato3.cantidadReservada)*100/plato3.cantidadDisponible;
    
    plato4.nombre = "Causa Limeña";
    plato4.cantidadDisponible = 20;
    plato4.cantidadReservada = 20;
    plato4.porcentjaReservas = double(plato4.cantidadReservada)*100/plato4.cantidadDisponible;
    
    plato5.nombre = "Arroz con Pollo";
    plato5.cantidadDisponible = 60;
    plato5.cantidadReservada = 45;
    plato5.porcentjaReservas = double(plato5.cantidadReservada)*100/plato5.cantidadDisponible;
    
    
    Plato arr[] = {plato1,plato2,plato3,plato4,plato5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    ordenamientoRapido(arr,0,n-1);
    
//    for (int i = 0; i < n; i++) {
//        cout<<arr[i].porcentjaReservas<<" ";
//
//    }
    //Imprimimos el top 3
    cout<<"Top 3 platos con mayor porcentaje de reservas"<<endl;
    cout<<arr[0].nombre<<" - "<<arr[0].porcentjaReservas<<"%"<<endl;
    cout<<arr[1].nombre<<" - "<<arr[1].porcentjaReservas<<"%"<<endl;
    cout<<arr[2].nombre<<" - "<<arr[2].porcentjaReservas<<"%"<<endl;


    
    
    
    
    
    return 0;
}

