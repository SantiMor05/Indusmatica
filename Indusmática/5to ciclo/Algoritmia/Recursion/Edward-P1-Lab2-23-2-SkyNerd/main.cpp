/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 18 de abril de 2025, 08:53 PM
 */

#include <iostream>

using namespace std;
#define N 7

int matriz[][N]{
    {0,0,0,0,0,0,0},
    {10,0,20,30,0,20,40},
    {0,0,0,0,0,100,0},
    {0,0,0,0,0,80,0},
    {50,10,5,10,0,100,4},
    {100,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};

void buscar(int pos){
    
    if(pos==N){
        cout<<"SkyNerd no está en la red";
        return;
    }
    
    int esSky=1;
    if(matriz[pos][pos]!=0)esSky=0;
    if(not esSky)buscar(pos+1);
    if(esSky){
        for (int i = 0; i < N; i++) {
            if(i!=pos and matriz[pos][i]==0){
                esSky=false;
                break;
            }
        }
        if(not esSky)buscar(pos+1);
        if(esSky){
            for (int i = 0; i < N; i++) {
                if(i!=pos and matriz[i][pos]!=0){
                    esSky=false;
                    break;
                }
            }
            if(not esSky)buscar(pos+1);
            else{
                cout<<"SkyNerd ha sido detectado en el servidor: "<<pos+1;
                return;
            }
        }
    }

}


int main(int argc, char** argv) {
    
    int pos=0;
    buscar(pos);
    return 0;
}

