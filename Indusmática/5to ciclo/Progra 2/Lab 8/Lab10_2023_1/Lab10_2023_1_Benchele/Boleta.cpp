/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Boleta.cpp
 * Author: Lenovo
 * 
 * Created on 18 de junio de 2025, 03:06 PM
 */

#include <iostream>
#include <iomanip>
#include "Boleta.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
using namespace std;

Boleta::Boleta() {
    pBoleta = nullptr;
}

Boleta::~Boleta() {
    if(pBoleta != nullptr)delete pBoleta;
}

void Boleta::inicializa(){
    pBoleta = nullptr;
}

void Boleta::asignaMemoria(char tipo){
    switch(tipo){ //Crea los espacios de memoria segun la clase que corresponde, esto ayuda al polimorfismo ...(*)
        case 'P':
            pBoleta = new class Presencial;
            break;
        case 'S':
            pBoleta = new class Semipresencial;
            break;
        case 'V':
            pBoleta = new class Virtual;
            break;
    }
}


void Boleta::lee(ifstream &arch){
    pBoleta->lee(arch); //Polimorfismo
    //Como el espacio de memoria ya está creado desde antes ...(*), sabe a que metodo de que clase ir
}

void Boleta::actualiza(double precEsc){
    pBoleta->actualiza(precEsc); //Polimorfismo
}


void Boleta::imprime(ofstream &arch)const{
    pBoleta->imprime(arch); //Polimorfismo
}
    


int Boleta::GetEscala() const{
    return pBoleta->getEscala();
}

int Boleta::GetCodigo() const{
    return pBoleta->getCodigo();
}

bool Boleta::operator >(const class Boleta &dato) const{
    return dato.GetCodigo() < pBoleta->getCodigo() ;
}

void operator >>(ifstream &arch, class Boleta &boleta){
    boleta.lee(arch);
}
void operator <<(ofstream &arch, const class Boleta &boleta){
    boleta.imprime(arch);
}
