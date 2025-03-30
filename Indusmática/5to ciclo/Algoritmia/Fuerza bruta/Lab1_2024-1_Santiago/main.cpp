/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 30 de marzo de 2025, 12:41
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Armas.h"
#include "Guerrero.h"

#define MAX_GUER 3
#define MAX_ARMAS 12

using namespace std;


void llenarDatos(struct Guerrero *guerreros, struct Arma *armas){
    
    ifstream arch("Datos.txt", ios::in);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    int cont;
    for(int i = 0; i < MAX_GUER; i++){
        cont = 0;
        arch >> guerreros[i].poder;
        while(arch.get() != '\n'){
            arch >> guerreros[i].TiposArmas[cont];
            cont++;
        }
        guerreros[i].narmas = cont;
    }
    
    for(int i = 0; i < MAX_ARMAS; i++){
        cont = 0;
        arch >> armas[i].codigo >> armas[i].poder >> armas[i].tipo;
        while(arch.get() != '\n'){
            arch >> armas[i].prerequisito[cont];
            cont++;
        }
        armas[i].nprerequisitos = cont;
    }
}

void cargabin(int num, int n, int *cromo, int base){
    
    for(int i = 0; i < n; i++)
        cromo[i] = 0;
    
    int resto, cont = 0;
    
    while(num > 0){
        resto = num % base;
        num /= base;
        cromo[cont] = resto;
        cont++;
    }
    
}

void copiarCromo(int *destino, int *fuente){
    
    for(int i = 0; i < MAX_ARMAS; i++)
        destino[i] = fuente[i];
    
}

void imprimirArmas(int *cromo, int numGuerrero, struct Arma *armas){
    
    for(int i = 0; i < MAX_ARMAS; i++)
        if(cromo[i] == numGuerrero)
            cout << armas[i].codigo << " ";
    cout << endl << endl << endl;
    
}

bool verficarTipo(int *TiposArmas, int codigo, int n){
    
    for(int i = 0; i < n; i++){
        if(codigo == TiposArmas[i])
            return true;
    }
    return false;
}

/*
 * 
 */
int main(int argc, char** argv) {

    struct Guerrero guerreros[MAX_GUER]{};
    struct Guerrero aux;
    struct Arma armas[MAX_ARMAS]{};  
    
    llenarDatos(guerreros, armas);
    //BASE 4
    int opciones = pow(4, MAX_ARMAS);
    int cromo[MAX_ARMAS]{};
    char prerequisito;
    //bool cumple;
    
    int poderAcumulado, podAcumAux; 
    int cumple, cromoAux[MAX_ARMAS];
    int soluciones = 0;
    bool satisface;
    
    for(int j = 1; j < opciones; j++){
        //Base 4, opciones : 0  1   2   3
        //0: No se usa      1: Guerrero 1
        //2: Guerrero 2     3: Guerrero 3
        cargabin(j, MAX_ARMAS, cromo, 4);
        satisface = true;
        int usados[MAX_ARMAS]{};
        //Recorremos cada guerrero verificando las armas
        for(int i = 0; i < MAX_GUER and satisface; i++){
            poderAcumulado = 0;
            aux = guerreros[i];
            
            //Recorremos el cromo buscando armas que dañen al guerrero i
            for(int c = 0; c < MAX_ARMAS and satisface; c++){
                if((cromo[c] == i + 1)){
                    //Si la arma no es del tipo que vence al guerrero se pasa de frente 
                    //a la proxima iteracion
                    if(not verficarTipo(aux.TiposArmas, 
                        armas[c].tipo, aux.narmas)){
                        satisface = false;
                        break;
                    }
                    if(armas[c].nprerequisitos == 0){
                        poderAcumulado += armas[c].poder;
                        usados[c] = i + 1;
                        cromo[c] = 0;
                    }
                    else{//Si tiene armas prerequisitos
                        podAcumAux = 0;
                        cumple = 0;
                        copiarCromo(cromoAux, cromo);
                        //Rastreamos si tenemos las armas que son prerquisitos
                        for(int p = 0; p < armas[c].nprerequisitos; p++){
                            prerequisito = armas[c].prerequisito[p];
                            //Buscamos en el cromo si tenemos el prerequisito asignado 
                            //para el guerrero i
                            for(int cr = 0; cr < MAX_ARMAS; cr++){
                                if(armas[cr].codigo == prerequisito and 
                                        (cromo[cr] == i + 1 or usados[cr] == i+1)){

                                    if(verficarTipo(aux.TiposArmas, armas[cr].tipo, aux.narmas)){
                                        podAcumAux += armas[c].poder;
                                        cromoAux [c] = 0;
                                        if(usados[cr] == 0){
                                            podAcumAux += armas[cr].poder;
                                            cromoAux [cr] = 0;
                                            usados[cr] = i + 1;
                                        }
                                        cumple++;
                                        break;
                                    }
                                    else
                                        satisface = false;

                                }
                            }
                        }

                        if(cumple == armas[c].nprerequisitos){
                            poderAcumulado += podAcumAux;
                            copiarCromo(cromo, cromoAux);
                        }
                    }
                }
            }
            
            if(poderAcumulado < aux.poder){
                satisface = false;
                break;
            } 
                
        }
         //cout << "Guerrero " << endl;
        
        if(satisface){
            cargabin(j, MAX_ARMAS, cromo, 4);
            soluciones++;
            cout << "Solucion " << soluciones << endl;
            cout << "-------------------------------------------" << endl; 
            for(int x = 0; x < MAX_GUER; x++){
                cout << "Guerrero " << x + 1 << endl;
                cout << "Poder: " << guerreros[x].poder << endl;
                cout << "Armas en la mochila para vencerlo: ";
                imprimirArmas(cromo, x + 1, armas);
            }
        }
    }
    
    
    
    return 0;
}

