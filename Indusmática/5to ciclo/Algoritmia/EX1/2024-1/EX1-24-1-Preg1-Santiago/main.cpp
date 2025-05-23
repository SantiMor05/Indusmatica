/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 21 de mayo de 2025, 21:48
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "funcionesLista.h"
#include "Lista.h"

using namespace std;

/*
 * 
 */


void escoger(Lista lista, Lista &escogidos, int cantProd, int calorMax) {

    Nodo *recorrido = lista.cabeza;
    int suma = 0, cont = 0;

    while (recorrido != nullptr) {
        if (suma + recorrido->elemento.calorias <= calorMax) {
            insertarAlFinal(escogidos, recorrido->elemento.calorias);
            suma += recorrido->elemento.calorias;
            cont++;
            if (cont == cantProd)break;
        }
        recorrido = recorrido->siguiente;
    }
}

void juntar(Lista &tipo1, Lista tipo2) {

    Nodo *ini = nullptr, *fin = nullptr, *recorrido1 = tipo1.cabeza,
            *recorrido2 = tipo2.cabeza, *ant1, *ant2;

    while (recorrido1 != nullptr and recorrido2 != nullptr) {

        if (recorrido1->elemento.calorias < recorrido2->elemento.calorias) {
            ant1 = recorrido1;
            recorrido1 = recorrido1->siguiente;
            if (ini == nullptr) {
                ini = ant1;
                fin = ant1;
            } else
                fin->siguiente = ant1;
            if (recorrido1->elemento.calorias < recorrido2->elemento.calorias) {
                //Metemos es bloque
                fin = recorrido1;
                ant1 = recorrido1;
                recorrido1 = recorrido1->siguiente;
            } else {//Solo metemos uno
                fin = ant1;
            }
        } else {
            ant2 = recorrido2;
            recorrido2 = recorrido2->siguiente;
            if (ini == nullptr){
                ini = ant2;
                fin = ant2;
            }
            else
                fin->siguiente = ant2;
            if (recorrido2->elemento.calorias < recorrido1->elemento.calorias) {

                fin = recorrido2;
                ant2 = recorrido2;
                recorrido2 = recorrido2->siguiente;
            } else {
                //Metemos solo uno
                fin = ant2;
            }
        }
    }


    if (recorrido1 == nullptr) {
        if(ini == nullptr){
            ini = tipo2.cabeza;
        }
        if(fin == nullptr)
            fin = tipo2.cabeza;
        else
            fin->siguiente = recorrido2;
        while (recorrido2 != nullptr) {
            ant2 = recorrido2;
            recorrido2 = recorrido2->siguiente;
        }
        fin = ant2;
    }
    else{
        if(ini == nullptr){
            ini = tipo1.cabeza;        }
        
        if(fin == nullptr)
            fin = tipo1.cabeza;
        else
            fin->siguiente = recorrido1;
            
        fin->siguiente = recorrido1;
        while (recorrido1 != nullptr) {
            ant1 = recorrido1;
            recorrido1 = recorrido1->siguiente;
        }
        fin = ant1;
    }
    
    tipo1.cabeza = ini;

}

void unirListas(Lista *escogidos) {

    for (int i = 1; i < 6; i++) {
        //imprime(escogidos[0]);
       // imprime(escogidos[i]);
        if(!esListaVacia(escogidos[i]))
            juntar(escogidos[0], escogidos[i]);
        //imprime(escogidos[0]);
    }
}

int main(int argc, char** argv) {

    Lista lista[6], escogidos[6];

    for (int i = 0; i < 6; i++) {
        construir(lista[i]);
        construir(escogidos[i]);
    }


    //Tipo A
    insertarAlFinal(lista[0], 120);
    insertarAlFinal(lista[0], 145);
    insertarAlFinal(lista[0], 230);
    insertarAlFinal(lista[0], 247);
    insertarAlFinal(lista[0], 285);

    //Tipo D
    insertarAlFinal(lista[1], 182);
    insertarAlFinal(lista[1], 240);
    insertarAlFinal(lista[1], 300);

    //Tipo B
    insertarAlFinal(lista[2], 58);
    insertarAlFinal(lista[2], 120);
    insertarAlFinal(lista[2], 247);
    insertarAlFinal(lista[2], 278);

    //Tipo H
    insertarAlFinal(lista[3], 128);
    insertarAlFinal(lista[3], 236);
    insertarAlFinal(lista[3], 354);
    insertarAlFinal(lista[3], 540);
    insertarAlFinal(lista[3], 782);

    int cantiposAIngresar = 2, cantProd, calorMax;

    for (int i = 0; i < cantiposAIngresar; i++) {
        cout << "Cantidad de Productos del tipo " << i << ": ";
        cin >> cantProd;
        cout << "Calorias maxima de todos los productos: ";
        cin >> calorMax;

        escoger(lista[i], escogidos[i], cantProd, calorMax);
    }
    unirListas(escogidos);
    imprime(escogidos[0]);


    return 0;
}

