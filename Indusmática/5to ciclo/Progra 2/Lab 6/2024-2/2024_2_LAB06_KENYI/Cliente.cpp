/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: kenyi
 * 
 * Created on 3 de junio de 2025, 05:17 PM
 */

#include "Cliente.h"
#include <cstring>
#include <iomanip>
using namespace std;

Cliente::Cliente() {
    inicializa();
}

Cliente::Cliente(const Cliente& orig) {
    inicializa();
    *this = orig;
}

Cliente::~Cliente() {
    elimina();
}

void Cliente::inicializa() {
    descuento = 0;
    distrito = nullptr;
    nombre = nullptr;
    totalPagado = 0;
}

void Cliente::elimina() {
    if (nombre != nullptr)delete nombre;
    if (distrito != nullptr)delete distrito;
}

void Cliente::operator=(const Cliente& orig) {
    char aux[100];
    dni = orig.dni;
    descuento = orig.descuento;
    totalPagado = orig.totalPagado;
    orig.getDistrito(aux);
    setDistrito(aux);
    orig.getNombre(aux);
    setNombre(aux);
}

void Cliente::setTotalPagado(double totalPagado) {
    this->totalPagado = totalPagado;
}

double Cliente::getTotalPagado() const {
    return totalPagado;
}

void Cliente::setDescuento(double descuento) {
    this->descuento = descuento;
}

double Cliente::getDescuento() const {
    return descuento;
}

void Cliente::setDistrito(const char* dist) {
    if (distrito != nullptr)delete distrito;
    distrito = new char[strlen(dist) + 1];
    strcpy(distrito, dist);
}

void Cliente::getDistrito(char* dist) const {
    if (distrito == nullptr)dist[0] = 0;
    else strcpy(dist, distrito);
}

void Cliente::setNombre(const char* nomb) {
    if (nombre != nullptr)delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Cliente::getNombre(char* nomb) const {
    if (nombre == nullptr)nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Cliente::setDni(int dni) {
    this->dni = dni;
}

int Cliente::getDni() const {
    return dni;
}

void operator>>(ifstream &arch, Cliente &cliente) {
    int dni;
    double descuento = 0;
    char aux[100];
    arch>>dni;
    if (arch.eof())return;
    arch.get();
    cliente.setDni(dni);
    arch.getline(aux, 100, ',');
    cliente.setNombre(aux);
    arch.getline(aux, 100, ',');
    cliente.setDistrito(aux);
    if (arch.get() == 'S') {
        arch.get();
        arch>>descuento;
        arch.get();
        cliente.setDescuento(descuento);
    }
}

void Cliente::modifica(int aten, double prec, double desc) {
    totalPagado += prec * aten * (1 - descuento / 100.0)*(1 - desc / 100.0);
}

void operator<<(ofstream &arch, Cliente &cliente) {
    char nomb[100], dist[100];
    arch.precision(2);
    arch << fixed;
    cliente.getNombre(nomb);
    cliente.getDistrito(dist);
    arch << setw(9) << cliente.getDni() << " " << left << setw(40) << nomb <<
            setw(60) << dist << right << setw(8) << cliente .getDescuento()
            << '%' << setw(18) << cliente.getTotalPagado() << endl;
}