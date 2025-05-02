/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 2 de mayo de 2025, 17:15
 */

#include <cstdlib>

using namespace std;
#include "ELEMENTO.h"
#include "NODO.h"
#include "LISTA.h"
#include "FuncionesLista.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Lista lista1, lista2, lista3, lista4, lista5;
    construirLista(lista1);
    insertarOrdenado(lista1,1,8,6);
    insertarOrdenado(lista1,1,10,14);
    insertarOrdenado(lista1,1,12,1);
    imprimeLista(lista1);
    
     construirLista(lista2);
    insertarOrdenado(lista2,2,9,3);
    insertarOrdenado(lista2,2,11,8);
    imprimeLista(lista2);
    
    construirLista(lista3);
    insertarOrdenado(lista3,3,8,2);
    insertarOrdenado(lista3,3,9,5);
    insertarOrdenado(lista3,3,10,10);
    imprimeLista(lista3);
    
    construirLista(lista4);
    insertarOrdenado(lista4,4,14,13);
    insertarOrdenado(lista4,4,15,9);
    insertarOrdenado(lista4,4,16,11);
    imprimeLista(lista4);
    
    construirLista(lista5);
    insertarOrdenado(lista5,5,17,4);
    insertarOrdenado(lista5,5,18,12);
    insertarOrdenado(lista5,5,19,7);
    imprimeLista(lista5);
    
    Fusion(lista1,lista2);
    Fusion(lista1,lista3);
    Fusion(lista1,lista4);
    Fusion(lista1,lista5);
    imprimeLista(lista1);
    return 0;
}

