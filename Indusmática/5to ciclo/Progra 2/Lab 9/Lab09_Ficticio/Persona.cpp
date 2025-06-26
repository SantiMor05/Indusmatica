//
// Created by kenyi on 22/06/2025.
//


#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

#include "Persona.h"

int Persona::get_edad() const {
    return Edad;
}

void Persona::set_edad(int edad) {
    Edad = edad;
}

void Persona::get_nombre(char *nomb) const {
    if (Nombre==nullptr)nomb[0]=0;
    else strcpy(nomb,Nombre);
}

void Persona::set_nombre(const char *nomb) {
    if (Nombre!=nullptr)delete Nombre;
    Nombre = new char[strlen(nomb)+1];
    strcpy(Nombre,nomb);
}

void Persona::get_apellido(char * apell) const {
    if (apellido==nullptr)apell[0]=0;
    else strcpy(apell,apellido);
}

void Persona::set_apellido(const char *apell) {
    if (apellido!=nullptr)delete apellido;
    apellido = new char[strlen(apell)+1];
    strcpy(apellido,apell);
}

int Persona::get_codigo() const {
    return codigo;
}

void Persona::set_codigo(int codigo) {
    this->codigo = codigo;
}

Persona::Persona() {
    inicializa();
}

Persona::Persona(const Persona &orig) {
    inicializa();
    *this = orig;
}

Persona::~Persona() {
    if (apellido != nullptr)delete apellido;
    if (Nombre != nullptr)delete Nombre;
}

void Persona::inicializa() {
    apellido = nullptr;
    Nombre = nullptr;
}

void Persona::imprime(ostream &out) const {
    out << left << setw(40) << strcat(strcat(Nombre," "),apellido) << setw(20) << Edad << setw(16)
            << codigo << endl;
}


void operator<<(ostream &out, const Persona &persona) {
    persona.imprime(out);
}
