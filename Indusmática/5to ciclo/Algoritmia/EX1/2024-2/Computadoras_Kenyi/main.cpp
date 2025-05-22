/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 21 de mayo de 2025, 10:45 PM
 */

#include <iostream>

using namespace std;
#include "Lista.h"
#include "funcionesLista.h"
#define N 6

/*
 * 
 */
void agregarConexio(Lista *lista, int origen, int destino) {
    insertarAlFinal(lista[origen - 1], destino - 1);
    cout << "Se conecto la computadora " << origen << " con la computadora "
            << destino << endl;
}

void imprimeRed(Lista *lista) {
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << "Computador " << i + 1 << ": ";
        imprime(lista[i]);
    }
    cout << endl;
}

bool busca(Lista *lista, int ori, int des) {

    bool encontro = false;
    Nodo *rec = lista[ori - 1].cabeza;
    for (int i = 0; i < longitud(lista[ori - 1]); i++) {
        if (rec->elemento.numero + 1 == des) {
            encontro = true;
            break;
        }
        encontro = busca(lista, rec->elemento.numero + 1, des);
        if (encontro)break;
        rec = rec->siguiente;
    }
    return encontro;
}

void hayEscaladaPrivilegios(Lista *lista, int ori, int des) {
    cout << "VERIFICACION: de computadora " << ori << " a " << des << endl;

    if (busca(lista, ori, des)) {
        cout << "Resultado: Si hay escala de privilegios" << endl;
    } else cout << "Resultado: No hay escala de privilegios" << endl;
    cout << endl;
}

void eliminarConexion(Lista *lista, int ori, int des) {
    eliminaNodo(lista[ori - 1], des - 1);
    cout << "Se desconecto la computadora " << ori << " con la computadora " << des
            << endl;
}

int main(int argc, char** argv) {
    Lista lista[N];
    for (int i = 0; i < N; i++) {
        construir(lista[i]);
    }
    agregarConexio(lista, 1, 2);
    agregarConexio(lista, 1, 3);
    agregarConexio(lista, 2, 4);
    agregarConexio(lista, 5, 6);
    imprimeRed(lista);

    hayEscaladaPrivilegios(lista, 1, 6);

    agregarConexio(lista, 3, 5);
    eliminarConexion(lista, 5, 6);

    imprimeRed(lista);



    agregarConexio(lista, 4, 6);

    imprimeRed(lista);

    hayEscaladaPrivilegios(lista, 1, 6);
    return 0;
}

