/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plato.cpp
 * Author: kenyi
 * 
 * Created on 3 de junio de 2025, 05:17 PM
 */

#include <cstring>
#include <iomanip>
using namespace std;
#include "Plato.h"

Plato::Plato() {
    inicializa();
}

Plato::Plato(const Plato& orig) {
    inicializa();
    *this = orig;
}

Plato::~Plato() {
    elimina();
}

void Plato::inicializa() {
    categoria = nullptr;
    codigo = nullptr;
    nombre = nullptr;
    atendidos = 0;
    noAtendidos = 0;
    totalBruto = 0;
    totalEsperado = 0;
    totalNeto = 0;
}

void Plato::elimina() {
    if (categoria != nullptr)delete categoria;
    if (codigo != nullptr)delete codigo;
    if (nombre != nullptr)delete nombre;
}

void Plato::operator=(const Plato& orig) {
    char aux[100];
    atendidos = orig.atendidos;
    descuento = orig.descuento;
    noAtendidos = orig.noAtendidos;
    precio = orig.precio;
    preparados = orig.preparados;
    totalBruto = orig.totalBruto;
    totalEsperado = orig.totalEsperado;
    totalNeto = orig.totalNeto;
    orig.getCategoria(aux);
    setCategoria(aux);
    orig.getNombre(aux);
    setNombre(aux);
    orig.getCodigo(aux);
    setCodigo(aux);
}

void Plato::setTotalNeto(double totalNeto) {
    this->totalNeto = totalNeto;
}

double Plato::getTotalNeto() const {
    return totalNeto;
}

void Plato::setTotalBruto(double totalBruto) {
    this->totalBruto = totalBruto;
}

double Plato::getTotalBruto() const {
    return totalBruto;
}

void Plato::setTotalEsperado(double totalEsperado) {
    this->totalEsperado = totalEsperado;
}

double Plato::getTotalEsperado() const {
    return totalEsperado;
}

void Plato::setNoAtendidos(int noAtendidos) {
    this->noAtendidos = noAtendidos;
}

int Plato::getNoAtendidos() const {
    return noAtendidos;
}

void Plato::setAtendidos(int atendidos) {
    this->atendidos = atendidos;
}

int Plato::getAtendidos() const {
    return atendidos;
}

void Plato::setDescuento(double descuento) {
    this->descuento = descuento;
}

double Plato::getDescuento() const {
    return descuento;
}

void Plato::setPreparados(int preparados) {
    this->preparados = preparados;
}

int Plato::getPreparados() const {
    return preparados;
}

void Plato::setCategoria(const char* cat) {
    if (categoria != nullptr)delete categoria;
    categoria = new char[strlen(cat) + 1];
    strcpy(categoria, cat);
}

void Plato::getCategoria(char* cat) const {
    if (categoria == nullptr)cat[0] = 0;
    else strcpy(cat, categoria);
}

void Plato::setPrecio(double precio) {
    this->precio = precio;
}

double Plato::getPrecio() const {
    return precio;
}

void Plato::setNombre(const char* nomb) {
    if (nombre != nullptr)delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Plato::getNombre(char* nomb) const {
    if (nombre == nullptr)nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Plato::setCodigo(const char* cod) {
    if (codigo != nullptr)delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Plato::getCodigo(char*cod) const {
    if (codigo == nullptr)cod[0] = 0;
    else strcpy(cod, codigo);
}

void operator>>(ifstream &arch, Plato &plato) {
    char aux[100];
    int num;
    double desc = 0, precio;
    arch.getline(aux, 100, ',');
    if (arch.eof())return;
    plato.setCodigo(aux);
    arch.getline(aux, 100, ',');
    plato.setNombre(aux);
    arch>>precio;
    arch.get();
    plato.setPrecio(precio);
    arch.getline(aux, 100, ',');
    plato.setCategoria(aux);
    arch>>num;
    plato.setPreparados(num);
    if (arch.get() == ',') {
        arch>>desc;
        arch.get();
        arch.get();
    }
    plato.setDescuento(desc);
    plato.setTotalEsperado(precio * num);
}

void Plato::modifica(int aten, int noAten, double desc) {
    atendidos += aten;
    noAtendidos += noAten;
    totalBruto += aten*precio;
    totalNeto += precio * aten * (1 - descuento / 100.0)*(1 - desc / 100.0);
}

void operator<<(ofstream &arch, Plato &plato) {
    char cod[8], nomb[60], cat[20];
    arch.precision(2);
    arch << fixed;
    plato.getCodigo(cod);
    plato.getNombre(nomb);
    plato.getCategoria(cat);
    arch << left << setw(10) << cod << setw(47) << nomb << right << setw(9)
            << plato.getPrecio() << "   " << left << setw(12) << cat << right
            << setw(7) << plato.getDescuento() << '%' << setw(10) << plato.getPreparados()
            << setw(11) << plato.getAtendidos() << setw(12) << plato.getNoAtendidos()
            << setw(14) << plato.getTotalEsperado() << setw(10) << plato.getTotalBruto()
            << setw(10) << plato.getTotalNeto() << endl;
}







