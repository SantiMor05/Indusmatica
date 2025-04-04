/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 3 de abril de 2025, 10:52 AM
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include "Guerrero.h"
#include "Mochila.h"
#include "Arma.h"
#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    struct Guerrero guerreros[3]{};
    struct Arma armas[12]{};
    struct Mochila mochilas[3]{};
    int cantGuerre=3,cantArmas=0,cantMochi=3;  
    bool esPosible;
    inizializar(guerreros,"armas.txt",armas,cantArmas);
    
    esPosible=evaluarGuerrero(guerreros,cantGuerre,armas,cantArmas,mochilas);
    if(esPosible){
//        cout<<"h ola"<<endl;
        for (int i = 0; i < cantGuerre; i++) {
            cout<<"Guerrero "<<i+1<<endl;
            cout<<"Poder: "<<guerreros[i].poder<<endl;
            cout<<"Armas en mochila para vencerlo: ";
            for (int j = 0; j < mochilas[i].cantArmas; j++) {
                cout<<mochilas[i].armas[j]<<" ";
            }
            cout<<endl;
        }

    }


    return 0;
}

