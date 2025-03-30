/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 30 de marzo de 2025, 11:16 AM
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    char letras[11]{},inputL,inputP[9];
    char* palabras[8]{};
    int cantLetras=0,cantPalabras=0;
    
//    pedir letras
    while(true){
        if(cantLetras==10){
            cout<<"Ya no puede ingresar mas letras"<<endl;
            break;
        }
        cout<<"Ingrese la letra numero "<<cantLetras+1<<" o ingrese # para "
                "terminar: ";
        cin>>inputL;
        if(inputL=='#')break;
        letras[cantLetras++]=inputL;
    }

//    pedir palabras
    while(true){
        if(cantPalabras==8){
            cout<<"Ya no puede ingresar mas palabras"<<endl;
            break;
        }
        cout<<"Ingrese la palabra numero "<<cantPalabras+1<<" o ingrese # para "
                "terminar: ";
        cin>>inputP;
        if(not strcmp(inputP,"#"))break;
        palabras[cantPalabras++]=copiarDinamico(inputP);
    }

    
    int posibilidades=(int)pow(2,cantLetras);
    int cromo[10],contadores[8]{},cantFormada;
    char formada[11];
    
    for (int i = 0; i < posibilidades; i++) {
        convertirCromo(cromo,cantLetras,i);
//        "formada" se refiere a la palabra que es representanda por el cromosoma
//        es decir, del cromosoma pasaré a una palabra
        convertirApalabra(formada,cantFormada,cromo,
                letras,cantLetras);
//        cada palabra tiene su contador de maneras de armar, voy a actualizarlos
        actualizarContadores(contadores,palabras,
                cantPalabras,formada,cantFormada);
    }
    for (int i = 0; i < cantPalabras; i++) {
        cout<<"La palabra "<<palabras[i]<<" se puede formar de "<<contadores[i]<<
                " maneras"<<endl;
    }

    
    return 0;
}

