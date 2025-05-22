/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;



void agregarConexion(Lista &lista,int compu){
    
    insertarAlFinal(lista,compu);
}

void eliminarConexion(Lista &lista,int compu){
    
    if(esListaVacia(lista)){
        cout<<"Error";
        return;
    }
    Nodo*ant=nullptr,*p=lista.cabeza;
    while(p){
        if(p->elemento.numero==compu)break;
        ant=p;
        p=p->siguiente;
    }
    if(not p){
        cout<<"Error";
        return;
    }
    if(ant){
        ant->siguiente=p->siguiente;        
    }
    else lista.cabeza=p->siguiente;
    delete p;
//    eliminaNodo(lista,compu);
    
}

bool buscar(Lista &lista,Lista *listas,int compuDest){
    
    
    Nodo*p=lista.cabeza;
    int compuAux;
    while(p){
        compuAux=p->elemento.numero;
        if(compuAux==compuDest)return true;
        if(buscar(listas[compuAux-1],listas,compuDest))return true;
        p=p->siguiente;
    }
    return false;
}

void hayEscaladaPrivilegios(Lista*listas,int compuOri,int compuDest){
    
    bool sePuede=buscar(listas[compuOri-1],listas,compuDest);
    if(sePuede)
        cout<<"Si se puede de "<<compuOri<<" a "<<compuDest<<endl;
    else cout<<"No se puede de "<<compuOri<<" a "<<compuDest<<endl;
}

void imprimirConex(Lista &lista){
    
    
    Nodo*p=lista.cabeza;
    while(p){
        cout<<"-> "<<p->elemento.numero<<"  ";
        p=p->siguiente;
    }
}


void imprimirRed(Lista*listas){
    
    for (int i = 0; i < 6; i++) {
        cout<<"Computadora "<<i+1<<": ";
        imprimirConex(listas[i]);
        cout<<endl;
    }

}


int main(int argc, char** argv) {

    int n=6;
    Lista listas[n]{};
    int compuOri=1,compuDest=6;
    
    agregarConexion(listas[0],2);
    agregarConexion(listas[0],3);
    agregarConexion(listas[1],4);
    agregarConexion(listas[2],5);
    agregarConexion(listas[3],6);
   
    hayEscaladaPrivilegios(listas,compuOri,compuDest);
    
    imprimirRed(listas);
    
    cout<<endl;
    eliminarConexion(listas[0],2);
    hayEscaladaPrivilegios(listas,compuOri,compuDest);
    imprimirRed(listas);
    
    return 0;
}

