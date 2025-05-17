/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 16 de mayo de 2025, 08:51 PM
 */

#include <iostream>

using namespace std;
#include "Lista.h"
#include "funcionesLista.h"

/*
 * 
 */

void divirParesImpares(Lista &lista) {

    Nodo *rec1 = lista.cabeza, *ant1 = nullptr;
    Nodo*rec2 = lista.cabeza, *ant2 = nullptr, *aux;
    int tamanho = longitud(lista);

    for (int i = 0; i < tamanho / 2; i++) {
        ant2 = rec2;
        rec2 = rec2->siguiente;
    }

    int imp = 1, par = 1;
    while (imp < tamanho / 2 and par < tamanho / 2) {
        while (rec1->elemento.numero % 2 == 0 and par < tamanho / 2) { // halla impares
            ant1 = rec1;
            rec1 = rec1->siguiente;
            par++;
        }
        while (rec2->elemento.numero % 2 != 0 and imp < tamanho / 2) { // halla pares
            ant2 = rec2;
            rec2 = rec2->siguiente;
            imp++;
        }
        if (rec1->elemento.numero % 2 != 0 and rec2->elemento.numero % 2 == 0) {
            cout << "Rec1: " << rec1->elemento.numero << " | Rec2:" << rec2->elemento.numero << endl;
            if (ant1 == nullptr) lista.cabeza = rec2;
            else ant1->siguiente = rec2;
            ant2->siguiente = rec1;
            aux = rec2->siguiente;
            rec2->siguiente = rec1->siguiente;
            rec1->siguiente = aux;
            rec1 = rec2;
            rec2 = ant2->siguiente;
            imprime(lista);
        }
    }

    //    cout << rec1->elemento.numero << " ";
    //    cout << ant2->elemento.numero << " " << rec2->elemento.numero;

}

int main(int argc, char** argv) {
    Lista lista;
    construir(lista);
    insertarAlFinal(lista, 1);
    insertarAlFinal(lista, 2);
    insertarAlFinal(lista, 3);
    insertarAlFinal(lista, 4);
    insertarAlFinal(lista, 5);
    insertarAlFinal(lista, 6);
    insertarAlFinal(lista, 7);
    insertarAlFinal(lista, 8);
    imprime(lista);

    divirParesImpares(lista);

    return 0;
}

