/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 8 de junio de 2025, 16:56
 */

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ArbolB.h"
#include "Elemento.h"
#include "funcionesAB.h"
#include "funcionesCola.h"
#include "Cola.h"
/*
 *  ARBOLES BINARIOS 2025-1
 *  Clase ABB
 */

void buscarNodo(NodoArbol *&raiz,Elemento &temp, NodoArbol *&rec){
    if(raiz){
//        if(raiz->elemento.numero == temp.numero and strcpy(raiz->elemento.titulo,temp.titulo) == 0)
//            return raiz;
        buscarNodo(raiz->izquierda,temp,rec);
        buscarNodo(raiz->derecha,temp,rec);
        if(raiz->elemento.numero == temp.numero)
            rec = raiz;
    }
}

//void hallarPrincipal(ArbolBinario arbol){
//    struct Cola cola;
//    NodoArbol *rec;
//    construir(cola);
//    Elemento temp;
//    
//    encolar(cola,arbol.raiz->elemento);
//    
//    int nivelMayor, relevanciaMayor = 0;
//    int cont = 0, i, cant;
//    while(!esColaVacia(cola)){
//        i = 0;
//        cant = cola.lista.longitud;
//        while(i<cant){
//            temp = desencolar(cola);
//            buscarNodo(arbol.raiz,temp,rec);
//            cout<<rec->elemento.titulo<<setw(8)<<rec->elemento.numero<<',';
//            if(temp.numero > relevanciaMayor){
//                relevanciaMayor = temp.numero;
//                nivelMayor = cont;
//            }
//            i++;
//            if(rec->izquierda) encolar(cola,rec->izquierda->elemento);
//            if(rec->derecha) encolar(cola,rec->derecha->elemento);
//        }
//        cout<<endl;
//        cont++;
//    }
//    cout<<"El nivel es: "<<nivelMayor<<endl;
//    
//    
//}

void contarSistema(NodoArbol *raiz,int &cantNodos,int &hojas){
    if(raiz){
        contarSistema(raiz->izquierda,cantNodos,hojas);
        contarSistema(raiz->derecha,cantNodos,hojas);
        cantNodos++;
        if(raiz->izquierda == nullptr and raiz->derecha == nullptr) hojas++;
    }
}

void insertarNodo(NodoArbol *&raiz,struct Elemento &dato){
    if(raiz == nullptr){
        raiz = new class NodoArbol;
        raiz->elemento = dato;
        raiz->derecha = nullptr;
        raiz->izquierda = nullptr;
        return;
    }
    if(raiz->elemento.numero > dato.numero){
        //Insertamos en la izquierda
        insertarNodo(raiz->izquierda,dato);
    }else{
        //Insertamos en la derecha
        insertarNodo(raiz->derecha,dato);
    }
    
}

ArbolBinario aplicar_arbol(ArbolBinario arbol_paquetes,ArbolBinario arbol_sistemas){
    struct Cola cola1, cola2;
    struct Elemento temp, dato, sist;
    NodoArbol *rec1, *rec2;
    
    construir(cola1);
    construir(cola2);
    
    encolar(cola1,arbol_paquetes.raiz->elemento);
    encolar(cola2,arbol_sistemas.raiz->elemento);
    
    ArbolBinario arbolFinal;
    
    construir(arbolFinal);
    
    int cantNodos, hojas;
    
    while(!esColaVacia(cola1)){
        temp = desencolar(cola1);
        sist = desencolar(cola2);
        
        buscarNodo(arbol_paquetes.raiz,temp,rec1);
        buscarNodo(arbol_sistemas.raiz,sist,rec2);
        
        if(rec1->izquierda) encolar(cola1,rec1->izquierda->elemento);
        if(rec1->derecha) encolar(cola1,rec1->derecha->elemento);
        
        if(rec2->izquierda) encolar(cola2,rec2->izquierda->elemento);
        if(rec2->derecha) encolar(cola2,rec2->derecha->elemento);
        
        cantNodos = 0; hojas = 0;
        
        contarSistema(rec2,cantNodos,hojas);
        
        //Armamos el arbol
        dato.numero = rec1->elemento.numero + cantNodos - hojas;
        
        insertarNodo(arbolFinal.raiz,dato);
        
        
    }
    
    
    return arbolFinal;
    
}

