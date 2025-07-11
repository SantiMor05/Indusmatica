/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 27 de octubre de 2024, 16:56
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "funcionesPila.h"
#include "Elemento.h"
#include "Pila.h"
/*
 *  ARBOLES BINARIOS 2024-2
 *  Clase ABB
 */

void insertarR(NodoArbol *&raiz,int anho,int stock){
    if(raiz == nullptr){
        raiz = new class NodoArbol;
        raiz->elemento = anho;
        raiz->stock = stock;
        raiz->derecha = nullptr;
        raiz->izquierda = nullptr;
        return;
    }
    if(raiz->elemento > anho){
        //Insertamos derecha
        insertarR(raiz->izquierda,anho,stock);
    }else{
        //Insertamos izquierda
        insertarR(raiz->derecha,anho,stock);
    }
}

void buscarNodo(NodoArbol *raiz,int anho,NodoArbol *&rec){
    if(raiz){
        buscarNodo(raiz->izquierda,anho,rec);
        buscarNodo(raiz->derecha,anho,rec);
        if(raiz->elemento == anho) rec = raiz;
    }
}

void ingresa_lote(ArbolBinarioBusqueda arbol,int anho,int stock){
    NodoArbol *rec = nullptr;
    buscarNodo(arbol.arbolBinario.raiz,anho,rec);
    
    if(rec){
        //Tenemos lote para actualizar
        rec->stock += stock;
    }else{
        //Debemos crear un nuevo lote
        insertarR(arbol.arbolBinario.raiz,anho,stock);
    }
    
}

void impresionDatos(ArbolBinarioBusqueda arbol){
    Pila aux;
    Elemento temp;
    NodoArbol *rec;
    
    construir(aux);
    
    temp.numero = arbol.arbolBinario.raiz->elemento;
    temp.stock = arbol.arbolBinario.raiz->stock;
    apilar(aux,temp);
//    apilar(aux,arbol.arbolBinario.raiz->elemento);
    //Proceso de apilamiento
    while(!esPilaVacia(aux)){
        temp = desapilar(aux);
        buscarNodo(arbol.arbolBinario.raiz,temp.numero,rec);
        while(rec){
            temp.numero = rec->elemento;
            temp.stock = rec->stock;
            apilar(aux,temp);
            rec = rec->derecha;
        }
        while(!esPilaVacia(aux)){
            temp = desapilar(aux);
            cout<<setw(5)<<temp.numero<<" - "<<temp.stock<<" , ";
            buscarNodo(arbol.arbolBinario.raiz,temp.numero,rec);
            if(rec->izquierda){
                temp.numero = rec->izquierda->elemento;
                temp.stock = rec->izquierda->stock;
                apilar(aux,temp);
                break;
            }
        }
    }
    
    
    
}


int main(int argc, char** argv) {
    int anho, stock;
    struct ArbolBinarioBusqueda arbol;
    
//    construir(arbol);
//    
//    insertar(arbol, 100);
//    insertar(arbol, 50);
//    insertar(arbol, 150);
//    insertar(arbol, 125);
//    insertar(arbol, 175);
//    insertar(arbol, 200);
//    insertar(arbol, 25);
//    insertar(arbol, 75);
//    
//    enOrden(arbol);
//    
//    /*Función de búsqueda*/
//    cout << endl <<"Se encuentra el nodo 125 en el arból: " << buscar(arbol, 125)<< endl;
//    
//    eliminar(arbol, 25);
//    eliminar(arbol, 150);
//    eliminar(arbol, 100);
//    enOrden(arbol);
//    
    
    construir(arbol);
    
    anho = 2018;
    stock = 100;
    insertarR(arbol.arbolBinario.raiz,anho,stock);
    
    anho = 2011;
    stock = 150;
    insertarR(arbol.arbolBinario.raiz,anho,stock);
    
    anho = 2022;
    stock = 50;
    insertarR(arbol.arbolBinario.raiz,anho,stock);
    
    anho = 2010;
    stock = 175;
    insertarR(arbol.arbolBinario.raiz,anho,stock);
    
    anho = 2017;
    stock = 25;
    insertarR(arbol.arbolBinario.raiz,anho,stock);
    
    anho = 2019;
    stock = 125;
    insertarR(arbol.arbolBinario.raiz,anho,stock);
    
    anho = 2023;
    stock = 200;
    insertarR(arbol.arbolBinario.raiz,anho,stock);
    
    anho = 2020;
    stock = 75;
    insertarR(arbol.arbolBinario.raiz,anho,stock);
    
//    recorrerEnOrden(arbol.arbolBinario);
    cout<<endl;
    
    //Item a
//    ingresa_lote(arbol,2013,25);
    ingresa_lote(arbol,2018,100);
    
//    recorrerEnOrden(arbol.arbolBinario);
    
    //Itemb
    impresionDatos(arbol);
    
    
    return 0;
}
