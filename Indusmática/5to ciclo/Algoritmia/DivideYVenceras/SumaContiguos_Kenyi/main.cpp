/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 17 de junio de 2025, 07:20 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

int max(int a, int b){
    if(a>b)return a;
    return b;
}

int calcularSumaCentro(int *arr,int ini,int medio,int fin){
    int suma=0,maxIzq=-9999,maxDer=-9999;
    for(int i=medio;i>=ini;i--){
        suma+=arr[i];
        if(suma>maxIzq) maxIzq=suma;
    }
    suma=0;
    for(int i=medio+1;i<=fin;i++){
        suma+=arr[i];
        if(suma>maxDer) maxDer=suma;
    }
    return maxDer+maxIzq;
}


int calcularSumaMay(int *arr,int ini,int fin){
    if(ini==fin) return arr[ini];
    
    int medio=(ini+fin)/2;
    
    int izq=calcularSumaMay(arr,ini,medio);
    int der=calcularSumaMay(arr,medio+1,fin);
    int centro=calcularSumaCentro(arr,ini,medio,fin);
    
    return max(centro,max(izq,der));
    
}

int main(int argc, char** argv) {
    int arr[]={-2, -5, 6, -2, -3, 1, 5, -6};
    int n=8;
    
    int suma=calcularSumaMay(arr,0,n-1);
    
    cout <<"La suma max es: "<<suma<<endl;
    
    return 0;
}

