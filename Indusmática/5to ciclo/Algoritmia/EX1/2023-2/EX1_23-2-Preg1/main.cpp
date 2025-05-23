/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 22 de mayo de 2025, 11:08
 */

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesLista.h"
#include "Lista.h"

using namespace std;

/*
 * 
 */

void leerDatos(Lista *&listas, int *capacidades, int &camiones) {

    ifstream arch("Datos.txt", ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo" << endl;
        exit(1);
    }

    int peso;

    arch >> camiones;

    listas = new Lista[camiones];


    for (int i = 0; i < 4; i++) {//Leemos las capacidades de las tortugas
        arch >> capacidades[i];
    }
    for (int i = 0; i < camiones; i++) {
        construir(listas[i]);
        while (true) {
            arch >> peso;
            if (peso == 0)break;
            insertarAlFinal(listas[i], peso);
        }
    }
}

void cargabin(int num, int *cromo, int n, int base) {
    for (int i = 0; i < n; i++)
        cromo[i] = 0;

    int resto, cont = 0;
    while (num > 0) {
        resto = num % base;
        num /= base;
        cromo[cont] = resto;
        cont++;
    }

}

bool buscarCombinacion(Lista *listas, int *capacidades, int camiones,
        int *solucion) {

    int *cromo = new int[camiones] {
    }, cont = 0, suma;
    int opciones = pow(4, camiones);
    bool valido;

    for (int i = 0; i < opciones; i++) {
        cargabin(i, cromo, camiones, 4);
        valido = true;
        //Verificamos que todos las tortugas tengan al menos 1 camion y que 
        //cumpla con la restriccion del peso
        for (int j = 0; j < 4; j++) {
            suma = cont = 0;
            for (int k = 0; k < camiones; k++) {
                if (cromo[k] == j) {
                    cont++;
                    suma += listas[k].pesoTotal;
                }

            }
            if (cont == 0 or suma > capacidades[j]) {
                valido = false;
                break;
            }
            //if(!valido) break;
        }

        if (valido) {
            cout << "Si hay solucion" << endl;
            for (int c = 0; c < camiones; c++) {
                cout << cromo[c] << " ";
                solucion[c] = cromo[c];
            }

            cout << endl;
            return true;
        }
    }
    delete cromo;
    return false;
}
//opcion 2 de mayor a menor, opcion 1 de menor a mayor
void ordernarPesos(Lista &lista, int opcion) {

    Nodo *ant = nullptr, *recorrido = lista.cabeza, *penultimo = nullptr;
    for (int i = 1; i < lista.longitud; i++) {
        ant = penultimo = nullptr;
        recorrido = lista.cabeza;
        while (recorrido != nullptr) {
            if (ant != nullptr) {
                if ((ant->elemento.numero > recorrido->elemento.numero and opcion == 1)
                        or ant->elemento.numero <= recorrido->elemento.numero and opcion == 2) {
                    if (penultimo == nullptr) {//ant es la cabeza
                        lista.cabeza = recorrido;
                    } else
                        penultimo->siguiente = recorrido;

                    ant->siguiente = recorrido->siguiente;
                    recorrido->siguiente = ant;

                    penultimo = recorrido;
                    recorrido = ant->siguiente;
                }
                else {
                    penultimo = ant;
                    ant = recorrido;
                    recorrido = recorrido->siguiente;
                }
            }
            else {
                ant = recorrido;
                recorrido = recorrido->siguiente;
            }
        }
    }


}

void unirListas(Lista &lista1, Lista lista2) {

    ordernarPesos(lista1, 1);
    ordernarPesos(lista2, 2);
    
    Nodo *ini = nullptr, *fin, *recorrido1 = lista1.cabeza, *recorrido2 = lista2.cabeza, 
            *ant = nullptr;
    int cont = 0;
    while(recorrido1 != nullptr and recorrido2 != nullptr){
        if(cont % 2 == 0){
            if(ini == nullptr){
                ini = recorrido1;
            }
            else{
                fin->siguiente = recorrido1;
            }
            
            fin = recorrido1;
            recorrido1 = recorrido1->siguiente;
        }
        else{
            if(ini == nullptr){
                ini = recorrido2;
            }
            else{
                fin->siguiente = recorrido2;
            }
            
            fin = recorrido2;
            recorrido2 = recorrido2->siguiente;
        }
        cont++;
    }
    if(recorrido1 == nullptr){
        fin->siguiente = recorrido2;
        while(recorrido2 != nullptr){
            ant = recorrido2;
            recorrido2 = recorrido2->siguiente;
        }
        fin = ant;
    }
    else{
        fin->siguiente = recorrido1;
        while(recorrido1 != nullptr){
            ant = recorrido1;
            recorrido1 = recorrido1->siguiente;
        }
        fin = ant;
    }
    lista1.cabeza = ini;
}

int main(int argc, char** argv) {

    Lista *listas;
    int capacidades[4]{}, camiones, *solucion, primero;

    leerDatos(listas, capacidades, camiones);
    solucion = new int[camiones] {
    };

    for (int i = 0; i < camiones; i++) {
        cout << listas[i].pesoTotal << endl;
        imprime(listas[i]);
    }

    if (buscarCombinacion(listas, capacidades, camiones, solucion)) {

        for (int i = 0; i < 4; i++) {
            primero = -1;
            for (int c = 0; c < camiones; c++) {
                if (solucion[c] == i) {
                    if (primero != -1 and !esListaVacia(listas[primero]) and
                            !esListaVacia(listas[c]))
                        unirListas(listas[primero], listas[c]);
                    else
                        primero = c;
                }
            }
            imprime(listas[i]);
        }
    }


    return 0;
}

