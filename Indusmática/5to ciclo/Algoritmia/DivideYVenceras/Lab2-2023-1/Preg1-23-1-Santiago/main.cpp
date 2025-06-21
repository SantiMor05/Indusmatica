/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 20 de junio de 2025, 19:39
 */

#include <iostream>


using namespace std;


#define N 5
#define M 6

/*
 * 
 */

void cambiar(int *arr, int i, int k) {
    int aux = arr[i];
    arr[i] = arr[k];
    arr[k] = aux;

}

void merge(int ini, int medio, int fin, int *registros, int *instrucciones) {

    int n1 = medio - ini + 1;
    int n2 = fin - medio;

    int izq[n1 + 1], der[n2 + 1];
    int izq_ins[n1], der_ins[n2];

    for (int i = 0; i < n1; i++) {
        izq[i] = registros[ini + i];
        izq_ins[i] = instrucciones[ini + i];
    }

    izq[n1] = 9999999;

    for (int i = 0; i < n2; i++) {
        der[i] = registros[medio + i + 1];
        der_ins[i] = instrucciones[medio + i + 1];

    }
    der[n2] = 999999;


    int cont1 = 0, cont2 = 0, i = ini;

    while (cont1 < n1 or cont2 < n2) {
        if (izq[cont1] < der[cont2]) {
            registros[i] = izq[cont1];
            instrucciones[i] = izq_ins[cont1];
            cont1++;
        } else {
            registros[i] = der[cont2];
            instrucciones[i] = der_ins[cont2];
            cont2++;
        }
        i++;
    }
}

void mergeSort(int ini, int fin, int *registros, int *instrucciones) {

    if (ini >= fin)return;

    int medio = (ini + fin) / 2;
    mergeSort(ini, medio, registros, instrucciones);
    mergeSort(medio + 1, fin, registros, instrucciones);

    merge(ini, medio, fin, registros, instrucciones);

}

int encontrarVirus(int ini, int fin, int registro, int *registros, 
                int *instruccion){
    
    if(ini > fin)return 0;
    
    int medio = (ini + fin) / 2;
    int suma = 0;
    if(registros[medio] == registro){
        suma += instruccion[medio];
    }
    
    if(medio - 1 >= ini  and registros[medio - 1] == registro or 
            registros[medio] > registro){
        suma += encontrarVirus(ini, medio - 1, registro, registros, instruccion);
    }
    else if(medio + 1 <= fin and registros[medio + 1] == registro or
            registros[medio] < registro)
        suma += encontrarVirus(medio + 1, fin, registro, registros, instruccion);
    
    return suma;
    
}

int evaluar(int registro, int matriz_registro[][M],
        int matriz_lineas_instruccion[][M]) {


    for (int i = 0; i < N; i++)
        mergeSort(0, M - 1, matriz_registro[i], matriz_lineas_instruccion[i]);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << matriz_registro[i][j] << "-" << matriz_lineas_instruccion[i][j]
                << "   ";
        cout << endl;
    }
    
    int suma = 0;
    
    for(int i = 0; i < N; i++)
        suma += encontrarVirus(0, M -1, registro, matriz_registro[i], 
                matriz_lineas_instruccion[i]);
    return suma;
}

int main(int argc, char** argv) {

    int matriz_registro[N][M]{
        {-1, -2, -3, -4, -5, -6},
        {-7, -8, 1, -9, 2, -10},
        {-11, 1, 2, -12, -13, -14},
        {-15, -16, -17, 1, -18, -19},
        {-20, 1, 2, -21, -22, -23}
    };

    int matriz_lineas_instruccion[N][M]{
        {10, 5, 8, 9, 8, 1},
        {10, 5, 2, 8, 2, 3},
        {4, 2, 1, 4, 8, 1},
        {1, 2, 4, 3, 5, 3},
        {8, 3, 3, 8, 5, 3}
    };

    int registro = 1, coincidencias;

    coincidencias = evaluar(registro, matriz_registro, matriz_lineas_instruccion);
    cout << "Para el virus de registro " << registro << " se obtienen " << 
            coincidencias << " en total" << endl;
    return 0;
}

