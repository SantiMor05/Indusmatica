/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 30 de marzo de 2025, 09:52 AM
 */

#include <iostream>
#include <cmath>
using namespace std;

/*
 * EL ALGORITMO RESUELVE CUANDO SE LE DA LA GANA
 */

void cargarBin(int num, int *cromosoma, int n, int base) {
    int res, i = 0;
    for (int i = 0; i < n; i++)cromosoma[i] = 0;
    while (num > 0) {
        res = num % base;
        num /= base;
        cromosoma[i] = res;
        i++;
    }
}

int main(int argc, char** argv) {
    int n = 5, m = 4, min, max, diff, base = m + 1, combinacion;
    int cam[m] = {25, 50, 100, 100};
    int paq[n] = {50, 20, 30, 50, 20};
    int cromosoma[n]{};
    int opciones = (int) pow(base, n);
    // 1 1 3 2 3
    //    cout<<"Ingrese la cantidad de camiones: ";
    //    cin>>m;
    //    cout<<"Ingrese la capacidad de los caminiones:";
    //    for(int i=0;i<m;i++)cin>>cam[i];
    //    cout<<"Ingrese la cantidad de paquetes: ";
    //    cin>>n;
    //    cout<<"Ingrese peso de los paquetes:";
    //    for (int i = 0; i < m; i++)cin >> paq[i];

    for (int i = 0; i < opciones; i++) {
        cargarBin(i, cromosoma, n, base);
        min = 99999;
        max = 0;
        //        for(int u=0;u<n;u++)cout<<cromosoma[u]<<" "; 
        //        cout<<endl;
        int camaux[n]{};
        bool esValido = true;
        for (int j = 0; j < m; j++)camaux[j] = cam[j]; //copiamos la capacidad del camion
        for (int k = 0; k < n; k++) {
            camaux[cromosoma[k] - 1] -= paq[k];
            if (cromosoma[k] == 0 or camaux[cromosoma[k] - 1] < 0) {
                esValido = false;
                break;
            }
        }
        for (int y = 0; y < m; y++) {
            if (camaux[y] < min)min = camaux[y];
            if (camaux[y] > max)max = camaux[y];
        }
        for (int o = 0; o < m; o++) {
            if (cam[o] - camaux[o] == 0)esValido = false;
        }
        if (esValido and diff > max - min and min >= 0) {//PONER '>=' PARA MOSTRAR TODAS LAS SOLUCINES REPETIDAS
            //            for (int u = 0; u < n; u++)cout << cromosoma[u] << " ";
            //            cout << "Diferencia Max: " << max << " " << min << endl;
            //si quieres mostrar todas las soluciones
            diff = max - min;
            combinacion = i;
        }
    }
    cargarBin(combinacion, cromosoma, n, base);
    cout << "La solucion es: ";
    for (int i = 0; i < n; i++)cout << cromosoma[i] << " ";
    cout << "Diferencia Max: " << diff;
    return 0;
}

