/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Opciones.cpp
 * Author: Lenovo
 * 
 * Created on 20 de junio de 2025, 10:18 PM
 */
#include <iostream>
#include <iomanip>
#include <climits>
#include "Opciones.h"
using namespace std;

//Opcion 1
//Contando 3

int calEmpleCentro(int *arr, int ini, int med, int fin, int &empleado){
    int cantIzq = 0, cantDer = 0;
    
    //Cantidad izquierda
    for (int i = med; i >= ini; i--) {
        if(arr[i] == arr[med])cantIzq++;
    }
    //Cantidad derecha
    for (int i = med + 1; i <= fin; i++) {
        if(arr[i] == arr[med])cantDer++;
    }
    
    empleado = arr[med];
    
    return cantDer + cantIzq + 1;
}
int maxEmple(int k, int g){
    if(k > g)return k;
    return g;
}

int hallarEmpleado(int *arr, int ini, int fin, int &empleado){
    if(ini == fin)return 0;
    
    int med = (ini + fin)/2;
    
    int empleIzq = -1;
    int izq = hallarEmpleado(arr, ini, med, empleIzq);
    int empleDer = -1;
    int der = hallarEmpleado(arr, med + 1, fin, empleDer);
    int empleCen = -1;
    int centro = calEmpleCentro(arr, ini, med, fin, empleCen);
    
    int maxE = maxEmple(maxEmple(izq, der), centro);

    if(maxE == izq){
        empleado = empleIzq;
    }
    if(maxE == der){
        empleado = empleDer;
    }
    if(maxE == centro){
        empleado = empleCen;
    }
    
    return maxE;
}



void opcion1(){
    int arr[] = {1, 6, 3, 4, 5, 6, 3, 7, 5, 4, 3, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int empleado = 0;
    cout << "OPCION 1" << endl;
    cout << "Cantidad veces: " << hallarEmpleado(arr, 0, n - 1, empleado) - 1;
    cout << endl << "El empleado que no salió fue " << empleado << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Opcion 2
//Ordenando y hallando el que tiene 3

void ordernarCentrEmple(int *arr, int ini, int med, int fin){
    int n1, n2, k = 0, g = 0;
    n1 = med - ini + 1; //Cantidad de elementos en la mitad izquierda, incluyendo med
    n2 = fin - med; //Cantidad de elementos en la mitad derecha, excluyendo med
    
    int K[n1 + 1];
    int G[n2 + 1];
    
    for (int i = ini; i <= med; i++)K[i - ini] = arr[i];
    for (int i = med + 1; i <= fin; i++)G[i - med - 1] = arr[i];
    
    K[n1] = INT_MAX;
    G[n2] = INT_MAX;
    
    for (int i = ini; i <= fin; i++) {
        if(K[k] < G[g]){
            arr[i] = K[k++];
        }
        else{
            arr[i] = G[g++];
        }
    }
}
void ordenarEmpleadosMErge(int *arr, int ini, int fin){
    if(ini == fin)return;
    
    int med = (ini + fin)/2;
    
    ordenarEmpleadosMErge(arr, ini, med);
    ordenarEmpleadosMErge(arr, med + 1, fin);
    ordernarCentrEmple(arr, ini, med, fin);
    
}

int encontrarTriple(int *arr, int ini, int fin){
    if(ini == fin)return arr[ini];
    
    int med = (ini + fin)/2;
    if(arr[med - 1] == arr[med] and arr[med] == arr[med + 1]){
        return arr[med];
    }

    if(med % 2 == 0){//Par
        if(arr[med] != arr[med + 1]){
            return encontrarTriple(arr, ini, med); //Si son diferentes, a la izquierda
        }
        else{
            return encontrarTriple(arr, med + 2, fin); //Si son iguales, a la derecha
        }
    }
    else{//Impar
        if(arr[med] != arr[med + 1]){ 
            return encontrarTriple(arr, med + 1, fin); //Si son diferentes, a la derecha
        }
        else{
            return encontrarTriple(arr, ini, med - 1); //Si son iguales, a la izquierda
        }
        
    }
}

void opcion2(){
    int arr[] = {1, 6, 3, 4, 5, 6, 3, 7, 5, 4, 3, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    ordenarEmpleadosMErge(arr, 0, n - 1);
    
    cout << "=================================" << endl;
    cout << "OPCION 2: " << endl;
    cout << "Empleados ordenados: " << endl;
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    cout << endl << "Empleado que nunca salió: " << encontrarTriple(arr, 0, n - 1) << endl;
}