/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 7 de abril de 2025, 17:46
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;


int EncontrarSoltero(int *arr,int ini,int fin){
    int pMedio = (ini+fin)/2;
    if (ini == fin) return arr[pMedio]; 
    if (arr[pMedio] != arr[pMedio-1] and arr[pMedio] != arr[pMedio+1]) return arr[pMedio];
    else if ((arr[pMedio]==arr[pMedio-1] and pMedio%2!=0) or (arr[pMedio]!=arr[pMedio-1] and pMedio%2==0)) 
        return EncontrarSoltero(arr,pMedio+1,fin);
    else return EncontrarSoltero(arr,ini,pMedio-1);
}

int contaCeros(int *arr,int ini,int fin){
    int pMedio = (ini+fin)/2, cont = 0;
    if (ini>fin) return 0;
    if (arr[pMedio]==0){
        cont  += fin - pMedio + 1;
        cont += contaCeros(arr,ini,pMedio-1);
    }else{
        cont += contaCeros(arr,pMedio+1,fin);
    }
    return cont;
}

int encuentraRotado(int *arr,int ini,int fin){
    if (ini>fin) return -1;
    int pMedio = (ini+fin)/2;
    if (arr[pMedio] > arr[pMedio+1]) return arr[pMedio+1];
    if (arr[pMedio] < arr[0]) return encuentraRotado(arr,ini,pMedio-1);
    else return encuentraRotado(arr,pMedio+1,fin);
}

int encuentraMayor(int *arr,int ini,int fin){
    int pMedio = (ini+fin)/2;
    if (ini>fin) return -1;
    if (arr[pMedio] > arr[pMedio+1] and arr[pMedio] > arr[pMedio-1]) return arr[pMedio];
    if (arr[pMedio] < arr[pMedio+1]) return encuentraMayor(arr,pMedio+1,fin);
    else return encuentraMayor(arr,ini,pMedio-1);
} 

void MyMerge(int *arr,int ini,int med,int fin){
    int A[med-ini+1], B[fin-med];
    for (int i = ini; i <= med; i++)
        A[i-ini] = arr[i];
    for (int i = med+1; i <= fin; i++)
        B[i-med-1] = arr[i];
    int p = 0, q = 0, j = ini;
    while(p<med-ini+1 and q<fin-med){
        if (A[p] < B[q]){
            arr[j++] = A[p++];
        }else{
            arr[j++] = B[q++];
        }
    }
    while(p<med-ini+1) 
        arr[j++] = A[p++];
    while(q<fin - med) 
        arr[j++] = B[q++];
}

void Mymergesort(int *arr,int ini,int fin){
    if (ini>=fin) return;
    int medio = (ini+fin)/2;
    Mymergesort(arr,ini,medio);
    Mymergesort(arr,medio+1,fin);
    MyMerge(arr,ini,medio,fin);
}

int sumaCentro(int *arr,int ini,int med, int fin){
    int suma = 0, sumaDerMax = -9999, sumaIzqMax = -9999;
    for (int i = med; i >=ini; i--) {
        suma += arr[i];
        if (suma > sumaIzqMax) sumaIzqMax = suma;
    }
    suma = 0;
    for (int i = med+1; i <=fin; i++) {
        suma += arr[i];
        if (suma > sumaDerMax) sumaDerMax = suma;
    }
    return sumaDerMax + sumaIzqMax;
}

int maximo(int a, int b){
    if (a>b) return a;
    return b;
}

int hallarSumMax(int *arr,int ini,int fin){
    if (ini>=fin) return arr[ini];
    int med = (ini+fin)/2, der, centro, izq; 
    izq = hallarSumMax(arr,ini,med);
    der = hallarSumMax(arr,med+1,fin);
    centro = sumaCentro(arr,ini,med,fin);
    return maximo(maximo(izq,der),centro);
}

int MergeContar(int *arr, int ini,int med,int fin){
    //paso inicial para formar arreglos auxilaires
    int A[med-ini+1], B[fin-med];
    for (int i = ini; i <= med; i++)
        A[i-ini] = arr[i];
    for (int i = med+1; i <= fin; i++)
        B[i-med-1] = arr[i];
    int p = 0, q = 0, j = ini, cont = 0;
    //Empieza el mergesort
    while(p<med-ini+1 and q<fin-med){
        if (A[p] < B[q]){
            arr[j++] = A[p++];
        }
        else{
            /*Como ingresa ordenado, si encuentro uno de A mayor que a uno de B, 
             hay inversión para ese elemento de B y los que le siguen en el arreglo de A*/
            cont += med-p+1;
            arr[j++] = B[q++];
        }
    }
    //Completo en caso sea impar la división
    while(p<med-ini+1){
        cont += fin - med;
        arr[j++] = A[p++];
    }
    while(q<fin-med){
        arr[j++] = B[q++];
    }
    return cont/2;
}

int contarInversiones(int *arr,int ini,int fin){
    if (ini>=fin) return 0;
    int cont = 0, med = (ini+fin)/2;
    cont += contarInversiones(arr,ini,med);
    cont += contarInversiones(arr,med+1,fin);
    cont += MergeContar(arr,ini,med,fin);
    return cont;
}

int main(int argc, char** argv) {
    int n = 11;
    int arrParejas[n] = {2,3,3,4,4,5,5,7,7,8,8};
    cout<<"Número soltero: "<<EncontrarSoltero(arrParejas,0,n-1)<<endl;
    
    int m = 9;
    int arr10s[m] = {1,1,1,0,0,0,0,0,0};
    cout<<"Cantidad de ceros: "<<contaCeros(arr10s,0,m-1)<<endl;
    
    int c = 7;
    int arrRot[c] = {6,7,1,2,3,4,5};
    cout<<"Elemento menor: "<<encuentraRotado(arrRot,0,c-1)<<endl;
    
    int z = 11;
    int arrPicos[z] = {8,10,20,80,900,699,450,300,3,2,1,0};
    cout<<"Elemento mayor: "<<encuentraMayor(arrPicos,0,z-1)<<endl;
    
    cout <<"MergeSort: ";
    Mymergesort(arrPicos,0,z-1);
    for (int i = 0; i < z; i++)
        cout<<arrPicos[i]<<"  ";
    cout<<endl; 
    
    int v = 8;
    int arrSuma[v] = {-2, -5, 6, -2,  -3, 1, 5, -6};
    cout<<"Suma máxima: "<<hallarSumMax(arrSuma,0,v-1)<<endl;
    
//    arrRot[c] = {6,7,1,2,3,4,5};
    cout<<"Cantidad de inversiones: "<<contarInversiones(arrRot,0,c-1)<<endl;
    return 0;
}


