/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 13 de mayo de 2025, 05:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funcionesLista.h"
#include "Lista.h"
using namespace std;

/*
 * 
 */

/*Funciones para cargar datos a la lista*/

int hallarTemPre(char comp){
    if(comp == 'b')return 10;
    else if(comp == 'm')return 20;
    else return 30;
}

void rellenarPedido(struct Pedido &pedido, char *id, int temPre, int tmpVia){
    strcpy(pedido.id, id);
    pedido.tiempoPreparacion= temPre;
    pedido.tiempoEstViaje = tmpVia;
}

void cargarDatosLista(const char*nombArch, Lista &lista){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    
    struct Pedido pedido;
    char id[5], comp, c;
    int temPre, tmpVia, dispPer, horaPun;
    double dist;
    
    /*P001, m, 1, 12.5, 0 */
    while (true) {
        arch.getline(id, 5, ',');
        if(arch.eof())break;
        arch>>comp>>c>>dispPer>>c>>dist>>c>>horaPun;
        arch.get();
        temPre = hallarTemPre(comp);
        if(dispPer == 0)temPre+=5;
        //45km/h = 3/4 km/min
        tmpVia= (dist/3)*4;
        if(horaPun == 1)tmpVia += 10;
        rellenarPedido(pedido, id, temPre, tmpVia);
        insertarAlFinal(lista, pedido);
    }
}

/*Funciones para ordenar lista*/

bool esMayor(Nodo *pRec, Nodo *pSig, int opcion){
    int tiempoTotalRec, tiempoTotalSig;
    tiempoTotalRec = pRec->elemento.tiempoEstViaje + pRec->elemento.tiempoPreparacion;
    tiempoTotalSig = pSig->elemento.tiempoEstViaje + pSig->elemento.tiempoPreparacion;
    
    if(opcion == 1){ //Pasada 1
        tiempoTotalRec %= 10;
        tiempoTotalSig %= 10;
        if(tiempoTotalRec > tiempoTotalSig)return true;
    }
    else{ //Pasada 2
        tiempoTotalRec /= 10;
        tiempoTotalSig /= 10;
        if(tiempoTotalRec > tiempoTotalSig)return true;
    }
    return false; 
}

void ordenar(Lista &lista, int opcion){
    Nodo *pAnt = nullptr, *pRec, *pAux;
    //pAux = pSig, es decir pAux es el nodo siguiente del pRec
    int n = longitud(lista);
    bool seCambio = true; //Si hubo cambio en los nodos
    
    while(n > 1) { //while(seCambio) //Hasta que ya no haya cambios o hasta que se haya recorrido toda la lista
        seCambio = false;
        pAnt = nullptr;
        pRec = lista.cabeza;
        pAux = pRec->siguiente; 
        
        for (int i = 1; i < n; i++) {
            if(esMayor(pRec, pAux, opcion)){ //Caso pRec sea mayor que pAux (pSig)
                seCambio = true;
                if(pAnt == nullptr){ //Caso en el que el cambio se de en el primer nodo (Cabeza)
                    pRec->siguiente = pAux->siguiente;
                    pAux->siguiente = pRec;
                    lista.cabeza = pAux;
                }
                else{
                    pRec->siguiente = pAux->siguiente;
                    pAux->siguiente = pRec;
                    pAnt->siguiente = pAux;
                }
                pAnt = pAux;
                pAux = pRec->siguiente;
            }
            else{
                pAnt = pRec;
                pRec = pAux;
                pAux = pRec->siguiente;
            }
        }
        if(not seCambio)break; //Si ya no hay cambios significa que ya está ordenado
        n--; //Cada nodo mayor lo manda al final por lo que cada pasada va hasta 1 menos
    }   
}



void ordenarLista(Lista &lista){
    ordenar(lista, 1); //Pasada 1
    
    cout<<"Lista Ordenada Pasada 1: "<<endl;
    imprime(lista);
    ordenar(lista, 2); //Pasada 2
    
    cout<<"Lista Ordenada Pasada 2: "<<endl;
    imprime(lista);
}
int main(int argc, char** argv) {
    struct Lista lista;
    
    construir(lista);
    
    cargarDatosLista("Datos.txt", lista);
    cout<<"Lista del principio: "<<endl;
    imprime(lista);
    cout<<"------------------------"<<endl;
    
    ordenarLista(lista);
    cout<<"------------------------"<<endl;
    cout<<"Lista Ordenada: "<<endl;
    imprime(lista);
    
    return 0;
}

