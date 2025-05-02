/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include <fstream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

    
void destruir(Lista &lista){
    
    Nodo *p=lista.cabeza,*aux;
    while(p){
        aux=p->siguiente;
        delete p;
        p=aux;
    }
}


bool operator <(Elemento &ele1,Elemento &ele2){
    
    bool resu;
    if(ele1.hora<ele2.hora)resu=true;
    else if(ele1.hora>ele2.hora)resu=false;
    else{
        if(ele1.dia<ele2.dia)resu=true;
        else resu=false;
    }
    return resu;
}

void fusionar(Lista &lis1,Lista &lis2){
    
    if(lis1.cola->elemento<lis2.cabeza->elemento){
        lis1.cola->siguiente=lis2.cabeza;
        lis1.cola=lis2.cola;
    }
    else{
        if(lis2.cola->elemento<lis1.cabeza->elemento){
            lis2.cola->siguiente=lis1.cabeza;
            lis1.cabeza=lis2.cabeza;
        }
        else{
            Nodo *ini=nullptr,*p=nullptr;
            while(!esListaVacia(lis1) and !esListaVacia(lis2)){
                if(lis1.cabeza->elemento<lis2.cabeza->elemento){
                    if(not ini){
                        ini=lis1.cabeza;
                        p=lis1.cabeza;
                    }
                    else{
                        p->siguiente=lis1.cabeza;
                        p=p->siguiente;
                    }
                    lis1.cabeza=lis1.cabeza->siguiente;
                }
                else{
                    if(not ini){
                        ini=lis2.cabeza;
                        p=lis2.cabeza;
                    }
                    else{
                        p->siguiente=lis2.cabeza;
                        p=p->siguiente;
                    }
                    lis2.cabeza=lis2.cabeza->siguiente;
                }
            }
            if(!esListaVacia(lis1)){
                p->siguiente=lis1.cabeza;
                p=lis1.cola;
            }
            else{
                p->siguiente=lis2.cabeza;
                p=lis2.cola;
            }
            lis1.cabeza=ini;
            lis1.cola=p;
        }
    }
}

Nodo* hallarAnt(Elemento &elemento,Lista &lista){
    
    Nodo *p=lista.cabeza,*ant=nullptr;
    while(p and elemento.hora>p->elemento.hora){
        ant=p;
        p=p->siguiente;
    }
    return ant;
}

void insertarOrdenado(Elemento &elemento,Lista &lista){
    
    Nodo*ant=hallarAnt(elemento,lista);
    if(not ant) lista.cabeza=crearNodo(elemento,lista.cabeza);
    else ant->siguiente=crearNodo(elemento,ant->siguiente);
    lista.longitud++;
    lista.cola=obtenerUltimoNodo(lista);
}

void llenar(Lista *listas){
    
    ifstream arch("Datos.txt",ios::in);
    if(not arch.is_open()){
        cout<<"Error en "<<"Datos.txt"; exit(1);
    }
    Elemento elemento;
    int i=0;
    while(true){
        arch>>elemento.dia;
        if(arch.eof())break;
        arch>>elemento.hora>>elemento.sucursal;
        insertarOrdenado(elemento,listas[i]);
        if(arch.get()=='\n')i++;
    }
}


int main(int argc, char** argv) {

//    0 8 6   0 10 14   0 12 1
    Lista listas[5];
    for (int i = 0; i < 5; i++) {
        construir(listas[i]);
    }
    llenar(listas);
    for (int i = 0; i < 5; i++) {
        imprime(listas[i]);
    }
    for (int i = 1; i <=4; i++) {
        fusionar(listas[0],listas[i]);
    }
    cout<<endl;
    imprime(listas[0]);
    destruir(listas[0]);
    cout<<endl;
    imprime(listas[0]);
    
    return 0;
}

