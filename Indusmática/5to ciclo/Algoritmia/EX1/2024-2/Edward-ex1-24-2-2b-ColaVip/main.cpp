/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include "Elemento.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
using namespace std;
#define ESP 10


Elemento desencolarNoVip(Cola&cola){
    
    Nodo*aux=cola.lista.vip->siguiente;
    cola.lista.vip->siguiente=aux->siguiente;
    Elemento ele=aux->elemento;
    delete aux;
    return ele;
}

Elemento desencolarVip(Cola&cola){
    
    Nodo*aux=cola.lista.cabeza;
    cola.lista.cabeza=aux->siguiente;
    Elemento ele=aux->elemento;
    delete aux;
    return ele;
}

void procesar(Cola &cola,int &vipAten,int &vipNoAten){
    
    int tiempoAct=15;
    Elemento ele;
    while(!esColaVacia(cola)){
        ele=desencolarNoVip(cola);
        tiempoAct+=20;
//        el que sigue es VIP
        ele=desencolarVip(cola);
        if(tiempoAct-ele.numero<=ESP){
            tiempoAct+=20;
            vipAten++;
        }
        else vipNoAten++;
    }
}


void insertarOrdenado(Lista &lista,Elemento ele){
    
    Nodo*nuevo=crearNodo(ele,nullptr);
    if(esListaVacia(lista)){
        lista.cabeza=nuevo;
        lista.cola=nuevo;
        if(ele.tipo==1)lista.vip=nuevo;
    }
    else{
        if(ele.tipo==1){
            if(lista.vip){
                nuevo->siguiente=lista.vip->siguiente;
                lista.vip->siguiente=nuevo;
                if(lista.cola->elemento.tipo==1)lista.cola=nuevo;
            }
            else{
                nuevo->siguiente=lista.cabeza;
                lista.cabeza=nuevo;
            }
            lista.vip=nuevo;
        }
        else{
            lista.cola->siguiente=nuevo;
            lista.cola=nuevo;
        }
    }
    lista.longitud++;
}

void encolarOrd(struct Cola & cola, const struct Elemento & elemento){
    
    insertarOrdenado(cola.lista,elemento);
}


int main(int argc, char** argv) {

    Cola cola;
    construir(cola);
    
    encolarOrd(cola,{15,0});
    encolarOrd(cola,{30,1});
    encolarOrd(cola,{45,0});
    encolarOrd(cola,{60,1});
    encolarOrd(cola,{75,0});
    encolarOrd(cola,{90,1});
    
    imprimir(cola);
    int vipAten=0,vipNoAten=0;
    procesar(cola,vipAten,vipNoAten);
    cout<<"Vip aten: "<<vipAten<<endl;
    cout<<"Vip no aten: "<<vipNoAten<<endl;
    
    return 0;
}

