/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 8 de junio de 2025, 16:56
 */

#include <iostream>
#include <math.h>
using namespace std;
#include "ArbolB.h"
#include "Elemento.h"
#include "funcionesAB.h"

void insertarNodo(NodoArbol*&p,Elemento ele){
    
    p=crearNuevoNodo(nullptr,ele,nullptr);
}


void llenarArbol(ArbolBinario&arbol){
    
    Elemento ele;
    ele.numero=0;
    ele.fin=false;
    plantarArbolBinario(arbol,nullptr,ele,nullptr);
    
    ele.numero=1;
    ele.fin=true;
    insertarNodo(arbol.raiz->izquierda,ele);
    
    ele.numero=1;
    ele.fin=true;
    insertarNodo(arbol.raiz->izquierda->izquierda,ele);
    
    ele.numero=1;
    ele.fin=false;
    insertarNodo(arbol.raiz->izquierda->izquierda->izquierda,
            ele);
    
    ele.numero=0;
    ele.fin=true;
    insertarNodo(arbol.raiz->izquierda->izquierda->izquierda->
            derecha,ele);
    
//    -----------
    ele.numero=0;
    ele.fin=false;
    insertarNodo(arbol.raiz->izquierda->derecha,ele);
    
    ele.numero=1;
    ele.fin=true;
    insertarNodo(arbol.raiz->izquierda->derecha->izquierda,ele);
    
    ele.numero=0;
    ele.fin=false;
    insertarNodo(arbol.raiz->izquierda->derecha->derecha,ele);
    
    ele.numero=1;
    ele.fin=true;
    insertarNodo(arbol.raiz->izquierda->derecha->
            derecha->izquierda,ele);
    
//    ------------
    
    ele.numero=0;
    ele.fin=true;
    insertarNodo(arbol.raiz->derecha,ele);
    
}

void revisar(NodoArbol*p,int*arr,int n,int i,bool&sePudo){
    
    if(!p or arr[i]!=p->elemento.numero)return;
    
    if(i==n-1){
        if(p->elemento.fin)
            sePudo=true;
        return;
    }
    
    revisar(p->izquierda,arr,n,i+1,sePudo);
    revisar(p->derecha,arr,n,i+1,sePudo);
    
}

bool validarEnArbol(ArbolBinario arbol,int num){
    
    int resto;
    int aux[20]{};
    
    int i=0;
    while(num>0){
        resto=num%2;
        aux[i]=resto;
        num/=2;
        i++;
    }
    int n=i+1;
    int arr[n]{};
    
    for (int k = 0; k <n; k++) {
        arr[k]=aux[n-1-k];
        cout<<arr[k]<<" ";
    }
    
    bool sePudo=false;
    revisar(arbol.raiz,arr,n,0,sePudo);
    
    return sePudo;
}

void imprimirNum(int*arr,int fin){
    
    int num=0;
    int e=0;
    for (int i = fin; i>= 0; i--) {
        num+=arr[i]*(int)round(pow(2,e++));
    }
    for (int i = 1; i <=fin; i++) {
        cout<<arr[i];
    }
    cout<<" : " <<num<<endl;

    
}

void imprimirNumeros(NodoArbol*p,int*arr,int i){
    
    if(!p)return;
    
    arr[i]=p->elemento.numero;
    if(p->elemento.fin)
        imprimirNum(arr,i);
    imprimirNumeros(p->izquierda,arr,i+1);
    imprimirNumeros(p->derecha,arr,i+1);
}


int main(int argc, char** argv) {

    ArbolBinario arbol;
    
    construir(arbol);
    
    llenarArbol(arbol);
    
    recorrerEnOrden(arbol);
    cout<<endl;
    int num=6;
    
    if(validarEnArbol(arbol,num))
        cout<<endl<<"si"<<endl;
    else cout<<endl<<"no"<<endl;
    
    int arr[100]{};
    imprimirNumeros(arbol.raiz,arr,0);
    
    return 0;
}
