/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 20 de junio de 2025, 04:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

/*
 * 
 */

int hallarSumaCentroPos(int *arr, int ini, int med, int fin, int &menorSuma, int &iniCen, int &finCen){
    int minSumaIzq = INT_MAX, minSumaDer = INT_MAX, suma = 0;
    for (int i = med; i >= ini; i--) {
        suma += arr[i];
        if(suma < minSumaIzq){
            minSumaIzq = suma;
            iniCen = i;
        }
    }
    suma = 0;
    for (int i = med + 1; i <= fin; i++) {
        suma += arr[i];
        if(suma < minSumaDer){
            minSumaDer = suma;
            finCen = i;
        }
    }
    menorSuma = minSumaIzq + minSumaDer;
}

int minNum2024(int k, int g){
    if(k < g)return k;
    return g;
}


void hallarAcuNegPos(int *arr, int ini, int fin, int &menorSuma, int &rangIni, int &rangFin){
    if(ini == fin){
        menorSuma = arr[ini];
        return;
    }
    int med = (ini + fin)/2;
    
    menorSuma = INT_MAX;
    int sumaIzq = 0, sumaDer = 0, sumCen = 0;
    int iniIzq = -1, finIzq = -1;
    hallarAcuNegPos(arr, ini, med, sumaIzq, iniIzq, finIzq);
    int iniDer = -1, finDer= -1;
    hallarAcuNegPos(arr, med + 1, fin, sumaDer, iniDer, finDer);
    int iniCen = -1, finCen = -1;
    hallarSumaCentroPos(arr, ini, med, fin, sumCen, iniCen, finCen);
    
    menorSuma = minNum2024(minNum2024(sumaIzq, sumaDer), sumCen);
    if(menorSuma == sumaIzq){//izq
        rangIni = iniIzq;
        rangFin = finIzq;
    }
    if(menorSuma == sumaDer){//der
        rangIni = iniDer;
        rangFin = finDer;
    }
    if(menorSuma == sumCen){//centro
        rangIni = iniCen;
        rangFin = finCen;
    }
}

int main(int argc, char** argv) {
    //int arr[] = {2, 5, -6, 2, 3, -1, -5, 6}; //-7
    //int arr[] = {2, -3, 4, -5, -7}; //-12
    //int arr[] = {-4, 5, 6, -4, 3, -1, -5, 6}; //-7
    //int arr[] = {-4, -5, -6, -4, 3, -1, -5, 6}; //-22 //1 2 3 4 5 6 7
    //int arr[] = {-4, -5, -6, -4, 3, -1, -5, -6}; //-28 //1 2 3 4 5 6 7 8 
    //int arr[] = {-4, -5, -6, -4, 3, -1, -5, 6, -1, -1, -1, -1}; //-22 //1 2 3 4 5 6 7
    int arr[] = {-4, -5, -6, -4, 3, -1, -5, 6, -1, -1, -1, -6}; //-7 //1 2 3 4 5 6 7 8 9 10 11 12
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "PREG 1 2024_1: " << endl;

    int rangIni = -1, rangFin = -1, menorSuma = 0;

    hallarAcuNegPos(arr, 0, n - 1, menorSuma, rangIni, rangFin);
    cout <<"Acumulacion negativa mas alta: " << menorSuma << endl;
    cout << "Paquetes: ";
    for (int i = rangIni + 1; i <= rangFin + 1; i++)cout<<i<<" ";
    cout << endl;

    return 0;
}

