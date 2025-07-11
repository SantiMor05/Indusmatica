/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: Lenovo
 * 
 * Created on 8 de julio de 2025, 05:27 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesAuxiliares.h"
#include "funcionesABB.h"
#include "ArbolBB.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesAB.h"
#include "ArbolB.h"
#include "NodoArbol.h"
#include "funcionesLista.h"
#include <cmath>
#include <stack> 
#include <string> 
#include <cstring>
#include <ratio> 
using namespace std;



////////////////////////////////////////////////////////////////////////////////PREGUNTA 1

void clonarPila(Pila &origen, Pila &clon){
    if(esPilaVacia(origen))return; 
    Elemento elemento = desapilar(origen);
    clonarPila(origen, clon);
    apilar(clon, elemento);
    apilar(origen, elemento);
}
void pregunta1(){
    Pila pila, pila2;
    construir(pila);
    construir(pila2);
    
    Elemento temp;
    for (int i = 1; i <= 7; i++) {
        temp.numero = i;
        apilar(pila, temp);
    }
    
    cout << "Pila 1: "; 
    imprimir(pila);
    cout << endl;
    cout << "Pila 2: "; 
    imprimir(pila2);
    cout << endl;
    
    clonarPila(pila, pila2);
    cout << "YA CLONADOS " << endl << endl;
    cout << "Pila 1: "; 
    imprimir(pila);
    cout << endl;
    cout << "Pila 2: "; 
    imprimir(pila2);
    cout << endl;
    
}

////////////////////////////////////////////////////////////////////////////////PREGUNTA 2

/*Archivo de texto
180
120
250
100
150
230
280
80
140
160
200
240
260
90
 */

void cargarDatos(ArbolBinarioBusqueda &arbol){
    ifstream arch("Emociones.txt", ios::in);
    if(not arch.is_open()){
        cout << "ERROR " << endl;
        exit(1);
    }
    
    Elemento temp;
    while (true) {
        arch>>temp.numero;
        if(arch.eof())break;
        insertar(arbol, temp);
    }

}


NodoArbol *buscarNodo(NodoArbol *pArbol, int numero){
    if(esNodoVacio(pArbol))return pArbol;
    if(pArbol->elemento.numero == numero)return pArbol;
    if(pArbol->elemento.numero < numero){
        return buscarNodo(pArbol->derecha, numero);
    }
    else{
        return buscarNodo(pArbol->izquierda, numero);
    }
}

//NodoArbol *buscarNodoIterativo(NodoArbol *pArbol, int numero){
//    if(pArbol == nullptr)return nullptr;
//    
//    while (pArbol) {
//        if(pArbol->elemento.numero == numero)return pArbol;
//        if(pArbol->elemento.numero < numero){
//            pArbol = pArbol->derecha;
//        }
//        else{
//            pArbol = pArbol->izquierda;
//        }
//    }
//    return pArbol;
//}


bool analizarHijos(NodoArbol *pRec, string *emociones, int pesos[][3], string combinacion[3], int numEmocion){
    if(pRec == nullptr)return false;
    if(numEmocion >= 3)return true;
    
    bool encontrada = false;
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
            if(pesos[i][j] == pRec->elemento.numero){
                if(emociones[i] == combinacion[numEmocion]){
                    encontrada = true;
                    break;   
                }
            }
        }
        if(encontrada)break;
    }

    return encontrada or analizarHijos(pRec->izquierda, emociones, pesos, combinacion, numEmocion + 1) or analizarHijos(pRec->derecha, emociones, pesos, combinacion, numEmocion + 1); 
    return analizarHijos(pRec->izquierda, emociones, pesos, combinacion, numEmocion + 1) or analizarHijos(pRec->derecha, emociones, pesos, combinacion, numEmocion + 1); 
}


int analizarCombinacion(NodoArbol *pRec, string *emociones, int pesos[][3], string combinaciones[][3], int nivelActual, int numEmocion){
    int cant = 0;
    for (int i = 0; i < 3; i++) { // Para cada combinación
        string emocion1 = combinaciones[i][0]; //Se recorren todas las combinaciones (i = 0 a i = 2), independientemente de que una ya haya coincidido.
        
        // Verifica si el nodo actual corresponde a emoción1
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 3; k++) { //
                if(pesos[j][k] == pRec->elemento.numero and emociones[j] == emocion1) {
                    if(analizarHijos(pRec->izquierda, emociones, pesos, combinaciones[i], 1) or 
                       analizarHijos(pRec->derecha, emociones, pesos, combinaciones[i], 1)) {
                        cant++;
                        //Analizar sus hijos porque si no se vuelve a contar el mismo nodo
                    }
                }
            }
        }
    }
    return cant;  
}



