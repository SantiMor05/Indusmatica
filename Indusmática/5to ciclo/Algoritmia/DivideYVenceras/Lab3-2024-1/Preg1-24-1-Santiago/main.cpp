/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 14 de junio de 2025, 18:39
 */

#include <iostream>

using namespace std;

/*
 * 
 */
//
//void merge(int *arr, int ini, int medio, int fin){
//    
//    int n1 = medio - ini + 1, n2 = fin - medio;
//    int izq[n1], der[n2];
//    
//    for(int i = 0; i < n1; i++)
//        izq[i] = arr[ini + i];
//    for(int i = 0; i < n2; i++)
//        der[i] = arr[medio + i + 1];
//    
//    int cont1 = 0, cont2 = 0, i = ini;
//    while(cont1 < n1 and cont2 < n2){
//        if(izq[cont1] < der[cont2]){
//            arr[i] = izq[cont1];
//            cont1++;
//        }
//        else{
//            arr[i] = der[cont2];
//            cont2++;
//        }
//        i++;
//    }
//    
//    for(; cont1 < n1; cont1++, i++)
//        arr[i] = izq[cont1];
//    for(;cont2 < n2; cont2++, i++)
//        arr[i] = der[cont2];
//    
//}
//
//void mergeSort(int *arr, int ini , int fin){
//    if(ini >= fin) return;
//    int medio = (ini + fin) / 2;
//    
//    mergeSort(arr, ini, medio);
//    mergeSort(arr, medio + 1, fin);
//    merge(arr, ini, medio, fin);
//}
//
//void encontrarNegativos(int * paquetes, int *negativos, int n, int &cant){
//    for(int i = 0; i < n; i++){
//        if(paquetes[i] < 0){
//            negativos[cant] = i;
//            cant++;
//        }
//            
//    }
//        
//}
//
//int calcularSuma(int *paquetes, int n){
//    int sumas[n];
//    for(int i = 0; i < n; i++){
//        if(i == 0)
//            sumas[i] = paquetes[i];
////        else if(i == 1){
////            sumas[i] = paquetes[0] + paquetes[1];
////        }
//        else
//            sumas[i] = sumas[i-1] + paquetes[i];
//        cout << sumas[i] << endl;
//    }
//    
//    //encontrarNegativos(paquetes, negativos, n, cant_negativos);
//    mergeSort(sumas, 0, n-1);
//    cout << endl;
//    for(int i = 0; i < n; i++)
//        cout << sumas[i] << endl;
//    
//    if(sumas[0]< 0){
//        if(-sumas[0] > sumas[n - 1])
//            return sumas[0];
//        else
//            return -sumas[n - 1];
//    }
//        
//    else
//        return -(sumas[n -1] - sumas[0]);
//    
//    
//}

int calcularCentro(int ini,int fin, int *paquetes){
    
    int min = 999999999, suma = 0;
    
    for(int i = ini; i <= fin; i++){
        suma += paquetes[i];
        if(suma < min) min = suma;
    }
    return min;
}

int min(int x,int y){
    if(x > y)
        return y;
    
    return x;
}


int calcularMinimo(int ini, int fin, int *paquetes){
    
    if(ini == fin) return paquetes[ini];
    int medio = (ini + fin) / 2;
    int izq = calcularMinimo(ini, medio,paquetes); 
    int der = calcularMinimo(medio + 1, fin,paquetes); 
    int centro = calcularCentro(ini,fin, paquetes);
    
    
    return min(der, min(izq,centro));
    
}


int main(int argc, char** argv) {
    
//    int paquetes[] ={2,5,-6,2,3,-1,-5, 6};
//    int n = 8;
    int paquetes[] ={2,-3,4,-5,-7};
    int n = 5;
//    int paquetes[] ={-4,5,6,-4,3,-1,-5,6};
//    int n = 8;
    
//    int paquetes[] = {-4};
//    int n = 1;
//    
//    int suma = calcularSuma(paquetes, n);
    
    int minimo = calcularMinimo(0, n - 1, paquetes);
    
    cout << "Acumulacion negativa mas alta: " << minimo << endl;
    return 0;
}

