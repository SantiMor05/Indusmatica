/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 21:29
 */

#include "Boleta.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Presencial.h"

Boleta::Boleta() {
    inicializa();
}

Boleta::Boleta(const Boleta& orig) {
}

Boleta::~Boleta() {
    if(pboleta != nullptr) delete pboleta;
}

void Boleta::asignaMemoria(char tipo){
    
    if(tipo == 'S')
        pboleta = new Semipresencial;
    else if(tipo == 'P')
        pboleta = new Presencial;
    else
        pboleta = new Virtual;
    
}

void Boleta::lee(ifstream &arch){
    pboleta->lee(arch);
}

void Boleta::inicializa(){
    pboleta = nullptr;
}

bool Boleta::operator <(const Boleta &boleta){
    int resultado = pboleta->GetCodigo() - boleta.pboleta->GetCodigo();
    
    if(resultado > 0) return true;
    else return false;
}

void Boleta::imprime(ofstream &arch){
    pboleta->imprime(arch);
}

int Boleta::obtenEscala(){
    
    return  pboleta->GetEscala();
    
}

void Boleta::actualizatotal(double escala){
    
    pboleta->actualizatotal(escala);
    
}