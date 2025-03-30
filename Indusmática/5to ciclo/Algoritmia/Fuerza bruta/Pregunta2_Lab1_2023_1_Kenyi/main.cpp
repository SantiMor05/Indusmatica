/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 30 de marzo de 2025, 11:33 AM
 */

#include <iostream>
#include <cmath>


using namespace std;

/*
 * 
 */
void cargarBin(int num, int base, int *cromo, int n) {
    int res, i = 0;
    for (int j = 0; j < n; j++)cromo[j] = 0;
    while (num > 0) {
        res = num % base;
        num /= base;
        cromo[i] = res;
        i++;
    }
}

int main(int argc, char** argv) {
    int n = 6, m = 5;
    int capacidad[2][10] = {
        {100, 90, 95, 85, 105},
        {90, 98, 75, 96, 93}
    };
    int robot[n] = {77, 82, 81, 90, 92, 75};
    int cromo[m];
    // 0:izquierda , 1:derecha . Solamente hay dos estados
    int opciones = (int) pow(2, m);
    int soluciones = 0;
    for (int i = 0; i < opciones; i++) {
        cargarBin(i, 2, cromo, m);
        //        for (int j = 0; j < m; j++)cout << cromo[j] << " ";
        //        cout << endl;
        bool cumple = true;
        for (int j = 0; j < m; j++) {
            int cap = capacidad[cromo[j]][j];
            for (int k = 0; k < n; k++) {
                if (cap < robot[k])cumple = false;
            }
        }
        if (cumple) {
            soluciones++;
            cout << "La solucion " << soluciones << " es: ";
            for (int y = 0; y < m; y++)
                if (cromo[y])cout << "Derecha ";
                else cout << "Izquierda ";
            cout << endl;
        }
    }
    if (soluciones == 0) {
        int robotaux[n]{};
        for (int i = 0; i < n; i++)robotaux[i] = robot[i];
        cout << "No se encontro solucion";
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (capacidad[0][j] < robotaux[k] and capacidad[1][j] < robotaux[k])
                    robotaux[k] = 0;
            }
        }
        cout << "Los robots que no cumple son los siguientes: " << endl;
        for (int i = 0; i < n; i++) {
            if (robotaux[i] == 0)cout << "El robot numero " << i + 1
                    << " con peso " << robot[i] << "kg" << endl;
        }
        for (int i = 0; i < opciones; i++) {
            cargarBin(i, 2, cromo, m);
            bool cumple = true;
            for (int j = 0; j < m; j++) {
                int cap = capacidad[cromo[j]][j];
                for (int k = 0; k < n; k++) {
                    if (cap < robotaux[k])cumple = false;
                }
            }
            if (cumple) {
                soluciones++;
                cout << "La solucion " << soluciones << " es: ";
                for (int y = 0; y < m; y++)
                    if (cromo[y])cout << "Derecha ";
                    else cout << "Izquierda ";
                cout << endl;
            }
        }
    }


    return 0;
}

