/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesListas.cpp
 * Author: Usuario
 * 
 * Created on 2 de mayo de 2025, 08:41 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <memory>
using namespace std;

#include "FuncionesListas.h"
#include "Elemento.h"
#include "Lista.h"
#include "Nodo.h"

void crearLista(struct Lista &lista) {
    lista.cabeza = nullptr;
    lista.cola = nullptr;
    lista.longitud = 0;
}

void insertar_al_final(struct Lista &lista, int num) {

    struct Elemento elemento;
    elemento.peso = num;

    struct Nodo *nuevoNodo = crearNodo(elemento, nullptr);

    if (lista.cabeza == nullptr) {
        lista.cabeza = nuevoNodo;
    } else 
        lista.cola->siguiente = nuevoNodo;
    lista.cola = nuevoNodo;
    lista.longitud++;
}

struct Nodo *crearNodo(Elemento &elemento, Nodo *siguiente) {
    Nodo *nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->siguiente = siguiente;
    return nuevo;
}

void imprimirLista(Lista lista){
    if(lista.cabeza==nullptr){
        cout<<"NO HAY DATOS";
    }
    else{
        Nodo *recorrido = lista.cabeza;
        for (int i = 0; i < lista.longitud; i++) {
            if(i ==0) cout << '[';
            cout << recorrido->elemento.peso;
            if(recorrido->siguiente != nullptr) cout << ',';
            recorrido = recorrido->siguiente;
        }
        cout << ']' << endl;
    }

}