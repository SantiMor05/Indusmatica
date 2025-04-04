/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 3 de abril de 2025, 04:43 PM
 */

#include <iostream>
#include <cmath>
#include "funciones.h"

using namespace std;
#define P 100
#define N 4
/*
 * 
 */
int main(int argc, char** argv) {

    int pesos[][N]{
        {20,20,20,20},
        {10,30,10,30},
        {10,10,10,10},
        {15,15,15,15}
    };
    int valores[][N]{
        {10,10,10,50},
        {80,10,10,20},
        {20,20,20,20},
        {50,50,50,50}
    };
    int valorMayor=0,pesoFinal;
    int pesoTotal,valorTotal;
    int combinaciones,base=2,cromo[N][N]{},cromoWin[N][N];
    combinaciones=(int)pow(base,N*N);
    for (int i = 0; i < combinaciones; i++) {
        cargaBin(cromo,N,base,i);
        pesoTotal=hallarPeso(cromo,N,pesos);
        if(pesoTotal<=P){
            valorTotal=hallarValor(cromo,N,valores);
            if(valorTotal>valorMayor){
                valorMayor=valorTotal;
                pesoFinal=pesoTotal;
                copiarCromo(cromoWin,cromo,N);
            }
        }
    }
    cout<<"Pesos (toneladas)"<<endl;
    imprimirResul(cromoWin,N,pesos);
    cout<<endl<<"Valores (Miles de $)"<<endl;
    imprimirResul(cromoWin,N,valores);
    cout<<"La mayor ganancia es "<<valorMayor<<endl;
    cout<<"El peso final es "<<pesoFinal<<endl;
    
    return 0;
}

