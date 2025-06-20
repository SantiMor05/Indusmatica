/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 15 de junio de 2025, 07:48 PM
 */

#include <iostream>
#include <climits>

using namespace std;

int max(int a,int b){
    
    if(a>b)return a;
    return b;
}

int buscarSuma(int*arr,int ini,int fin){
    
    if(ini==fin)return arr[fin];
    if(ini>fin)return INT_MIN;
    
    int med=(ini+fin)/2;
    int izq=buscarSuma(arr,ini,med-1);
    int dere=buscarSuma(arr,med+1,fin);
    
    int cenDere=0,cenIzq=0;
    int maxCenDere=0,maxCenIzq=0;
    for (int i = med+1; i<=fin; i++) {
        cenDere+=arr[i];
        if(maxCenDere<cenDere)maxCenDere=cenDere;
    }
    
    for (int i = med-1; i>=ini; i--) {
        cenIzq+=arr[i];
        if(maxCenIzq<cenIzq)maxCenIzq=cenIzq;
    }

    int centro=maxCenIzq+arr[med]+maxCenDere;
    return max(max(izq,dere),centro);
    

}

int main(int argc, char** argv) {

    int arr[]{-2, -5, 6, -2, -3, 1, 5, -6};
//    int arr[]{-2, -5, 6, 9, -3, -1, -5, -6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"La mayor suma es "<<buscarSuma(arr,0,n-1);
    
    return 0;
}

