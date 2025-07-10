/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kalef Mandujano
 *
 * Descripción del código
 * 
 * Created on 7 de julio de 2025, 11:56 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolB.h"
#include "funcionesAB.h"
#include "funcionesLista.h"
#include "Lista.h"
#include <cmath>

using namespace std;

void imprimeBinario(Lista aux){
    int cant = aux.longitud;
    int fact;
    Nodo *rec = aux.cabeza;
    int numBinario = 0, valor = 0;
    while(rec){
        //Formamos el numero binario y su respectivo valor
        fact = (int)round(pow(10,cant-1));
        numBinario += rec->elemento.numero*fact;
        valor += rec->elemento.numero*round((int)pow(2,cant-1));
        cant--;
        rec = rec->siguiente;
    }
    cout<<setw(6)<<numBinario<<" : "<<valor<<endl;
}

void imprimirPreOrden(NodoArbol *raiz,Lista aux, bool band){
    Elemento temp;
    if(raiz){
        if(band){
            insertarAlFinal(aux,raiz->elemento);
            if(raiz->elemento.numero != 0 and raiz->izquierda != nullptr or
                    (raiz->izquierda == nullptr and raiz->derecha == nullptr)){
                imprimeBinario(aux);
            }
        }
        band = true;
        imprimirPreOrden(raiz->izquierda,aux,band);
        imprimirPreOrden(raiz->derecha,aux,band);
        eliminaCola(aux);
    }
}



bool comprobarValor(Lista aux,int num){
    int cant = aux.longitud;
    int exp = cant-1;
    Nodo *rec;
    rec = aux.cabeza;
    int numParcial = 0;
    bool ingreso = false;
    for(int i = 0; i < cant; i++){
        numParcial += rec->elemento.numero * (int)pow(2,exp);
        rec = rec->siguiente;
        exp--;
        ingreso = true;
    }
    if(numParcial == num and ingreso) return true;
    return false;
    
    
}

void verificarNumero(NodoArbol *raiz,int num,Lista aux,bool &band, bool inicio){
    Elemento temp;
//    bool inicio = false;
    if(raiz){
        if(not inicio){
            temp = raiz->elemento;
            insertarAlFinal(aux,temp);
        }
        inicio = false;
        //Verificamos el llenado hasta ese punto
        if(!band){
            band = comprobarValor(aux,num);
            verificarNumero(raiz->izquierda,num,aux,band,inicio);
            verificarNumero(raiz->derecha,num,aux,band,inicio);
            eliminaCola(aux);
        }
        
    }
}


bool comprobarNumero(ArbolBinario arbolFinal,int num){
    bool band = false;
    Lista aux;
    construir(aux);
    bool inicio = true;
    verificarNumero(arbolFinal.raiz,num,aux,band,inicio);
    
    return band;
    
}


int main(int argc, char** argv) {
    ArbolBinario arbol1,arbol2,arbol3,arbol4,arbol5,arbol6,
            arbol7,arbol8,arbol9,arbol10,arbolFinal;
    
    construir(arbol1);
    construir(arbol2);
    construir(arbol3);
    construir(arbol4);
    construir(arbol5);
    construir(arbol6);
    construir(arbol7);
    construir(arbol8);
    construir(arbol9);
    construir(arbol10);
    construir(arbolFinal);
    
    Elemento aux;
    aux.numero = 0;
    
    plantarArbolBinario(arbol1,nullptr,aux,nullptr);
    
    aux.numero = 1;
    
    plantarArbolBinario(arbol2,nullptr,aux,arbol1.raiz);
    
    aux.numero = 1;
    
    plantarArbolBinario(arbol3,arbol2.raiz,aux,nullptr);
    
    aux.numero = 1;
    
    plantarArbolBinario(arbol4,nullptr,aux,nullptr);
    
    aux.numero = 0;
    
    plantarArbolBinario(arbol5,arbol4.raiz,aux,nullptr);
    
    aux.numero = 1;
    
    plantarArbolBinario(arbol6,nullptr,aux,nullptr);
    
    aux.numero = 0;
    
    plantarArbolBinario(arbol7,arbol6,aux,arbol5);
    
    aux.numero = 1;
    
    plantarArbolBinario(arbol8,arbol3,aux,arbol7);
    
    aux.numero = 0;
    
    plantarArbolBinario(arbol9,nullptr,aux,nullptr);
    
    aux.numero = 100;
    
    plantarArbolBinario(arbolFinal,arbol8,aux,arbol9);
    
    //Casos de prueba
    
    if(comprobarNumero(arbolFinal,0)){
        cout<<"El numero sí existe en el arbol"<<endl;
    }else{
        cout<<"El numero no existe en el arbol"<<endl;
    }
//    
//    if(comprobarNumero(arbolFinal,3)){
//        cout<<"El numero sí existe en el arbol"<<endl;
//    }else{
//        cout<<"El numero no existe en el arbol"<<endl;
//    }    
//    
//    if(comprobarNumero(arbolFinal,1)){
//        cout<<"El numero sí existe en el arbol"<<endl;
//    }else{
//        cout<<"El numero no existe en el arbol"<<endl;
//    }    
//    
//    if(comprobarNumero(arbolFinal,5)){
//        cout<<"El numero sí existe en el arbol"<<endl;
//    }else{
//        cout<<"El numero no existe en el arbol"<<endl;
//    }
//
//    if(comprobarNumero(arbolFinal,9)){
//        cout<<"El numero sí existe en el arbol"<<endl;
//    }else{
//        cout<<"El numero no existe en el arbol"<<endl;
//    } 
//    
//    if(comprobarNumero(arbolFinal,14)){
//        cout<<"El numero sí existe en el arbol"<<endl;
//    }else{
//        cout<<"El numero no existe en el arbol"<<endl;
//    }    
//    
//    if(comprobarNumero(arbolFinal,20)){
//        cout<<"El numero sí existe en el arbol"<<endl;
//    }else{
//        cout<<"El numero no existe en el arbol"<<endl;
//    }    
    
    Lista temp;
    construir(temp);
    bool band = false;
    imprimirPreOrden(arbolFinal.raiz,temp,band);
 
   

    
    
    
    


    return 0;
}