void analizarCombinaciones(ArbolBinarioBusqueda arbol, string *emociones, int pesos[][3], string combinaciones[][3]){
    if(esArbolVacio(arbol.arbolBinario))return;
    
    NodoArbol *pRec = arbol.arbolBinario.raiz;
    
    Cola cola;
    construir(cola);
    
    Elemento temp;
    encolar(cola, pRec->elemento);
    int tamano;
    int nivelActual = 0;
    int alt = altura(arbol.arbolBinario);
    
    int cantComb[10]{}; //El arreglo deberia ser con el numero de combinaciones dadas xd
    
    bool sePuede;
    while (!esColaVacia(cola)) { //Recorrido en amplitud (BFS)
        tamano = longitud(cola.lista);
        //cout << "Nivel " << nivelActual << ": ";
        sePuede = false;
        
        for (int i = 0; i < tamano; i++) {
            temp = desencolar(cola);
            pRec = buscarNodo(arbol.arbolBinario.raiz, temp.numero);
            
            if(pRec->izquierda)encolar(cola, pRec->izquierda->elemento);
            if(pRec->derecha)encolar(cola, pRec->derecha->elemento);
            
            if(numeroNodosRecursivo(pRec->izquierda) >= 2 or numeroNodosRecursivo(pRec->derecha) >= 2){
                cantComb[nivelActual] += analizarCombinacion(pRec, emociones, pesos, combinaciones, nivelActual, 0);
                sePuede = true;
            }
        }
        
        if(sePuede){ //Si al menos uno del nivel cumple con la combinacion
            cout << "Nivel " << nivelActual << ": " << cantComb[nivelActual] << " combinaciones";
        }
        else{
            break;
        }
        nivelActual++;
        cout << endl;

    }

}

void analizarArbol(ArbolBinarioBusqueda arbol, string *emociones, int pesos[][3], string combinaciones[][3]){
    if(esArbolVacio(arbol.arbolBinario))return;
    
    cout << endl << endl;
    
    analizarCombinaciones(arbol, emociones, pesos, combinaciones);
}

