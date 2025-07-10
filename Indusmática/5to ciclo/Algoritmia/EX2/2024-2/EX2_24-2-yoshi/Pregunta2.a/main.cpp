/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 8 de julio de 2025, 17:15
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#include "ArbolB.h"
#include "funcionesAB.h"
/*
 * 
 */


int convertirBinario(int num){
    int total = 0, base = 0;
    while(num>0){
        total += (num % 10)*pow(2,base++);
        num /= 10;
    }
    return total;
}

int SeEncuentra(NodoArbol* raiz,int num,int opc){
    if (raiz){
        int opcion = opc*10 + raiz->elemento.numero;
        if (convertirBinario(opcion) == num)
            return 1;
        else{
            if (SeEncuentra(raiz->izquierda,num,opcion))
                return 1;
            else{
                if (SeEncuentra(raiz->derecha,num,opcion))
                    return 1;
                else return 0;
            }
        }
    }return 0;
}

imprimirBinarios(NodoArbol* raiz,int num){
    if (raiz){
        num = num*10 + raiz->elemento.numero;
        cout << left << setw(10) << num<<":"<<convertirBinario(num)<<endl;
        imprimirBinarios(raiz->izquierda,num);
        imprimirBinarios(raiz->derecha,num);
    }
}

void imprimirBinLados(ArbolBinario arbol){
    imprimirBinarios(arbol.raiz->izquierda,0);
    imprimirBinarios(arbol.raiz->derecha,0);
}

int NumFinder(ArbolBinario arbol,int num){
    cout<<"Se encuentra el número "<<num<<"?: ";
    if (SeEncuentra(arbol.raiz->izquierda,num,0))
        return 1;
    else if (SeEncuentra(arbol.raiz->derecha,num,0))
        return 1;
    else return 0;
}

int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);
    
    //armado primer nivel
    arbol.raiz = new NodoArbol;
    arbol.raiz->elemento.numero = 7; //root
    arbol.raiz->derecha = new NodoArbol;
    arbol.raiz->derecha->elemento.numero = 0;
    arbol.raiz->derecha->derecha = nullptr;
    arbol.raiz->derecha->izquierda = nullptr;
    arbol.raiz->izquierda = new NodoArbol;
    arbol.raiz->izquierda->elemento.numero = 1;
    
    //armado segundo nivel
    arbol.raiz->izquierda->izquierda = new NodoArbol;
    arbol.raiz->izquierda->izquierda->elemento.numero = 1;
    arbol.raiz->izquierda->derecha = new NodoArbol;
    arbol.raiz->izquierda->derecha->elemento.numero = 0;
    
    //armado tercer nivel
    arbol.raiz->izquierda->izquierda->izquierda = new NodoArbol;
    arbol.raiz->izquierda->izquierda->izquierda->elemento.numero = 1;
    arbol.raiz->izquierda->izquierda->derecha = nullptr;
    arbol.raiz->izquierda->derecha->izquierda = new NodoArbol;
    arbol.raiz->izquierda->derecha->izquierda->elemento.numero = 1;
    arbol.raiz->izquierda->derecha->derecha = new NodoArbol;
    arbol.raiz->izquierda->derecha->derecha->elemento.numero = 0;
    
    //armado cuarto nivel
    arbol.raiz->izquierda->izquierda->izquierda->izquierda =  nullptr;
    arbol.raiz->izquierda->izquierda->izquierda->derecha =  new NodoArbol;
    arbol.raiz->izquierda->izquierda->izquierda->derecha->elemento.numero = 0;
    arbol.raiz->izquierda->derecha->derecha->izquierda = new NodoArbol;
    arbol.raiz->izquierda->derecha->derecha->izquierda->elemento.numero = 1;
    arbol.raiz->izquierda->derecha->derecha->derecha = nullptr;
    arbol.raiz->izquierda->derecha->izquierda->derecha = nullptr;
    arbol.raiz->izquierda->derecha->izquierda->izquierda = nullptr;
    
    //null del quinto nivel
    arbol.raiz->izquierda->izquierda->izquierda->derecha->derecha = nullptr;
    arbol.raiz->izquierda->izquierda->izquierda->derecha->izquierda = nullptr;
    arbol.raiz->izquierda->derecha->derecha->izquierda->derecha = nullptr;
    arbol.raiz->izquierda->derecha->derecha->izquierda->izquierda = nullptr;
    
    cout<<NumFinder(arbol,0)<<endl;
    cout<<NumFinder(arbol,1)<<endl;
    cout<<NumFinder(arbol,2)<<endl;
    cout<<NumFinder(arbol,3)<<endl;
    cout<<NumFinder(arbol,5)<<endl;
    cout<<NumFinder(arbol,7)<<endl;
    cout<<NumFinder(arbol,9)<<endl;
    cout<<NumFinder(arbol,12)<<endl;
    cout<<NumFinder(arbol,14)<<endl;
    
    cout<<endl<<endl;
    
    imprimirBinLados(arbol);
    return 0;
}

