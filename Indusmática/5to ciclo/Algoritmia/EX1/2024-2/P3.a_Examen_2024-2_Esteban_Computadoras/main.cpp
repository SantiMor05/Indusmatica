/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */
#include <iomanip>
#include <iostream>
#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;


/*
 * IMPLEMENTACIÓN DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-1
 */
void eliminarConexion(struct Lista *computadoras,int compuOrigen,int compuDesconect){
    cout<<"Se desconectó la computadora "<<compuOrigen<<"  con la computador "
            <<compuDesconect<<endl;
    eliminaNodo(computadoras[compuOrigen-1],compuDesconect);
    
    
}

bool buscamos(struct Lista &compuOrigen,struct Lista* computadoras,int destino){
    
    struct Nodo *nodo;
    
    nodo= compuOrigen.cabeza;
    
    while (nodo) {
        if(nodo->elemento.numero==destino) return true;
        return buscamos(computadoras[nodo->elemento.numero-1],computadoras,destino);
//        if(buscamos(computadoras[nodo->elemento.numero-1],computadoras,destino)) return true;
        nodo= nodo->siguiente;
    }
        
    return false;


    
    
    
}

void hayEscalaPrivilegios(struct Lista *computadoras,int origen,int destino){
    cout<<"VERIFICACION: de computadora "<<origen<<" a "<<destino<<endl;
    bool siHay= buscamos(computadoras[origen-1],computadoras,destino);
    
    
    cout<<"RESULTADO: ";
    if(siHay){
        cout<<"Si hay escala de privilegios"<<endl;
    }else  cout<<"No hay escala de privilegios"<<endl;
    
}


void  imprimerRed(struct Lista *computadoras,int n){
    
    for (int i = 0; i < n; i++) {
        cout<<"Computadora "<<i+1<<": ";
        imprime(computadoras[i]);
    }

    
}
void agregarConexion(struct Lista *computadoras,int origen,int destino){
    cout<<"Se conectó la computadora "<<origen<<"  con la computador "
            <<destino<<endl;
    insertarAlFinal(computadoras[origen-1],destino);
}
int main(int argc, char** argv) {
    
    int n=6;
    struct Lista computadoras[n];
    
    //Inicializamos las 6 computadoras;
    for (int i = 0; i < n; i++) {
        construir(computadoras[i]);
    }
    
    

    agregarConexion(computadoras,1,2);
    agregarConexion(computadoras,1,3);
    agregarConexion(computadoras,2,4);
    agregarConexion(computadoras,5,6);
    
    
    
    
    imprimerRed(computadoras,n);

    hayEscalaPrivilegios(computadoras,1,6);
    
    agregarConexion(computadoras,3,5);
    eliminarConexion(computadoras,5,6);
    
    imprimerRed(computadoras,n);
    
    hayEscalaPrivilegios(computadoras,1,6);
    agregarConexion(computadoras,4,6);

    imprimerRed(computadoras,n);
    hayEscalaPrivilegios(computadoras,1,6);
    
    
    return 0;
}



