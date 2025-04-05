/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 29 de marzo de 2025, 20:05
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Array
    double matriz[][2] = {
        {1.0, 2.0},
        {3.0, 4.0},
        {5.0, 6.0},
        {7.0, 8.0}
    };
    double distancia, menorDistancia;
    int indexP1=0, indexP2=0;
    //Una forma en la q puedes sacar el numero de filas
    int rowsNum = sizeof (matriz) / sizeof (matriz[0]);

    if (rowsNum < 2) {
        cout << "Se requieren al menos dos puntos" << endl;
        return 1;
    }


    for (int i = 0; i < rowsNum - 1; i++) {
        for (int k = i + 1; k < rowsNum; k++) {
            distancia = pow(matriz[i][0] - matriz[k][0], 2) +
                    pow(matriz[i][1] - matriz[k][1], 2);
            if (k == 1) {
                menorDistancia = distancia;
                indexP1=i;
                indexP2=k;
            }
            // aqui se guardara la primera distancia minima que se encuentre
            if(distancia<menorDistancia){
                menorDistancia=distancia;
                indexP1=i;
                indexP2=k;
            }
        }
    }
    
    cout<<indexP1<<"   "<<indexP2;
    


    return 0;
}

