/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include "funciones.h"

using namespace std;

char* copiarDinamico(const char*cad1){
    char *p;
    p=new char[strlen(cad1)+1];
    strcpy(p,cad1);
    return p;
}

void convertirCromo(int*cromo,int n,int num){
    
    int resto,i=0;
    for (int j = 0; j < n; j++) {
        cromo[j]=0;
    }
    while(num>0){
        resto=num%2;
        num/=2;
        cromo[i++]=resto;
    }

}
     
void convertirApalabra(char*formada,int &cantFormada,const int*cromo,
            const char*letras,int cantLetras){
    
//    como la palabra formada varia en tamaño, pero tiene un maximo de 10 letras
//    limpio todo el arreglo con 0s
    for (int j = 0; j < 10; j++) {
        formada[j]=0;
    }
    cantFormada=0;    
    for (int i = 0; i < cantLetras; i++) {
//        busco 1s en el cromosoma, si el cromosoma[n] es 1, debo añadir la letra[n]
//        voy creando la palabra añadiendo letras
        if(not cromo[i])continue;
        agregarAlFinal(formada,cantFormada,letras[i]);
        cantFormada++;
    }

}

void agregarAlFinal(char*formada,int cantFormada,char letra){
    
    int i=0;
    while(formada[i]) i++;
    
    formada[i++]=letra;
    formada[i]=0; 
    
}
     
void actualizarContadores(int*contadores,char**palabras,int cantPalabras,
        const char*formada,int cantFormada){
    
    bool cumple;
    for (int i = 0; i < cantPalabras; i++) {
//        si cumple es verdadero, significa que 
//        las letras de la palabra formada COINCIDEN con las de la palabra[i]
//        NO ME REFIERO A QUE LAS PALABRAS SEAN IGUALES, sino que las letras coinciden
        cumple=comparar(formada,cantFormada,palabras[i]);
        if(cumple){
            contadores[i]++;
            break;
        } 
    }
}

bool comparar(const char*formada,int cantFormada,const char*palabra){
    
//    LEYENDA:
//    palabra del arreglo de palabras inicial: Palabra
//    palabra abstraida del cromosoma: Formada
    
    int cantPalabra=strlen(palabra);
    
//    primero que todo, deben tener misma cantidad de letras
    if(cantFormada!=cantPalabra)return false;
    
//    cuando una letra de Palabra coincide con una letra de Formada, la letra de 
//    Palabra ya no debe ser considerada, porque sino otra letra de Formada puede coincidir con ella
//    letrasOcupadas es el arreglo que te dice que letras de Palabra ya han coincidido con una letra de Formada
    bool *letrasOcupadas=new bool[cantPalabra]{};
    
    for (int i = 0; formada[i]; i++) {
        for (int j = 0; palabra[j]; j++) {
            if(letrasOcupadas[j])continue;
            if(formada[i]==palabra[j]){
                letrasOcupadas[j]=true;
                break;
            }
        }
    }
    for (int i = 0; i < cantPalabra; i++) {
        if(not letrasOcupadas[i])return false;
    }
    return true;
}

