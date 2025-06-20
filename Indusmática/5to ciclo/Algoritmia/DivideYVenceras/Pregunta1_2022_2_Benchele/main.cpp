/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 20 de junio de 2025, 04:58 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

/*
 * 
 */

int minNum(int k, int g){
    if(k < g)return k;
    return g;
}

int menorPeso(int *arr, int ini, int fin){
    if(ini == fin)return arr[ini];
    
    int med = (ini + fin)/2;
    
    int izq = menorPeso(arr, ini, med);
    int der = menorPeso(arr, med + 1, fin);

    return minNum(izq, der);
}
void hallarRangoCentro(int *arr, int ini, int med, int fin, int menorPes, int &iniCen, int &finCen){
    for (int i = med; i >= ini; i--) {
        if(arr[i] == menorPes)iniCen = i;
        else break;
    }

    for (int i = med + 1; i <= fin; i++) {
        if(arr[i] == menorPes)finCen = i;
        else break;
    }
}
int maxNum(int k, int g){
    if(k > g)return k;
    return g;
}
void buscarRango(int *arr, int ini, int fin, int menorPes, int &rangIni, int &rangFin){
    if(ini == fin){
        if(arr[ini] == menorPes){
            rangIni = ini;
            rangFin = ini;
        }
        return;
    }
    int med = (ini + fin)/2;
    
    int iniIzq = -1, finIzq = -1;
    buscarRango(arr, ini, med, menorPes, iniIzq, finIzq);
    
    int iniDer = -1, finDer = -1;
    buscarRango(arr, med + 1, fin, menorPes, iniDer, finDer);
    
    int iniCen = -1, finCen = -1;
    hallarRangoCentro(arr, ini, med, fin, menorPes, iniCen, finCen);

    int maxRango = INT_MIN;
    
    int ranIzq = (iniIzq != -1) ? (finIzq - iniIzq + 1) : 0; //SI es = -1 se hace la suma, si no es igual se hace 0
    int ranDer = (iniDer != -1) ? (finDer - iniDer + 1) : 0;
    int ranCen = (iniCen != -1) ? (finCen - iniCen + 1) : 0;
    
    maxRango = maxNum(maxNum(ranIzq, ranDer), ranCen);
    
    if(maxRango == ranIzq){
        //cout << "Izq: " << ranIzq << endl;
        rangIni = iniIzq;
        rangFin = finIzq;
    }
    if(maxRango == ranDer){
        //cout << "Der: " << ranDer << endl;
        rangIni = iniDer;
        rangFin = finDer;
    }
    if(maxRango == ranCen){
        //cout << "Cen: " << ranCen << endl;
        rangIni = iniCen;
        rangFin = finCen;
    }
}

int main(int argc, char** argv) {
      //int arr[] = {98, 88, 88, 90, 88, 92, 89, 89, 92, 90, 88, 88, 88, 88, 88, 95, 90, 89, 90, 91, 88, 88, 90, 90, 88, 88, 95, 88, 90, 91};
    int arr[] = {98, 95, 92, 89, 91, 92, 89, 89, 92, 93, 94, 92, 91, 90, 88, 88, 88, 89, 90, 91, 88, 88, 90, 90, 92, 89, 90, 88, 90, 91};

    int n = sizeof(arr)/sizeof(arr[0]);

    int menPe = menorPeso(arr, 0, n - 1); //Complejidad O(n) xd
    cout << "Menor peso: " << menPe << endl;
    int rangIni = 0, rangFin = 0;
    buscarRango(arr, 0, n - 1, menPe, rangIni, rangFin); //Complejidad nlog(n)
    cout << "El rango de dias que lo logró: ";//<< rangIni << " - " << rangFin;
    for (int i = rangIni + 1; i <= rangFin + 1; i++)cout << i << " ";
    
    return 0;
}

