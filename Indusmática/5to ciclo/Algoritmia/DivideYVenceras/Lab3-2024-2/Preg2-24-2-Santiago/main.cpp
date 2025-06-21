/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 13 de junio de 2025, 23:35
 */

#include <iostream>
#include <iomanip>

#define N 10
using namespace std;

/*
 * 
 */


int encontrarMaximo(int *tablero, int ini, int fin) {
    if (ini > fin)return 0;

    int max = 0, medio = (ini + fin) / 2;

    if (medio - 1 >= ini and tablero[medio - 1] > tablero[medio] or 
            (medio + 1 <= fin and tablero[medio + 1] < tablero[medio])) {
        max = encontrarMaximo(tablero, ini, medio - 1);
    } else if ((medio + 1 <= fin and tablero[medio + 1] > tablero[medio]) or
            (medio - 1 >= ini and tablero[medio - 1] < tablero[medio]))
        max = encontrarMaximo(tablero, medio + 1, fin);
    //    else{
    //        if()
    //            
    //    }
    if (tablero[medio] > max)
        max = tablero[medio];
    return max;
}

int encontrarMaximo(int tablero[][N]) {
    int max = 0, valor;
    for (int i = 0; i < N; i++) {
        valor = encontrarMaximo(tablero[i], 0, N - 1);
        if (valor > max)
            max = valor;
    }

    return max;
}

void reiniciarArr(int *muestras, int &cant) {
    for (int i = 0; i < cant; i++)
        muestras[i] = 0;
    cant = 0;
}

int cuentaCeros(int *tablero, int ini, int fin) {
    if (ini > fin)return 0;
    int cant = 0, medio = (ini + fin) / 2;

    if (tablero[ini] == 0) {
        if (tablero[medio] == 0){
            cant = medio - ini + 1;
            cant += cuentaCeros(tablero, medio + 1, fin); 
        }
        else
            cant += cuentaCeros(tablero, ini, medio - 1);  
    }
    else if(tablero[fin] == 0){
        if (tablero[medio] == 0){
            cant = fin - medio + 1;
            cant += cuentaCeros(tablero, ini, medio - 1); 
        }
        else
            cant += cuentaCeros(tablero, medio + 1, fin); 
    }
    return cant;
}

void encontrarMaximaCant(int tablero[][N], int *muestras, int &cant, int &max) {
    int cantidad;
    for (int i = 0; i < N; i++) {
        cantidad = cuentaCeros(tablero[i], 0, N - 1);
        cantidad = N - cantidad;
        if (cantidad > max) {
            reiniciarArr(muestras, cant);
            muestras[cant] = i + 1;
            max = cantidad;
            cant++;
        } else if (cantidad == max) {
            muestras[cant] = i + 1;
            cant++;
        }
    }

}

int main(int argc, char** argv) {

    int tablero[N][N]{
        {0, 0, 0, 3, 3, 7, 5, 5, 1, 1},
        {8, 8, 10, 9, 9, 5, 4, 4, 2, 0},
        {3, 5, 8, 9, 7, 6, 4, 2, 0, 0},
        {9, 7, 7, 4, 4, 4, 2, 0, 0, 0},
        {0, 2, 2, 3, 3, 4, 4, 5, 3, 3},
        {0, 0, 0, 0, 0, 0, 2, 3, 4, 5},
        {1, 2, 2, 3, 3, 4, 3, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 5, 5, 7},
        {6, 5, 5, 2, 2, 1, 0, 0, 0, 0},
        {3, 2, 2, 0, 0, 0, 0, 0, 0, 0}
    };

    //No sale
    int maxima = encontrarMaximo(tablero);
    cout << maxima << endl;

    int muestras[N], cant = 0, max = 0;

    encontrarMaximaCant(tablero, muestras, cant, max);
    
    cout << "Las muestras con mayor cantidad de niveles con minerales son : ";
    
    for(int i = 0; i < cant; i++)
        cout << setw(4) << muestras[i];
    cout << endl << "Con " << max << " estratos de minerales" << endl;
    
    return 0;
}

