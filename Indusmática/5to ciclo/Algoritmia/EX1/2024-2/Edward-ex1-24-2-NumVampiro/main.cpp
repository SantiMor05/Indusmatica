/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 22 de mayo de 2025, 09:24 AM
 */

#include <iostream>
#include <cmath>
#include "funciones.h"

using namespace std;

int hallarCant(int num){
    
//    int cant=0;
//    while(num>0){
//        num/=10;
//        cant++;
//    }
//    return cant;
    return log10(num)+1;
}


void cargaBin(int*cromo,int n,int base,int num){
    
    for (int j = 0; j < n; j++) {
        cromo[j]=0;
    }
    int i=0;
    while(num>0){
        cromo[i]=num%base;
        num/=base;
        i++;
    }
}

bool cumple(int*cromo,int*arrNum,int n,int num){
    
    int num1=0,num2=0,aux;
    for (int i = 0; i < n; i++) {
        if(cromo[i]>=0 and cromo[i]<n/2){
            num1+=arrNum[i]*round(pow(10,cromo[i]));
        }
        else{
            aux=cromo[i]-(n/2);
            num2+=arrNum[i]*round(pow(10,aux));
        }
    }
    return num==num1*num2;
}

bool verificaVampiro(int num){
    
    int n=hallarCant(num);
    if(n%2!=0)return false;    
    int arrNum[n]{},cromo[n]{},aux=num;
    for (int i = 0; i < n; i++) {
        arrNum[i]=aux%10;
        aux/=10;
    }
    int base=n,combi;
    combi=(int)pow(base,n);
    for (int i = 0; i < combi; i++) {
        cargaBin(cromo,n,base,i);
        if(cumple(cromo,arrNum,n,num))return true;
    }
    return false;
}

int main(int argc, char** argv) {

    int num=1260;
    
    if(verificaVampiro(num))cout<<"Es vampiro"<<endl;
    else cout<<"No es vampiro"<<endl;
    
    return 0;
}

