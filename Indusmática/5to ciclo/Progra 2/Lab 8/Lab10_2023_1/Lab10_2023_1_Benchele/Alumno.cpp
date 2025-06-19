/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Lenovo
 * 
 * Created on 18 de junio de 2025, 03:02 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Alumno.h"
using namespace std;

Alumno::Alumno() {
    inicializa();
}

Alumno::Alumno(const Alumno& orig) {
    inicializa();
    *this = orig;
}

Alumno::~Alumno() {
    if(nombre != nullptr)delete nombre;
}


void Alumno::setTotal(double total) {
    this->total = total;
}

double Alumno::getTotal() const {
    return total;
}

void Alumno::setCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::getCreditos() const {
    return creditos;
}

void Alumno::setEscala(int escala) {
    this->escala = escala;
}

int Alumno::getEscala() const {
    return escala;
}

void Alumno::setNombre(const char* nomb) {
    if(nombre != nullptr)delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Alumno::getNombre(char*nomb) const {
    if(nombre == nullptr)nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Alumno::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::getCodigo() const {
    return codigo;
}

void Alumno::inicializa(){
    nombre = nullptr;
    total = 0.0;
}
void Alumno::operator =(const class Alumno &orig){
    char aux[60];
    orig.getNombre(aux);
    setNombre(aux);
    codigo = orig.codigo;
    escala = orig.escala;
    creditos = orig.creditos;
    total = orig.total;
}

/*
 S,202123703,GAMARRA/TABORI/PAUL-RONAL,5,20,30
 P,202119153,MENDOZA/ARIAS/HENRY,4,19.5,10
 */
void Alumno::lee(ifstream &arch){
    char aux[60];
    
    arch>>codigo;
    //if(arch.eof())return;
    arch.get();
    arch.getline(aux, 60, ',');
    setNombre(aux);
    arch>>escala;
    arch.get();
    arch>>creditos;
    arch.get();
}

void Alumno::imprime(ofstream &arch){
    arch<<left<<setw(10)<<codigo<<setw(5)<<" "<<setw(40)<<nombre<<right<<setw(3)<<escala<<setw(14)<<creditos;
}

void Alumno::actualiza(double pago){
    total = pago;
}