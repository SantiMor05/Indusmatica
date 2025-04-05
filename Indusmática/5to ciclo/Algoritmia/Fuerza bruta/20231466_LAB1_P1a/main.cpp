/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Kenyi Chavez Ramos 20231466
 *
 * Created on 5 de abril de 2025, 9:15 a. m.
 */

#include <iostream>
#include <cmath>
#define T 6
#define D 3
using namespace std;

/*
 * 
 */

void cargarBin(int *cromo, int n, int num, int base) {
    int res, j = 0;
    for (int i = 0; i < n; i++)cromo[i] = 0;
    while (num > 0) {
        res = num % base;
        num /= base;
        cromo[j] = res;
        j++;
    }
}

int main(int argc, char** argv) {
    int velocidadesTablas[T] = {150, 100, 80, 50, 120, 10};
    int velocidadesDiscos[D] = {250, 200, 200};
    int cromo[T];
    int base = 4;
    int opciones = (int) pow(base, T), combinacion;
    int velocidadMax = 0,combinacionMax;
    for (int i = 0; i < opciones; i++) {
        cargarBin(cromo, T, i, base); // cargo el numero en la base 3 porque hay 3 discos
        //        for(int j=0;j<T;j++)cout<<cromo[j];
        //        cout<<endl;
        //        cromo[0]= 3;
        //        cromo[1]= 2;
        //        cromo[2]= 1;
        //        cromo[3]= 2;
        //        cromo[4]= 1;
        //        cromo[5]= 1;
        int velocidadesDiscosAux[D];
        for (int k = 0; k < D; k++)velocidadesDiscosAux[k] = velocidadesDiscos[k];
        bool valida = true;
        for (int j = 0; j < T; j++) { // entro a mi cromo 
            if (cromo[j] != 0) {
                velocidadesDiscosAux[cromo[j] - 1] -= velocidadesTablas[j];
            } else valida = false; // para que todos tengan un disco asignado
        }
        int velocidadMinObtenida = 999999;
        for (int y = 0; y < D; y++) {
            if (velocidadesDiscosAux[y] < 0) {
                valida = false; //verifico que ninguno sea menor que sero en el arreglo
            } else {
                if (velocidadMinObtenida > velocidadesDiscosAux[y]) {
                    velocidadMinObtenida = velocidadesDiscosAux[y];
                }
            }
        }
        if (valida) {
//            combinacion=i;
//            cargarBin(cromo, T, combinacion, base);
//            cout << "Solucion Optima:" << endl;
//            for (int j = 0; j < T; j++)cout << cromo[j];
//            cout << " Velocidad Minima " << velocidadMinObtenida << endl;
            if (velocidadMax < velocidadMinObtenida) {
                combinacionMax = i;
                velocidadMax = velocidadMinObtenida;
            }
            //            break;
        }
    }
    cargarBin(cromo, T, combinacionMax, base);
    cout << "Solucion Optima Mayor:" << endl;
    for (int j = 0; j < T; j++)cout << cromo[j]<<" ";
    cout << " Velocidad Minima " << velocidadMax <<" "<< endl;
    //    cout << "DISCOS        TABLAS" << endl;

    return 0;
}

