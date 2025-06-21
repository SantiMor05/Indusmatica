/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 13 de junio de 2025, 22:49
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */


void merge(int *arr,int ini,int medio,int fin){
    
    int n1 = medio - ini + 1, n2 = fin - medio;
    int izq[n1], der[n2];
    
    for(int i = 0; i < n1; i++){
        izq[i] = arr[i + ini];
    }
    for(int i = 0; i < n2; i++){
        der[i] = arr[i + medio + 1];
    }
    
    int cont1 = 0, cont2 = 0, i = ini;
    while(cont1 < n1 and cont2 < n2){
        if(izq[cont1] < der[cont2]){
            arr[i] = izq[cont1];
            cont1++;
        }
        else{
            arr[i] = der[cont2];
            cont2++;
        }
        i++;
    }
    
    for(;cont1 < n1; cont1++,i++)
        arr[i] = izq[cont1];
    for(;cont2 < n2;cont2++,i++)
        arr[i] = der[cont2];
}

void mergeSort(int *arr, int ini, int fin){
    if(ini >= fin)return;
    int medio =(ini + fin) / 2;
    
    mergeSort(arr, ini, medio);
    mergeSort(arr, medio + 1, fin);
    
    merge(arr,ini,medio,fin);
}

int busqueda(int *arr, int ini, int fin, int n){
    if(ini > fin)return 0;
    int medio = (ini + fin) / 2;
    int cont = 1;
    if(medio - 1 >= 0){
        if(arr[medio - 1] == arr[medio])
            cont++;
    }
    if(medio + 1 <= n){
        if(arr[medio + 1] == arr[medio])
            cont++;
    }
    
    if(cont == 3)return arr[medio];
    cont = busqueda(arr, ini, medio - 1, n);
    if(cont != 0)return cont;
    cont = busqueda(arr, medio + 1, fin,n);
    if(cont != 0)return cont;
}

int main(int argc, char** argv) {
    
    int bitacora[] = {1,6,3,4,5,6,3,7,5,4,3,1,7};
    int n = 13;
    
//    int bitacora[] = {1,1,2,2,2,3,3,4,4};
//    int n = 9;
    
    mergeSort(bitacora, 0, n - 1); 
    
    for(int i = 0; i < n; i++)
        cout << setw(3) << bitacora[i];
    cout << endl;
    int empleado = busqueda(bitacora, 0 , n-1, n - 1);
    
    cout << "El empleado es: " << empleado << endl;

    return 0;
}

