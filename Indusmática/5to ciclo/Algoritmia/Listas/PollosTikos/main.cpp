/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

void invierteiterativa(Lista &lista){
    Nodo*prec,*paux,*pant; 
    int n=lista.longitud;
    
    prec=lista.cabeza;
    paux=prec->siguiente;
    for(int i=1;i<n;i++){//por evaluar
        pant=prec;
        prec=paux;
        paux=prec->siguiente;
        prec->siguiente=pant;
        if(i==1)pant->siguiente=nullptr;
    }
    lista.cabeza=prec;

}

Nodo* inviertecore(Nodo*ptr){
    if(ptr==nullptr) return ptr;
    if(ptr->siguiente==nullptr) return ptr;
    Nodo*pini=inviertecore(ptr->siguiente);
    ptr->siguiente->siguiente = ptr;
    return pini;
}
void invierterec(Lista &lista){
    Nodo *pini=inviertecore(lista.cabeza);
    lista.cabeza->siguiente=nullptr;
    lista.cabeza=pini;
}

void fusiona(Lista &L1,Lista L2){
    if(L1.cola->elemento.numero<L2.cabeza->elemento.numero){
        L1.cola->siguiente=L2.cabeza;
        L1.cola = L2.cola;
    }
    else{
        if(L2.cola->elemento.numero<L1.cabeza->elemento.numero){
            L2.cola->siguiente = L1.cabeza;
            L1.cabeza = L2.cabeza;
        }
        else{
            Nodo*ini=nullptr,*fin=nullptr;
            while(!esListaVacia(L1) and !esListaVacia(L2) ){
                if(L1.cabeza->elemento.numero<L2.cabeza->elemento.numero){
                    if(ini==nullptr){
                        ini=L1.cabeza;
                        fin=L1.cabeza;
                    }else{
                        fin->siguiente=L1.cabeza;
                        fin = L1.cabeza;
                    }
                    L1.cabeza = L1.cabeza->siguiente;
                }
                else{ //compara cabezas
                    if(ini==nullptr){
                        ini=L2.cabeza;
                        fin=L2.cabeza;                        
                    }
                    else{
                        fin->siguiente=L2.cabeza;
                        fin = L2.cabeza;
                    }
                    L2.cabeza=L2.cabeza->siguiente;   
                }
            }
            if(!esListaVacia(L1)){
              fin->siguiente = L1.cabeza;  
              fin = L1.cola;  
            }            
            else{
              fin->siguiente = L2.cabeza;  
              fin = L2.cola;  
            }
            L1.cabeza = ini;
            L1.cola = fin;
        }
    }
}

int main(int argc, char** argv) {

    struct Lista lista1,lista2;
    /*Construimos la lista, la lista esta vacía*/
    construir(lista1);
    insertarAlFinal(lista1,6);
    insertarAlFinal(lista1,8);
    insertarAlFinal(lista1,10);
    insertarAlFinal(lista1,15);
    
    
    construir(lista2);    
    insertarAlFinal(lista2,14);
    insertarAlFinal(lista2,52);
    insertarAlFinal(lista2,64);
    insertarAlFinal(lista2,95);
    
    imprime(lista1);
    imprime(lista2);
    
    fusiona(lista1,lista2);
    imprime(lista1);
    
    return 0;
}

