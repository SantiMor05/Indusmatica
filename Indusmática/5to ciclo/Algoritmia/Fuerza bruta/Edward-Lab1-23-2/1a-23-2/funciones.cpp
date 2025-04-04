/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <cmath>
#include "funciones.h"

using namespace std;
#define P 100
#define N 4

void cargaBin(int cromo[][N],int n,int base,int num){
    int resto;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cromo[i][j]=0;
        }
    }
    int x=0,y=0;
    while(num>0){
        resto=num%base;
        num/=base;
        if(y==N){
            x++;
            y=0;
        }
        cromo[x][y]=resto;
        y++;
    }
}


int hallarPeso(int cromo[][4],int n,int pesos[][4]){
    int pesoTotal=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pesoTotal+=cromo[i][j]*pesos[i][j];
        }
    }
    return pesoTotal;

}
int hallarValor(int cromo[][4],int n,int valores[][4]){
    int valorTotal=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            valorTotal+=cromo[i][j]*valores[i][j];
        }
    }
    return valorTotal;
}
void copiarCromo(int cromoWin[][4],int cromo[][4],int n){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cromoWin[i][j]=cromo[i][j];
        }
    }
}
void imprimirResul(int cromo[][4],int n,int info[][4]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<cromo[i][j]*info[i][j]<<" ";
        }
        cout<<endl;
    }

}
