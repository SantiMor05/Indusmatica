/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 4 de abril de 2025, 07:28 PM
 */

#include <iostream>
#include <cmath>
#include "funciones.h"

using namespace std;
#define M 4
#define N 5
/*
 * 
 */
int main(int argc, char** argv) {

    int capacidades[M]{25,50,100,100};
    int paquetes[N]{50,20,30,50,20};
    int difMenor,dif,base=5,combi,cromo[N],cromoWin[N];
    bool esPrimera=true;
//    cuidado al ini difMenor
    combi=(int)pow(base,N);
    for (int i = 0; i < combi; i++) {
        cargaBin(cromo,N,base,i);
        if(not verCamiones(cromo,N))continue;
        if(cumplePesos(cromo,N,paquetes,capacidades)){
            dif=hallarDif(cromo,N,paquetes,capacidades);
            if(esPrimera or dif<difMenor){
//                cout<<"hola"<<endl;
                esPrimera=false;
                difMenor=dif;
                copiarCromo(cromoWin,cromo,N);
            }
        }
    }
    imprimirWin(cromoWin,N,difMenor);

    
    
    
    return 0;
}

