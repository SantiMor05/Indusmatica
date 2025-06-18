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

void Boleta::asignaPresencial(){
    pBoleta = new class Presencial;
}
void Boleta::asignaSemipresencial(){
    pBoleta = new class Semipresencial;
}
void Boleta::asignaVirtual(){
    pBoleta = new class Virtual;
}


void Boleta::lee(ifstream &arch){
    pBoleta->lee(arch); //Polimorfismo
    //Como el espacio de memoria ya está creado desde antes ...(*), sabe a que metodo de que clase ir
}

void Boleta::imprime(ofstream &arch){
    pBoleta->imprime(arch); //Polimorfismo
}
    
bool Boleta::ultimo(){
    return pBoleta == nullptr;
}

int Boleta::GetEscala(){
    return pBoleta->getEscala();
}

void Boleta::actualiza(double monto){
    pBoleta->actualiza(monto); //Polimorfismo
}