void calcularSuma(NodoArbol *raiz, int &suma){
    if(raiz){
        calcularSuma(raiz->izquierda, suma);
        calcularSuma(raiz->derecha,suma);
        suma += raiz->elemento.numero;
    }
}

void determinar_anomalia(ArbolBinario arbol){
    int suma = 0;
    
    calcularSuma(arbol.raiz,suma);
    
    if(suma % 2 == 0){
        cout<<"Sin eventos sospechosos"<<endl;
    }else{
        cout<<"Anomalia detectada"<<endl;
    }
}


int main(int argc, char** argv) {

    struct ArbolBinario arbol_paquetes, arbol_sistemas,
            arbol2, arbol3, arbol4, arbol5, arbol6, arbol7, arbol8,
                arbol9, arbol10, arbol;
    struct Elemento elemento;
//    struct ArbolBinario arbol1, arbol2, arbol3, arbol4;
//    construir(arbol);
//    cout<<"Es árbol vacío: "<<esArbolVacio(arbol)<<endl;
    
//    elemento.numero = 25;
//    plantarArbolBinario(arbol1, nullptr, elemento, nullptr);
//    
//    elemento.numero = 75;
//    plantarArbolBinario(arbol2, nullptr, elemento, nullptr);
//    
//    elemento.numero = 150;
//    plantarArbolBinario(arbol4, nullptr, elemento, nullptr);
//    
//    elemento.numero = 50;
//    plantarArbolBinario(arbol3, arbol1, elemento, arbol2);
//    
//    elemento.numero = 100;
//    plantarArbolBinario(arbol, arbol3, elemento, arbol4);
//       
//    cout <<"Recorrer en pre orden: "<< endl;
//    recorrerPreOrden(arbol); cout<<endl;
//    
//    cout <<"Recorrer en En orden: "<< endl;
//    recorrerEnOrden(arbol); cout<<endl;
//    
//    cout <<"Recorrer en Post orden: "<< endl;
//    recorrerPostOrden(arbol); cout<<endl;
//    
//    cout<<"Altura árbol: " << altura(arbol) <<endl;
    


//    recorrerEnOrden(arbol);
    
    
//    hallarPrincipal(arbol);
    
    //Construimos el arbol de paquetes (Caso1)
//    construir(arbol9);
//    construir(arbol10);
//    construir(arbol_paquetes);
//    
//    //Construimos el arbol de paquetes
//    
//    elemento.numero = 3;
//    plantarArbolBinario(arbol9,nullptr,elemento,nullptr);
//    
//    elemento.numero = 9;
//    plantarArbolBinario(arbol10,nullptr,elemento,nullptr);
//    
//    elemento.numero = 5;
//    plantarArbolBinario(arbol_paquetes,arbol9,elemento,arbol10);
    
     construir(arbol9);
    construir(arbol10);
    construir(arbol_paquetes);
    
    //Construimos el arbol de paquetes (Caso2)
    
    elemento.numero = 3;
    plantarArbolBinario(arbol9,nullptr,elemento,nullptr);
    
    elemento.numero = 9;
    plantarArbolBinario(arbol10,nullptr,elemento,nullptr);
    
    elemento.numero = 6;
    plantarArbolBinario(arbol_paquetes,arbol9,elemento,arbol10);
    
    
    //Construimos el arbol de sistemas
    construir(arbol7);
    construir(arbol8);
    construir(arbol5);
    construir(arbol6);
    construir(arbol_sistemas);
    
    elemento.numero = 2;
    plantarArbolBinario(arbol7,nullptr,elemento,nullptr);
    
    elemento.numero = 3;
    plantarArbolBinario(arbol8,nullptr,elemento,nullptr);
    
    elemento.numero = 7;
    plantarArbolBinario(arbol5,arbol7,elemento,arbol8);
    
    elemento.numero = 8;
    plantarArbolBinario(arbol6,nullptr,elemento,nullptr);
    
    elemento.numero = 1;
    plantarArbolBinario(arbol_sistemas,arbol5,elemento,arbol6);
    
//    recorrerEnOrden(arbol_paquetes);
//    recorrerEnOrden(arbol_sistemas);
    
    arbol = aplicar_arbol(arbol_paquetes,arbol_sistemas);
    
//    recorrerEnOrden(arbol);
//    
    determinar_anomalia(arbol);
    
    return 0;
}
