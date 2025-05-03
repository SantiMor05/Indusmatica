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

void eliminarLista(Lista &lista){
    
    Nodo *p=lista.cabeza;
    if(not p)return;
    Nodo*aux;
    while(p){
        aux=p->siguiente;
        delete p;
        p=aux;
    }
}


bool operator >(Elemento &ele1,Elemento &ele2){
    
    bool resu;
    if(ele1.impacto>ele2.impacto)resu=true;
    else if(ele2.impacto>ele1.impacto)resu=false;
    else{
        if(ele1.categoria<ele2.categoria)resu=true;
        else resu=false;
    }
    return resu;
}

void fusionar(Lista &lis1,Lista &lis2){
    
    if(lis1.cola->elemento>lis2.cabeza->elemento){
        lis1.cola->siguiente=lis2.cabeza;
        lis1.cola=lis2.cola;
    }
    else{
        if(lis2.cola->elemento>lis1.cabeza->elemento){
            lis2.cola->siguiente=lis1.cabeza;
            lis1.cabeza=lis2.cabeza;
        }
        else{
            Nodo *ini=nullptr,*p=nullptr;;
            while(!esListaVacia(lis1) and !esListaVacia(lis2)){
                if(lis1.cabeza->elemento>lis2.cabeza->elemento){
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
            if(esListaVacia(lis1)){
                p->siguiente=lis2.cabeza;
                p=lis2.cola;
            }
            else{
                p->siguiente=lis1.cabeza;
                p=lis1.cola;
            }
            lis1.cabeza=ini;
            lis1.cola=p;
        }
    }
    
}

void fusionarTodas(Lista *listas){
    
    int i=0;
    for (int i = 1; i <=4; i++) {
        fusionar(listas[0],listas[i]);
//        imprime(listas[0]);
    }
}

char hallarCategoria(int i){
    
    char c;
    switch(i){
        case 0:
           c='A';
           break;
        case 1:
            c='B';
            break;
        case 2:
            c='C';
            break;
        case 3:
            c='D';
            break;
        case 4:
            c='E';
            break;
        default:
            cout<<"AAA"<<endl;
    }
    return c;
}
  

Nodo* obtenerNodoAnterior(Lista &lista,Elemento &elemento){
    
    Nodo *p=lista.cabeza,*ant=nullptr;
    if(not p)return nullptr;
    while(p and elemento.impacto<p->elemento.impacto){
        ant=p;
        p=p->siguiente;
    }
    return ant;
}


   
void insertarOrdenado(Lista &lista,Elemento &elemento){
    
    Nodo*ant=obtenerNodoAnterior(lista,elemento);
    if(ant) ant->siguiente=crearNodo(elemento,ant->siguiente);
    else lista.cabeza=crearNodo(elemento,lista.cabeza);
    lista.longitud++;
    lista.cola=obtenerUltimoNodo(lista);
}

void llenarDatos(Lista *listas){
    
//    15 13 12 11
    ifstream arch("Datos.txt",ios::in);
    if(not arch.is_open()){
        cout<<"Error en "<<"Datos.txt"; exit(1);
    }
    Elemento elemento;
    int i=0;
    while(true){
        arch>>elemento.impacto;
        if(arch.eof())break;
        elemento.categoria=hallarCategoria(i);
        insertarOrdenado(listas[i],elemento);
        if(arch.get()=='\n') i++;
    }
}



int main(int argc, char** argv) {

    Lista listas[5];
    
    for (int i = 0; i < 5; i++) {
        construir(listas[i]);
    }
    llenarDatos(listas);
    for (int i = 0; i < 5; i++) {
        imprime(listas[i]);
    }
    cout<<endl<<endl;
    fusionarTodas(listas);
    imprime(listas[0]);
    eliminarLista(listas[0]);
//    imprime(listas[0]);

    return 0;
}

