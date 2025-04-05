/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <cmath>
#include "funciones.h"

using namespace std;
#define M 4
#define N 5

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

bool cumplePesos(int*cromo,int n,int*paquetes,int*capacidades){
    
    for (int i = 0; i < n; i++) {
        if(not fijarmeCamion(cromo,n,i+1,paquetes,capacidades))return false;
    }
    return true;
}

bool fijarmeCamion(int *cromo,int n,int camion,int*paquetes,int*capacidades){
    
    int pesoTot=0;
    for (int i = 0; i < n; i++) {
        if(cromo[i]==camion){
            pesoTot+=paquetes[i];
        }
    }
    if(pesoTot<=capacidades[camion-1])return true;
    return false;
}
                
int hallarDif(int*cromo,int n,int*paquetes,int*capacidades){
    
    int difMax,difMin,dif;
    bool esPrimera1=true,esPrimera2=true;
    for (int i = 0; i < M; i++) {
        dif=fijarmeDif(cromo,n,i+1,paquetes,capacidades);
        if(dif!=-1){
            if(esPrimera1 or dif>=difMax){
                esPrimera1=false,
                difMax=dif;
            }
            if(esPrimera2 or dif<=difMin){
                esPrimera2=false,
                difMin=dif;
            }
        }
    }
    return difMax-difMin;
}

int fijarmeDif(int *cromo,int n,int camion,int*paquetes,int*capacidades){
    
    int dif;
    int pesoTot=0;
    for (int i = 0; i < n; i++) {
        if(cromo[i]==camion){
            pesoTot+=paquetes[i];
        }
    }
    dif=capacidades[camion-1]-pesoTot;
    if(dif>=0)return dif;
    return -1;    
}
        
void copiarCromo(int*cromoWin,int*cromo,int n){
    
    for (int i = 0; i < n; i++) {
        cromoWin[i]=cromo[i];
    }
}

void imprimirWin(int*cromoWin,int n,int difMin){
    
    cout<<"La solucion optima es:"<<endl;
    for (int i = 0; i < n; i++) {
        if(cromoWin[i]){
            cout<<"Paquete "<<i+1<<" en camion "<<cromoWin[i]<<endl;
        }
    }
    cout<<"  La diferencia maxima es "<<difMin<<endl;

    
}
