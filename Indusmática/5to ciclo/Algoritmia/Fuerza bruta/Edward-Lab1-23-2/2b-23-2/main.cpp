/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 4 de abril de 2025, 05:16 PM
 */

#include <iostream>
#include <cmath>
#include "funciones.h"

using namespace std;
#define N 8
#define P 100000
/*
 * 
 */
int main(int argc, char** argv) {

    int cromo[8],base=2,combi,inversionTotal;
    int inversiones[8]{32000,8000,40000,40000,20000,4000,16000,16000};
    int beneficios[8]{6000,32000,120000,60000,32000,20000,48000,60000};
    int requi[N][3]{
        {},
        {},
        {1,2},
        {},
        {},
        {2},
        {6},
        {6},
    };
    int beneTot,beneMayor=0,cromoWin[N];
    combi=(int)pow(base,N);
    for (int i = 0; i < combi; i++) {
        cargaBin(cromo,N,base,i);
        if(validarRequi(cromo,N,requi)){
            inversionTotal=hallarInver(cromo,N,inversiones);
            if(inversionTotal==P){
                beneTot=hallarBene(cromo,N,beneficios);
                imprimir(cromo,N);
                cout<<"  El beneficio total es "<<beneTot<<endl;
                if(beneTot>=beneMayor){
                    beneMayor=beneTot;
                    copiarCromo(cromoWin,cromo,N);
                }
            }
        }
    }
    cout<<endl<<"La mejor solucion es: ";
    imprimir(cromoWin,N);
    cout<<"Con maximo beneficio de "<<beneMayor<<endl;
    
    return 0;
}

