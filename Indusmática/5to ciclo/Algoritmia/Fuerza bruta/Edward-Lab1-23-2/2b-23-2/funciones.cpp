/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <cmath>
#include "funciones.h"

using namespace std;

#define N 8
#define P 100000

void cargaBin(int*cromo,int n,int base,int num){
    int i=0,resto;
    for (int j = 0; j < n; j++) {
        cromo[j]=0;
    }
    while(num>0){
        resto=num%base;
        num/=base;
        cromo[i++]=resto;
    }
}

bool validarRequi(int*cromo,int n,int requi[][3]){

    for (int i = 0; i < n; i++) {
        if(cromo[i]){
            if(not cumpleRequi(cromo,n,i,requi[i]))return false;
        }
    }
    return true;
}

bool cumpleRequi(int *cromo,int n,int posi,int*requi){
    
    int cantRequi=0;
    for (int i = 0; requi[i]; i++) {
        cantRequi++;
    }
    if(not cantRequi)return true;
    
    int control,j;
    for (int i = 0; i<cantRequi; i++) {
        for (j = 0; j < n; j++) {
            if(cromo[j]){
                control=j+1;
                if(control==requi[i])break;
            }
        }
        if(j==n)return false;
    }
//    cout<<"se ha validado"<<endl;

    return true;
}
        
int hallarInver(int *cromo,int n,int*inversiones){
    
    int inversionTot=0;
    for (int i = 0; i < n; i++) {
        inversionTot+=cromo[i]*inversiones[i];
    }
    return inversionTot;
}

void imprimir(int*cromo,int n){
    
    cout<<"Una solucion es usar los controles: ";
    for (int i = 0; i < n; i++) {
        if(cromo[i])cout<<i+1<<" ";
    }
    cout<<endl;
}

int hallarBene(int*cromo,int n,int*beneficios){
    
    int beneTot=0;
    for (int i = 0; i < n; i++) {
        beneTot+=cromo[i]*beneficios[i];
    }
    return beneTot;
}

void copiarCromo(int*cromoWin,int*cromo,int n){
    
    for (int i = 0; i < n; i++) {
        cromoWin[i]=cromo[i];
    }

}