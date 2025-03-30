/* 
 * File:   main.cpp
 * Author: Farid Oswaldo
 *
 * Created on 30 de marzo de 2025, 12:24 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cmath>

/*
 * 
 */

void cargaBin(int num, int base, int *cromo, int n) {
    int rest, i = 0;
    for (int j = 0; j < n; j++) cromo[j] = 0; // inicializar en 0
    while (num > 0) {
        rest = num % base;
        num /= base;
        cromo[i] = rest;
        i++;
    }
}

int robPesado(int *robot, int n, int* estado) {
    int pesoMax = 0;
    for (int i = 0; i < n; i++) {
        if (robot[i] * estado[i] > pesoMax) pesoMax = robot[i];
    }
    return pesoMax;
}

void desactivarPesado(int *robot,int cantRob,int *estado,int pesoMax){
    for (int i = 0; i < cantRob; i++) {
        if(robot[i]==pesoMax){
            estado[i]=0;
            cout << "Se desactivaron al robot de " << robot[i] << endl;
        }
    }
}

void hallarEImorimirRutas(int *cromo, int *robot, int *estado, int puente[][10],
        int cantRob, int n) {
    bool esValido;
    int base = 2;
    int opcion = (int) pow(base, n), pesoMax, cantSol = 0;
    pesoMax = robPesado(robot, cantRob, estado);
    
    if(pesoMax==0){
        cout << "No se pudo hallar una ruta" << endl;
        return;
    }
    
    for (int i = 0; i < opcion; i++) {
        esValido = true;
        cargaBin(i, base, cromo, n);
        for (int j = 0; j < n; j++) {
            if (puente[cromo[j]][j] < pesoMax) {
                esValido = false;
                break;
            }
        }
        if (esValido) {
            cantSol++;
            cout << "Solucion " << cantSol << ':' << endl;
            for (int k = 0; k < n; k++) {

                cout << "Nivel " << k + 1 << ": ";
                if (cromo[k] == 0) {
                    cout << "Izquierda" << endl;
                } else cout << "Derecha" << endl;
            }
        }
    }
    if (cantSol == 0) {
        desactivarPesado(robot, cantRob, estado, pesoMax);
        hallarEImorimirRutas(cromo, robot, estado, puente, cantRob, n);
    }
}

int main(int argc, char** argv) {

    int cantRob = 6, cantNivelMax = 10, n = 5;
    int robot[6] = {77, 82, 81, 90, 92, 75};
    int estado[6] = {1, 1, 1, 1, 1, 1};
    int puente[2][10] = {
        {100, 90, 95, 85, 105},
        {90, 98, 75, 96, 93}
    };
    int cromo[n];
    hallarEImorimirRutas(cromo, robot, estado, puente, cantRob, n);
    //    bool esValido;
    //    int opcion = (int) pow(base, n), pesoMax, cantSol = 0;


    //    pesoMax = robPesado(robot, cantRob, estado);
    //    int base=2;
    //    for (int i = 0; i < opcion; i++) {
    //        esValido = true;
    //        cargaBin(i, base, cromo, n);
    //        for (int j = 0; j < n; j++) {
    //            if (puente[cromo[j]][j] < pesoMax) {
    //                esValido = false;
    //                break;
    //            }
    //        }
    //        if (esValido) {
    //            cantSol++;
    //            cout << "Solucion " << cantSol << ':' << endl;
    //            for (int k = 0; k < n; k++) {
    //
    //                cout << "Nivel " << k + 1 << ": ";
    //                if (cromo[k] == 0) {
    //                    cout << "Izquierda" << endl;
    //                } else cout << "Derecha" << endl;
    //            }
    //        }
    //    }


    return 0;
}

