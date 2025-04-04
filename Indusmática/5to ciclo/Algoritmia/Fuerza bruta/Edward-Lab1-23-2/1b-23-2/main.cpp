/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 4 de abril de 2025, 03:58 PM
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "funciones.h"

using namespace std;
#define N 4
#define M 10
/*
 * 
 */

int mov[][M]{
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};


void copiar(char*aux,char*letras){
    for (int i = 0; i < 3; i++) {
        aux[i]=letras[i];
    }

}


bool validar(char letra,char* opciones){
    for (int i = 0; i < 3; i++) {
        if(letra==opciones[i]){
            opciones[i]=0;
            return true;
        }
    }
    return false;
}

bool evaluarEnPupi(char pupi[][M],int x,int y,char *letrasDispo){
    int nx,ny,j;
    char aux[3];
    for (int i = 0; i < 4; i++) {
        copiar(aux,letrasDispo);
        nx=x+mov[i][0];
        ny=y+mov[i][1];
        for (j = 1; j < 3; j++) {
            if(not(nx>=0 and nx<N and ny>=0 and ny<M))break;
            if(not validar(pupi[nx][ny],aux))break;
            nx+=mov[i][0];
            ny+=mov[i][1];
        }
        if(j==3)return true;
    }
    return false;

}



int main(int argc, char** argv) {

    char pupi[N][M];
    
    ifstream arch("pupi.txt",ios::in);
    if(not arch.is_open()){
        cout<<"Error en "<<"pupi.txt";exit(1);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arch>>pupi[i][j];
            if(arch.eof())break;
        }
    }
//    cout<<pupi[3][8]<<endl;
    char letras[3]{'H','S','O'},aux[3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            copiar(aux,letras);
            if(validar(pupi[i][j],aux)){
                if(evaluarEnPupi(pupi,i,j,aux))
                    cout<<"Poscion: "<<i<<","<<j<<endl;
            }
        }

    }

    
    return 0;
}

