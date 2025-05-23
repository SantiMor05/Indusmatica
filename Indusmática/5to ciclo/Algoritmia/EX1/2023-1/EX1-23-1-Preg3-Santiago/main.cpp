/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 22 de mayo de 2025, 19:58
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "funcionesLista.h"

using namespace std;

/*
 * 
 */


void ordenar(Lista &lista) {

    Nodo *ant, *penultimo, *recorrido;
    int n = lista.longitud;
    for (int i = 0; i < n; i++) {
        ant = nullptr;
        penultimo = nullptr;
        recorrido = lista.cabeza;
        for (int j = i; j < n; j++) {
            if (ant != nullptr) {//Es la cabeza
                if (ant->elemento.numero / 10 > recorrido->elemento.numero / 10) {
                    if (penultimo == nullptr) {
                        //Ant es la cabeza
                        lista.cabeza = recorrido;
                    } else
                        penultimo->siguiente = recorrido;
                    ant->siguiente = recorrido->siguiente;
                    recorrido->siguiente = ant;

                    penultimo = recorrido;
                    recorrido = ant->siguiente;
                } else {
                    penultimo = ant;
                    ant = recorrido;
                    recorrido = recorrido->siguiente;
                }
            } else {
                penultimo = ant;
                ant = recorrido;
                recorrido = recorrido->siguiente;
            }
        }
    }

}

void formarEjercitos(Lista lista, Lista *ejercitos) {

    int orden, fuerza;
    Nodo *recorrido;

    ordenar(lista);
    imprime(lista);

    for (int i = 0; i < 3; i++)
        construir(ejercitos[i]);
    recorrido = lista.cabeza;
    while (recorrido != nullptr) {
        orden = recorrido->elemento.numero % 10;
        fuerza = recorrido->elemento.numero / 10;
        insertarAlFinal(ejercitos[orden - 1], fuerza);
        recorrido = recorrido->siguiente;
    }

    cout << endl << "Los ejercitos formados son :" << endl;
    cout << "Ejercito 1 - Bowser: ";
    imprime(ejercitos[0]);
    cout << "Nivel de Ataque Total del Ejercito 1: " << ejercitos[0].poder << endl;

    cout << endl << "Ejercito 2 - Peach: ";
    imprime(ejercitos[1]);
    cout << "Nivel de Ataque Total del Ejercito 2: " << ejercitos[1].poder << endl;

    cout << endl << "Ejercito 3 - Donkey Kong: ";
    imprime(ejercitos[2]);
    cout << "Nivel de Ataque Total del Ejercito 3: " << ejercitos[2].poder << endl;

}

void fusionar(Lista &lista1, Lista lista2) {

    Nodo *recorrido1 = lista1.cabeza, *recorrido2 = lista2.cabeza,
            *ini = nullptr, *fin = nullptr;

    while (recorrido1 != nullptr and recorrido2 != nullptr) {
        if (recorrido1->elemento.numero < recorrido2->elemento.numero) {
            if (ini == nullptr)
                ini = recorrido1;
            else
                fin->siguiente = recorrido1;
            fin = recorrido1;
            recorrido1 = recorrido1->siguiente;
        } else {
            if (ini == nullptr)
                ini = recorrido2;
            else
                fin->siguiente = recorrido2;
            fin = recorrido2;
            recorrido2 = recorrido2->siguiente;
        }
    }

    if (recorrido1 == nullptr) {
        fin->siguiente = recorrido2;
        fin = lista2.cola;
    } else {
        fin->siguiente = recorrido1;
        fin = lista1.cola;
    }
    lista1.cabeza = ini;
    lista1.cola = fin;
    
    lista1.poder += lista2.poder;
}

void simularBatalla(Lista *ejercitos, int n) {

    Nodo *recorrido1, *recorrido2, *aux;
    bool fusiona = false;
    while (!esListaVacia(ejercitos[0]) and !esListaVacia(ejercitos[1])) {
        cout << endl << "Inicia la batalla:" << endl;
        cout << "Ejercito 1 - Bowser: ";
        imprime(ejercitos[0]);
        cout << endl << "Ejercito 2 - Peach: ";
        imprime(ejercitos[1]);

        recorrido1 = ejercitos[0].cabeza;
        recorrido2 = ejercitos[1].cabeza;

        for (int i = 0; i < n and recorrido1 != nullptr and recorrido2 != nullptr; i++) {
            cout << "Pelea " << i + 1 << ":" << recorrido1->elemento.numero <<
                    "vs " << recorrido2->elemento.numero << ", ";
            if (recorrido1->elemento.numero > recorrido2->elemento.numero) {
                cout << "gana " << recorrido1->elemento.numero << endl;
                aux = recorrido2->siguiente;
                eliminaNodo(ejercitos[1], recorrido2->elemento.numero);
                recorrido2 = aux;
                recorrido1 = recorrido1->siguiente;
            } else {
                cout << "gana " << recorrido2->elemento.numero << endl;
                aux = recorrido1->siguiente;
                eliminaNodo(ejercitos[0], recorrido1->elemento.numero);
                recorrido1 = aux;
                recorrido2 = recorrido2->siguiente;
            }
        }
        cout << "Nivel de Ataque Total del Ejercito 1: " << ejercitos[0].poder << endl;
        cout << "Nivel de Ataque Total del Ejercito 2: " << ejercitos[1].poder << endl;
        if(ejercitos[1].poder <= ejercitos[0].poder and !fusiona){
            fusionar(ejercitos[1], ejercitos[2]);
            cout << "El ejercito de Donkey Kong se une al ejército de Peach" <<
                    endl;
            fusiona = true;
        }
        else
            cout << "Ya no se puede unir nadie al ejercito de Peach" << endl;
    }
    if(esListaVacia(ejercitos[0]))
        cout << "Gana la batalla Peach" << endl;
    else
        cout << "Gana la batalla Bowser" << endl;

}

int main(int argc, char** argv) {

    int n = 2, guerreros = 12;

    Lista lista, ejercitos[3];
    construir(lista);

    insertarAlFinal(lista, 723);
    insertarAlFinal(lista, 182);
    insertarAlFinal(lista, 123);
    insertarAlFinal(lista, 262);
    insertarAlFinal(lista, 851);
    insertarAlFinal(lista, 352);
    insertarAlFinal(lista, 653);
    insertarAlFinal(lista, 103);
    insertarAlFinal(lista, 561);
    insertarAlFinal(lista, 841);
    insertarAlFinal(lista, 391);
    insertarAlFinal(lista, 241);

    cout << "Lista Guerreros: ";
    imprime(lista);


    formarEjercitos(lista, ejercitos);

    simularBatalla(ejercitos, n);

    return 0;
}

