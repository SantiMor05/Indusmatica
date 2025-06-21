/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 20 de junio de 2025, 10:17 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <climits>
#define N 10
using namespace std;

/*
 * 
 */


int maximaPurezaFila(int *fila, int ini, int fin){
    if (ini == fin) return ini;

    int mid = (ini + fin) / 2;

    if (fila[mid] > fila[mid + 1]){
        return maximaPurezaFila(fila, ini, mid);
    }
    else{
        return maximaPurezaFila(fila, mid + 1, fin);
    }
}

int contarCero(int *arr, int ini, int fin, int cont){
    if(ini > fin)return cont;
    
    int med = (ini + fin)/2;
    
    if(arr[ini] == 0){ //Ceros a la izquierda
        if(arr[med] == 0){ //Tengo que ir a la erecha y sumarle todos los 0's de la izq
            return contarCero(arr, med + 1, fin, cont + med - ini + 1);
        }
        else{
            return contarCero(arr, ini, med - 1, cont);
        }
    }
    else{
        if(arr[fin] == 0){ //Ceros a las derecha
            if(arr[med] == 0){ //Tengo que ir a la izquierda y sumarle todos los 0's de la derecha
                return contarCero(arr, ini, med - 1, cont + fin - med + 1);
            }
            else{
                return contarCero(arr, med + 1, fin, cont);
            }
        }
    }
    return cont; //Si arr[ini] != 0 and arr[fin] != 0
                 //Se tiene que hacer esto por si la fila no tiene ceros o todos los ceros ya fueron contados.
}

void reiniciarCandidatos(int *candidatos, int &cantCand){
    for (int i = 0; i < cantCand; i++) {
        candidatos[i] = 0;
    }
    cantCand = 0;

}

int main(int argc, char** argv) {
    int matriz[10][10] = {{0, 0, 0, 3, 3, 7, 5, 5, 1, 1}, //7
                          {8, 8, 10, 9, 9, 5, 4, 4, 2, 0}, //9
                          {3, 5, 8, 9, 7, 6, 4, 2, 0, 0}, //8
                          {9, 7, 7, 4, 4, 4, 2, 0, 0, 0}, //7
                          {0, 2, 2, 3, 3, 4, 4, 5, 3, 3}, //9
                          {0, 0, 0, 0, 0, 0, 2, 3, 4, 5}, //4
                          {1, 2, 2, 3, 3, 4, 3, 2, 0, 0}, //8
                          {0, 0, 0, 0, 0, 0, 3, 5, 5, 7}, //4
                          {6, 5, 5, 2, 2, 1, 0, 0, 0, 0}, //6
                          {3, 2, 2, 0, 0, 0, 0, 0, 0, 0}}; //3
    int n = 10;
    
    //Pregunta a
    int maxPureza = -1;
    int muestraMax = -1;
    int estratoMax = -1;
    int pos;
    
    for (int i = 0; i < n; ++i) {
        pos = maximaPurezaFila(matriz[i], 0, n - 1);
        if (matriz[i][pos] > maxPureza) {
            maxPureza = matriz[i][pos];
            muestraMax = i + 1;
            estratoMax = pos + 1;
        }
    }
    cout << "La máxima pureza de las muestras es: " << maxPureza;
    cout << " (encontrado en la muestra " << muestraMax << ", en el estrato " << estratoMax << ")" << endl;
    
    //////////////////////////////////////////////////////////////////////////////
    //Pregunta b 
    /*Yo pense que tenia que hacer dos funciones para cuando es 0 a la izquierda o 0 a la derecha, pero la
      solucion actual de este item fue idea de Santiago xd*/
    
    int cantMax = INT_MIN, cantidad, cont = 0, candidatos[10]{}, cantCand = 0;
    for (int i = 0; i < n; i++) {
        cont = 0;
        cantidad = contarCero(matriz[i], 0, n - 1, cont);
        cantidad = n - cantidad; //La cantidad de minerales es igual al total - cantidad de 0's
        if(cantMax < cantidad){
            reiniciarCandidatos(candidatos, cantCand);
            candidatos[cantCand] = i + 1;
            cantMax = cantidad;
            cantCand++;
        }
        else{
            if(cantMax == cantidad){
                candidatos[cantCand] = i + 1;
                cantCand++;
            }
        }
    }
    
    cout << "Las muestras con mayor cantidad de niveles son: ";
    for (int i = 0; i < cantCand; i++) {
        cout << candidatos[i] << " ";
    }
    cout << " Con " << cantMax << " estratos de minerales" << endl;
    
    return 0;
}

