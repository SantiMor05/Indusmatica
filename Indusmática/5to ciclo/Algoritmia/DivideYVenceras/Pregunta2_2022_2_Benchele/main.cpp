/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 20 de junio de 2025, 05:10 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

/*
 * 
 */
int maxNum(int k, int g){
    if(k > g)return k;
    return g;
}
int buscarMayorPotencia(int arr[][7], int iniFil, int finFil, int iniCol, int finCol){
    if(iniFil == finFil and iniCol == finCol){
        return arr[iniFil][iniCol];
    }
    int medFil = (iniFil + finFil)/2;
    int medCol = (iniCol + finCol)/2;
    
    int supIzq = INT_MIN, supDer = INT_MIN, infIzq = INT_MIN, infDer = INT_MIN;
    
    supIzq = buscarMayorPotencia(arr, iniFil, medFil, iniCol, medCol);
    if(medCol + 1 <= finCol){
        supDer = buscarMayorPotencia(arr, iniFil, medFil, medCol + 1, finCol); 
    }
    if(medFil + 1 <= finFil){
        infIzq = buscarMayorPotencia(arr, medFil + 1, finFil, iniCol, medCol);
    }
    if(medFil + 1 <= finFil and medCol + 1 <= finCol){
        infDer = buscarMayorPotencia(arr, medFil + 1, finFil, medCol + 1, finCol);
    }
    return maxNum(maxNum(supDer, supIzq), maxNum(infDer, infIzq));
}

void buscarMaximoConPos(int arr[][7], int iniFil, int finFil, int iniCol, int finCol,
                        int &valorMax, int &filaMax, int &colMax) {
    if (iniFil == finFil && iniCol == finCol) {
        valorMax = arr[iniFil][iniCol];
        filaMax = iniFil;
        colMax = iniCol;
        return;
    }

    int medFil = (iniFil + finFil) / 2;
    int medCol = (iniCol + finCol) / 2;

    // Variables para cada subcuadro
    int v1 = INT_MIN, f1 = -1, c1 = -1;
    int v2 = INT_MIN, f2 = -1, c2 = -1;
    int v3 = INT_MIN, f3 = -1, c3 = -1;
    int v4 = INT_MIN, f4 = -1, c4 = -1;

    // SupIzq
    buscarMaximoConPos(arr, iniFil, medFil, iniCol, medCol, v1, f1, c1);

    // SupDer
    if (medCol + 1 <= finCol)
        buscarMaximoConPos(arr, iniFil, medFil, medCol + 1, finCol, v2, f2, c2);

    // InfIzq
    if (medFil + 1 <= finFil)
        buscarMaximoConPos(arr, medFil + 1, finFil, iniCol, medCol, v3, f3, c3);

    // InfDer
    if (medFil + 1 <= finFil && medCol + 1 <= finCol)
        buscarMaximoConPos(arr, medFil + 1, finFil, medCol + 1, finCol, v4, f4, c4);

    // Comparar los 4 máximos
    valorMax = v1; filaMax = f1; colMax = c1;

    if (v2 > valorMax) { valorMax = v2; filaMax = f2; colMax = c2; }
    if (v3 > valorMax) { valorMax = v3; filaMax = f3; colMax = c3; }
    if (v4 > valorMax) { valorMax = v4; filaMax = f4; colMax = c4; }
}


int main(int argc, char** argv) {
    int arr[10][7] = {{0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 1, 1, 1},
                      {0, 0, 0, 0, 1, 2, 2},
                      {0, 0, 0, 0, 1, 2, 3},
                      {0, 0, 0, 0, 1, 2, 2},
                      {0, 0, 0, 0, 1, 1, 1},
                      {0, 0, 0, 0, 0, 0, 0}};
//    int arr2[3][3] = {{1, 2, 3},
//                      {4, 9, 6},
//                      {7, 8, 5}};
//    int arr3[4][4] = {{7, 7, 7, 7},
//                      {7, 7, 7, 7},
//                      {7, 7, 7, 7},
//                      {7, 7, 7, 7}};
    
    int arr2[8][7] = {{0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0},
                     {0, 1, 1, 1, 0, 0, 0},
                     {0, 1, 2, 1, 0, 0, 0},
                     {0, 1, 1, 1, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0}};
    cout << endl;
    cout << "POtencia mas alta: " <<  buscarMayorPotencia(arr, 0, 9, 0, 6);
    int valorMax, filaMax, colMax;
    
    buscarMaximoConPos(arr2, 0, 8, 0, 6, valorMax, filaMax, colMax);
    cout << endl;

    cout << "Valor máximo: " << valorMax << " en (" << filaMax << ", " << colMax << ")\n";

    return 0;
}

