/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 4 de abril de 2025, 10:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#define N 8
#define P 100000
using namespace std;

void cargaBin(int*cromo,int n,int base,int num){
    int i=0,resto;
    for (int j = 0; j < n; j++) {
        cromo[j]=0;
    }
    while(num>0){
        resto=num%base;
        num/=base;
        cromo[i]=resto;
        i++;
    }
}

int main(int argc, char** argv) {
    int inversion[N] = {32000,8000,40000,40000,20000,4000,16000,16000};
    int beneficios[8] = {6000,32000,120000,60000,32000,20000,48000,60000};
    int cromo[N];
    int requisitos[N][3]{ {0,0,0},
                          {0,0,0},
                          {1,2,0},
                          {0,0,0},
                          {0,0,0},
                          {2,0,0},
                          {6,0,0},
                          {6,0,0}};
    int inversionTotal, sePuede, beneficiosTotal, maxBeneficio = 0, mejorComb;
    int opcion = (int) pow(2, N);
    for (int i = 0; i < opcion; i++) {
        inversionTotal = 0;
        beneficiosTotal = 0;
        sePuede = 1;
        cargaBin(cromo,N,2,i);
        for (int j = 0; j < N; j++) {
            if(cromo[j] == 1){
                sePuede = 1;
                for (int k = 0; k < 3; k++) {
                    if(requisitos[j][k] != 0){
                        if(cromo[requisitos[j][k] - 1] == 0){
                            sePuede = 0;
                        }
                    }
                }
                if(sePuede == 0){
                    break;
                }
                else{
                    inversionTotal += inversion[j];
                    beneficiosTotal += beneficios[j];
                }   
            }

        }
        if(inversionTotal == P and beneficiosTotal > maxBeneficio){
            maxBeneficio = beneficiosTotal;
            mejorComb = i;
            cout<<"Una solucion es: ";
            for (int d = 0; d < N; d++) {
                if(cromo[d])cout<<d+1<<" ";
                
            }
            cout<<"I: "<<inversionTotal<<"   B: "<<beneficiosTotal<<" ";
            cout<<endl;
        }


    }
    cargaBin(cromo, N, 2, mejorComb);
    cout<<"La solucion con mayor beneficio sería: "<<endl;
    for (int d = 0; d < N; d++) {
        if(cromo[d])cout<<d+1<<" ";   
    }
    cout<<"I: "<<inversionTotal<<"   B MAX: "<<maxBeneficio<<" ";
    cout<<endl;


    return 0;
}

