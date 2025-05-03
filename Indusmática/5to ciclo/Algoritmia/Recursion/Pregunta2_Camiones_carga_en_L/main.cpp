/* 
 * File:   main.cpp
 * Author: Farid Oswaldo
 *
 * Created on 2 de mayo de 2025, 07:09 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#define N 6
#include "Lista.h"
#include "FuncionesListas.h"

/*
 * 
 */

void reiniciarRuta(Lista lista) {
    struct Nodo *recor = lista.cabeza;
    for (int i = 0; i < lista.longitud; i++) {
        recor->elemento.Atendido = false;
        recor = recor->siguiente;
    }
}

void buscarPedido(Lista lista, int valor) {
    struct Nodo *recor = lista.cabeza;
    for (int i = 0; i < lista.longitud; i++) {
        if (recor->elemento.peso == valor and !recor->elemento.Atendido) {
            recor->elemento.Atendido = true;
            break;
        }
        recor = recor->siguiente;
    }
}

bool validarRuta(Lista lista) {
    struct Nodo *recor = lista.cabeza;
    for (int i = 0; i < lista.longitud; i++) {
        if (!recor->elemento.Atendido) return false;
        recor = recor->siguiente;
    }
    return true;
}

void verificarPedidos(Lista &lista, int mapa [][N], int x, int y, int tam, int ruta, bool &verifica) {
    if (x < 0 or y < 0 or x >= N or y >= N or tam == 1) return;

    int valor = mapa[x][y];
    buscarPedido(lista, valor);


    if (!validarRuta(lista)) {
        if (y + 1 < tam) {
            verificarPedidos(lista, mapa, x, y + 1, tam, ruta, verifica);
        } else {
            verificarPedidos(lista, mapa, x + 1, y, tam, ruta, verifica);
        }
        if (y == 0) {
            verificarPedidos(lista, mapa, x + 1, y, tam - 1, ruta + 1, verifica);
        }
    } else verifica = true;
    if (x == N - 1)reiniciarRuta(lista);
}

int calcularMayorRuta(int mapa[][N], int x, int y, int tam, int &maxRuta, int ruta) {
    if (x < 0 or y < 0 or x >= N or y >= N or tam == 1) return 0;
    int valor = mapa[x][y];


    int aux;

    if (y + 1 < tam) {
        valor += calcularMayorRuta(mapa, x, y + 1, tam, maxRuta, ruta);
    } else {
        valor += calcularMayorRuta(mapa, x + 1, y, tam, maxRuta, ruta);
    }

    if (y == 0) {

        aux = calcularMayorRuta(mapa, x + 1, y, tam - 1, maxRuta, ruta + 1);
        if (aux > valor) {
            valor = aux;
            maxRuta = ruta + 1;
        } else maxRuta = ruta;
    }
    return valor;
}

int mapa[N][N] = {
    {1, 2, 9, 1, 2, 3},
    {5, 1, 7, 0, 2, 1},
    {0, 7, 0, 3, 8, 1},
    {1, 2, 6, 1, 2, 2},
    {0, 6, 9, 5, 0, 5},
    {0, 0, 4, 0, 9, 0}
};

int main(int argc, char** argv) {
    int max = 0;
    int maxruta = 0;
    max = calcularMayorRuta(mapa, 0, 0, N, maxruta, 1);
    cout << "El peso maximo es " << max << " en la ruta " << maxruta << endl;

    Lista lista;

    crearLista(lista);

    int cant, dato;
    cout << "Ingrese la cantidad de productos: ";
    cin>>cant;
    for (int i = 0; i < cant; i++) {
        cout << "Ingrese el dato: ";
        cin>>dato;
        insertar_al_final(lista, dato);
    }
    cout << "Lista = ";
    imprimirLista(lista);

    bool atendido = false;
    verificarPedidos(lista, mapa, 0, 0, N, 1, atendido);

    if (atendido) {
        cout << "Si se pudo atender" << endl;
    } else cout << "No se pudo atender" << endl;
    
    return 0;
}

