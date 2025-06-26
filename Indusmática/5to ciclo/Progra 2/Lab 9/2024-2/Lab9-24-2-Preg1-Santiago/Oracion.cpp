/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Oracion.cpp
 * Author: santi
 * 
 * Created on 24 de junio de 2025, 22:37
 */

#include "Oracion.h"
#include <iostream>
using namespace std;

Oracion::Oracion() {
    inicializa();
}
//
//Oracion::Oracion(const Oracion& orig) {
////    inicializa();
////    *this = orig;
//}

Oracion::~Oracion() {
}

void Oracion::SetCantidad_palabras(int cantidad_palabras) {
    this->cantidad_palabras = cantidad_palabras;
}

int Oracion::GetCantidad_palabras() const {
    return cantidad_palabras;
}

void Oracion::SetPolaridad_total(int polaridad_total) {
    this->polaridad_total = polaridad_total;
}

int Oracion::GetPolaridad_total() const {
    return polaridad_total;
}

void Oracion::inicializa(){
    cantidad_palabras = 0;
    polaridad_total = 0;
}


void Oracion::imprimir(){
    cout << "Hola " <<  cantidad_palabras<< endl;
}

void Oracion::operator =(const Oracion& orig){
    
    cantidad_palabras = orig.cantidad_palabras;
    polaridad_total = orig.polaridad_total;
    
}


void Oracion::dividirPalabras(string &comentario,  map <string, int> &lexicon){
    
//    int pos = -1; Cuando pongo esto no entra al while no c xq
    int pos = 0, pos_ant = 0;
    int longitud, cont;
    int polaridad;
    string cadena;
    Palabra palabra;
   // cout  << comentario.size() << endl;
    while(pos < comentario.size()){
        if(pos == 0)
            pos = comentario.find(' ', pos);
        else
            pos = comentario.find(' ', pos + 1);
        
        longitud = pos - pos_ant;
        cadena = comentario.substr(pos_ant, longitud);
        if(cadena.size() > 0){
            palabra.SetTexto(cadena);
            cont = lexicon.count(cadena);
            if(cont != 0){
                polaridad = lexicon[cadena];
            }
            else polaridad = 0;
            polaridad_total += polaridad;
            palabra.SetPolaridad(polaridad);
            cantidad_palabras++;
            palabras.push_back(palabra);
        }
        
        
        pos_ant = pos + 1;
        if(pos == 0) pos++;
    }
    
}