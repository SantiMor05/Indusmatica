/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 14 de mayo de 2025, 03:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

/*
 * 
 */

void rellenarGuerreros(struct Pila &robotKupa1, struct Pila &robotKupa2){
    Elemento aux1, aux2;
    
    aux1.poder = 27;
    aux2.poder = 20;
    apilar(robotKupa1, aux1);
    apilar(robotKupa2, aux2);
    
    aux1.poder = 30;
    aux2.poder = 68;
    apilar(robotKupa1, aux1);
    apilar(robotKupa2, aux2);
    
    aux1.poder = 56;
    aux2.poder = 22;
    apilar(robotKupa1, aux1);
    apilar(robotKupa2, aux2);
    
    aux1.poder = 15;
    aux2.poder = 45;
    apilar(robotKupa1, aux1);
    apilar(robotKupa2, aux2);
    
    aux1.poder = 85;
    apilar(robotKupa1, aux1);
}

void unirPilas(struct Pila &pila1, struct Pila &pila2){
    Elemento aux;
    //Pasar de pila 2 a pila 1 -> De robot 2 a robot 1
    while (!esPilaVacia(pila2)) {
        aux = desapilar(pila2);
        apilar(pila1, aux);
    }
}

void ordenarAtaques(struct Pila &pila, int longitud){
    Elemento min, valor, aux;
    int i = longitud - 1; //Es longitud - 1, porque ya se quita uno antes del while, y solo faltan longitud - 1 elementos más para comparar
    Pila pilaAux;
    construir(pilaAux);
    
    if(longitud == 0)return; //Condicion de parada
    
    min = desapilar(pila);
    while (i > 0) {
        valor = desapilar(pila);
        if(valor.poder < min.poder){ //Si es menor que el min anterior, se coloca el min anterior a la pilaAux //Y se actualiza el min
            apilar(pilaAux, min);
            min = valor;
        }
        else{
            apilar(pilaAux, valor); //Si no es menor, se coloca el valor en la pilaAux
        }
        i--;
    }
    apilar(pila, min); //Se coloca en la pila real el minimo encontrado en la iteracion
    while (!esPilaVacia(pilaAux)) { //Se vuelve a poner todos los de la pilaAux encima
        aux = desapilar(pilaAux);
        apilar(pila, aux);
    }
    ordenarAtaques(pila, longitud - 1); //Se manda a recursion para que haga el mismo proceso pero con longitud - 1, 
                                        //porque ya se ordenó un min
}

void pasaPilaAOtroMundo(struct Pila &pilaKupa, struct Pila &pilaChampi){
    Elemento der, izq;
    //pilaKupa = pilaOrigen / pilaChampi -> pilaDestino
    int cont;
    while (!esPilaVacia(pilaKupa)) {
        der = desapilar(pilaKupa); //Garantiza que se mantenga uno en la "mano derecha" (der)
        cont = 0;
        while (!esPilaVacia(pilaKupa)) { //Apila todo a la pila destino menos el ultimo
            apilar(pilaChampi, der);
            der = desapilar(pilaKupa);
            cont++;
        } //Der = Ultimo elemento pila Origen
        while (!esPilaVacia(pilaChampi) and cont > 0) { //Regresa todo a la pila origen con la "mano izquierda" (izq)
            izq = desapilar(pilaChampi);                //El cont garantiza que no se devuelva el elemento puesto (der) 
            apilar(pilaKupa, izq);                      //en la anterior iteracion porque ya queda fijo
            cont--;
        }
        apilar(pilaChampi, der); //Coloca en la pila destino el elemento de la "mano derecha" (der)
    }
}

int main(int argc, char** argv) {
    Pila pilaMundoKupa1, pilaMundoKupa2, pilaMundoChampinion;
    
    construir(pilaMundoKupa1);
    construir(pilaMundoKupa2);
    construir(pilaMundoChampinion);
    rellenarGuerreros(pilaMundoKupa1, pilaMundoKupa2);
    
    //Impresion robots
    cout<<"Robot Kupa 1: ";
    imprimir(pilaMundoKupa1);
    cout<<"Robot Kupa 2: ";
    imprimir(pilaMundoKupa2);
    cout<<"---------------------------"<<endl;
    
    //Pregunta a
    unirPilas(pilaMundoKupa1, pilaMundoKupa2);
    cout<<"Pila única: ";
    imprimir(pilaMundoKupa1);
    
    //Pregunta b
    ordenarAtaques(pilaMundoKupa1, longitud(pilaMundoKupa1));
    cout<<"Pila única ordenada: ";
    imprimir(pilaMundoKupa1);
    
    //Pregunta c
    pasaPilaAOtroMundo(pilaMundoKupa1, pilaMundoChampinion);
    cout<<"Pila en el mundo champiñón: ";
    imprimir(pilaMundoChampinion);
    
    return 0;
}