void pregunta2(){
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    cargarDatos(arbol);
    
    recorrerEnOrden(arbol.arbolBinario);

    string emociones[9] = {
                            "Alegría",      // 0
                            "Tristeza",     // 1
                            "Temor",        // 2
                            "Furia",        // 3
                            "Desagrado",    // 4
                            "Ansiedad",     // 5
                            "Envidia",      // 6
                            "Vergüenza",    // 7
                            "Aburrimiento"};  // 8
                        
    int numEmociones = 9;
    int pesos[numEmociones][3] = {{180, 200, -1},    // Alegría
                                  {140, 230, 80},   // Tristeza
                                  {240, 100, -1},    // Temor
                                  {280, -1,  -1},    // Furia
                                  {250, -1,  -1},    // Desagrado
                                  {260, 120, -1},    // Ansiedad
                                  {160, 240, -1},    // Envidia
                                  {120,  80, -1},    // Vergüenza
                                  {150, 230,  90}};  // Aburrimiento
                                
    
    
    int numComb = 3, cantEmocionXCOmb = 3;
    
//    string combinaciones[numComb][3] = {
//                                                    {"Ansiedad", "Aburrimiento", "Tristeza"},
//                                                    {"Desagrado", "Tristeza", "Temor"},
//                                                    {"Temor", "Vergüenza", "Aburrimiento"}
//                                                };
//    string combinaciones[numComb][3] = {
//                                                    {"Alegría", "Desagrado", "Furia"},
//                                                    {"Alegría", "Desagrado", "Aburrimiento"},
//                                                    {"Alegría", "Vergüenza", "Aburrimiento"}
//                                                };
//    string combinaciones[numComb][3] = {
//                                                    {"Ansiedad", "Aburrimiento", "Envidia"},
//                                                    {"Temor", "Hola", "Tristeza"},
//                                                    {"Desagrado", "Tristeza", "Temor"}
//                                                };
    
//    string combinaciones[numComb][3] = {
//                                                    {"Ansiedad", "Aburrimiento", "Envidia"},
//                                                    {"Aburrimiento", "Hola", "Tristeza"},
//                                                    {"Desagrado", "Tristeza", "Temor"}
//                                                };


    //Mas ejemplos

//    string combinaciones[3][3] = {//NIVEL 0: 1
//                                    {"Ansiedad", "Aburrimiento", "Envidia"},   
//                                    {"Desagrado", "Tristeza", "Temor"},        
//                                    {"Alegría", "Desagrado", "Furia"}          
//                                };
//    string combinaciones[3][3] = {//NIVEL 1: 1
//                                    {"Temor", "Vergüenza", "Aburrimiento"},    
//                                    {"Aburrimiento", "Hola", "Tristeza"},      
//                                    {"Ansiedad", "Tristeza", "Furia"}          
//                                };
    
//    string combinaciones[3][3] = {Nivel 1: 1 - Nivel 2: 2
//                                    {"Alegría", "Desagrado", "Furia"},         
//                                    {"Ansiedad", "Vergüenza", "Tristeza"},     //--Considera nieto xd
//                                    {"Desagrado", "Tristeza", "Temor"}         
//                                };

//    string combinaciones[3][3] = {//NINGUNA
//                                    {"Tristeza", "Aburrimiento", "Alegría"},   
//                                    {"Temor", "Envidia", "Desagrado"},         
//                                    {"Desagrado", "Hola", "Tristeza"}          
//                                };
//    string combinaciones[3][3] = { //Nivel 1: 3
//                                    {"Ansiedad", "Aburrimiento", "Envidia"},
//                                    {"Ansiedad", "Aburrimiento", "Envidia"},
//                                    {"Desagrado", "Tristeza", "Temor"}
//                                };
//    
//    string combinaciones[3][3] = {
//                                    {"Desagrado", "Aburrimiento", "Alegría"},
//                                    {"Vergüenza", "Temor", "Tristeza"},
//                                    {"Aburrimiento", "Envidia", "Alegría"}
//                                };
    
    
    //Ejemplo del examen
    string combinaciones[numComb][3] = {
                                        {"Ansiedad", "Aburrimiento", "Tristeza"},
                                        {"Desagrado", "Tristeza", "Temor"},
                                        {"Temor", "Vergüenza", "Aburrimiento"}
                                       };
    analizarArbol(arbol, emociones, pesos, combinaciones);
    

}

/*
                             180
 *                  /                   \
 *                120                        250
 *              /    \                     /      \
 *          100       150               230        280
 *          /         /   \           /   \         /
 *        80        140  160        200    240    260
 *        /  
 *       90 
 
 */



////////////////////////////////////////////////////////////////////////////////Pregunta 3B

void insertarFin(Lista &lista, Elemento elemento){
    //Lista circular
    Nodo *nuevo = crearNodo(elemento, nullptr);
    nuevo->siguiente = nullptr;
    
    
    if(esListaVacia(lista)){
        lista.cabeza = nuevo;
        lista.cabeza->siguiente = lista.cabeza;
    }
    else{
        Nodo *temp = lista.cabeza;
        while (temp->siguiente != lista.cabeza) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
        nuevo->siguiente = lista.cabeza;

    }
}

int eliminarKth(Lista &lista, int k){
    Nodo *actual = lista.cabeza;
    Nodo *ant = nullptr;
    int contador = 1;
    while (actual->siguiente != actual) {
        if(contador == k){
            cout << "El siguiente empleado que se eliminaría sería el número " << actual->elemento.numero << endl;
            ant->siguiente = actual->siguiente;
            delete actual;
            actual = ant->siguiente;
            contador = 1;
        }
        else{
            ant = actual;
            actual = actual->siguiente;
            contador++;
        }
    }
    int ultimo = actual->elemento.numero;
    delete actual;
    return ultimo;

}
void pregunta3B(){
    Lista lista;
    construir(lista);
    
    int n = 7, k = 3;
    Elemento temp;
    
    for (int i = 1; i <= n; i++) {
        temp.numero = i;
        insertarFin(lista, temp);
    }
    
    int elegido = eliminarKth(lista, k);
    

    cout << "-----------------------------------------------------------" << endl;
    cout << "En una lista de " << n << " empleados, para k = " << k << endl;
    cout << "El elegido es: " << elegido << endl;
    
}
