/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include "Pila.h"
#include "Elemento.h"
#include "funcionesPila.h"
#include "funcionesLista.h"
using namespace std;
#define N 7
struct Elemento buscarCanditado(int * pilas,int n); 
/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-1
 */
int main(int argc, char** argv) {
    //N=14;
//    int pilas[N]= {1,7,2,7,3,4,3,2,1,7,2,1,7,3};
//    int pilas[N]= {2,5,7,7,1};
    int pilas[N]= {6,2,5,4,5,1,6};
    // int pilas[N]= {1,3,6,4};
    
    
    
    struct Elemento candidato;
    
    candidato = buscarCanditado(pilas,N); 
    
    //el apilando en la impresion repesenta el numero de pilas pequeñas de los
    //diferentes candidatos
    cout<< "Con posicion : "<<candidato.tipo<<" y numero de pilas pequeñas"
            " alrededor: "<<candidato.numero;
    return 0;
}


struct Elemento buscarCanditado(int * pilas,int n){
    struct Pila pila;
    struct Elemento candidato,maxCandidato;
    int contador=0,posCandi=0;
    int numCandidato= pilas[0];
    construir(pila);
    
    
    for (int i = 0; i < n; i++) {
        //Buscamos al candidato
        if(pilas[i]>numCandidato){
            numCandidato= pilas[i];
            posCandi=i;
            contador++;
        }else{
            // Puede pasar q tengas un 2 o mas candidatos pero solo cuando son
            // iguales por ejem cand1= 7 y candi2= 7
            if(pilas[i]== numCandidato and i!=0){
                //Cuando entra aqui significa que hay un nuevo canditado
                //por eso debemos guardar a nuestro anterior candidato en una pila
                candidato.tipo= posCandi;
                candidato.numero= contador;
                apilar(pila,candidato);
                
                //actualizamos los numeros del nuevo candidato
                contador= i-posCandi-1;
                posCandi=i;
                
            }else{
                // Sirve para contar las pilas pequeñas despues de encontrar a un candidato
                // --> 1 2 7 3 4 // Aqui el canditado seria 7 este if nos permitira 
                // contar al 3 y 4
                if(i!=0) contador++;
            }
        }
    }
    // El final del for habra un candidato que no hemos metido esto tmb pasa 
    // si solo hay un candidato
    candidato.tipo= posCandi;
    candidato.numero= contador;
    apilar(pila,candidato);

    //sacamos al candidato con mas pilas pequeñas alrededor
    
    maxCandidato= desapilar(pila);
    while (!esPilaVacia(pila)) {
        candidato= desapilar(pila);
        if(candidato.numero>maxCandidato.numero) maxCandidato= candidato;
    }

    destruirPila(pila);
    return maxCandidato;
    
}

