/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 7 de julio de 2025, 19:01
 */

#include <iostream>
#include <string>
using namespace std;

struct Plato {
    string nombre;
    int cantidadDisponible;
    int cantidadReservada;
    double porcentajeReservas;
};

void cambiar(Plato&pla1,Plato&pla2){
    
    Plato aux=pla1;
    pla1=pla2;
    pla2=aux;
}


//void quickSort(Plato*platos,int ini,int fin){
//    
//    if(ini>=fin)return;
//    
//    int pivot=ini;
//    for (int i = ini+1; i <=fin; i++) {
//        if(platos[i].porcentajeReservas>platos[ini].porcentajeReservas)
//            cambiar(platos[i],platos[++pivot]);
//    }
//    cambiar(platos[ini],platos[pivot]);
//    quickSort(platos,ini,pivot-1);
//    quickSort(platos,pivot+1,fin);
//}
void quickSort(Plato*platos,int ini,int fin){
    
    if(ini>=fin)return;
    
    int pivot=fin;
    for (int i = fin-1; i>=ini; i--) {
        if(platos[i].porcentajeReservas<platos[fin].porcentajeReservas)
            cambiar(platos[i],platos[--pivot]);
    }
    cambiar(platos[fin],platos[pivot]);
    quickSort(platos,ini,pivot-1);
    quickSort(platos,pivot+1,fin);
}


int main(int argc, char** argv) {

    Plato platos[]{
        {"Lomo Saltado", 50, 30},
        {"Ceviche", 40, 35},
        {"Aji de Gallina", 30, 10},
        {"Causa Limena", 20, 20},
        {"Arroz con Pollo", 60, 45}
    };
    int n=5;
    int total=0;

    for (int i = 0; i < n; i++) {
        platos[i].porcentajeReservas=
                (double)platos[i].cantidadReservada*100/
                platos[i].cantidadDisponible;                
    }
    quickSort(platos,0,n-1);

    cout<<"Top 3 platos con mayor porcentaje de reservas:"<<endl;
    for (int i = 0; i < 3; i++) {
        cout<<platos[i].nombre<<" - "<<platos[i].porcentajeReservas<<"%"<<
                endl;
    }

    
    return 0;
}

