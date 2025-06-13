/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Restaurante.cpp
 * Author: kenyi
 * 
 * Created on 3 de junio de 2025, 05:19 PM
 */

#include <string.h>

#include "Restaurante.h"


#define INCREMENTO 5
#define NO_ENCONTRADO -1

Restaurante::Restaurante() {
    inicializa();
}

Restaurante::~Restaurante() {
    elimina();
}

int Restaurante::inicializa() {
    clientes = nullptr;
    cantidadDeClientes = 0;
    capacidadDeClientes = 0;
    platos = nullptr;
    cantidadDePlatos = 0;
    capacidadDePlatos = 0;
}

int Restaurante::elimina() {
    if (clientes != nullptr)delete []clientes;
    if (platos != nullptr)delete []platos;
}

void Restaurante::SetCapacidadDePlatos(int capacidadDePlatos) {
    this->capacidadDePlatos = capacidadDePlatos;
}

int Restaurante::GetCapacidadDePlatos() const {
    return capacidadDePlatos;
}

void Restaurante::SetCantidadDePlatos(int cantidadDePlatos) {
    this->cantidadDePlatos = cantidadDePlatos;
}

int Restaurante::GetCantidadDePlatos() const {
    return cantidadDePlatos;
}

void Restaurante::SetCapacidadDeClientes(int capacidadDeClientes) {
    this->capacidadDeClientes = capacidadDeClientes;
}

int Restaurante::GetCapacidadDeClientes() const {
    return capacidadDeClientes;
}

void Restaurante::SetCantidadDeClientes(int cantidadDeClientes) {
    this->cantidadDeClientes = cantidadDeClientes;
}

int Restaurante::GetCantidadDeClientes() const {
    return cantidadDeClientes;
}

void Restaurante::operator<(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    Cliente regCli;
    while (true) {
        arch>>regCli;
        if (arch.eof())break;
        if (cantidadDeClientes == capacidadDeClientes)aumentarEspaciosCli();
        clientes[cantidadDeClientes] = regCli;
        cantidadDeClientes++;
    }
}

void Restaurante::aumentarEspaciosCli() {
    Cliente *aux;
    capacidadDeClientes += INCREMENTO;
    if (clientes == nullptr) {
        clientes = new Cliente [capacidadDeClientes]{};
    } else {
        aux = new Cliente [capacidadDeClientes]{};
        for (int i = 0; i < cantidadDeClientes; i++)
            aux[i] = clientes[i];
        delete []clientes;
        clientes = aux;
    }
}

void Restaurante::operator<=(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    Plato regPla;
    while (true) {
        arch>>regPla;
        if (arch.eof())break;
        if (cantidadDePlatos == capacidadDePlatos)aumentarEspaciosPla();
        platos[cantidadDePlatos] = regPla;
        cantidadDePlatos++;
    }
}

void Restaurante::aumentarEspaciosPla() {
    Plato *aux;
    capacidadDePlatos += INCREMENTO;
    if (platos == nullptr) {
        platos = new Plato [capacidadDePlatos]{};
    } else {
        aux = new Plato [capacidadDePlatos]{};
        for (int i = 0; i < cantidadDePlatos; i++)
            aux[i] = platos[i];
        delete []platos;
        platos = aux;
    }
}

void Restaurante::operator<<=(const char* nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    int numPed, dniCli, posCli;
    while (true) {
        arch>>numPed;
        if (arch.eof())break;
        arch.get();
        arch>>dniCli;
        arch.get();
        posCli = buscarCliente(dniCli);
        if (posCli != NO_ENCONTRADO) {
            agregarAtributos(arch, clientes[posCli], posCli);
        } else while (arch.get() != '\n');
    }
}

int Restaurante::buscarCliente(int dniCli) const {
    for (int i = 0; i < cantidadDeClientes; i++) {
        if (clientes[i].getDni() == dniCli)return i;
    }
    return NO_ENCONTRADO;
}

void Restaurante::agregarAtributos(ifstream& arch, Cliente& cliente, int posCli) {
    int cantidad, posPla, quedan, aten, noAten;
    char cod[8];
    while (true) {
        arch.getline(cod, 8, ',');
        arch>>cantidad;
        posPla = buscarPlato(cod);
        if (posPla != NO_ENCONTRADO) {
            quedan = platos[posPla].getPreparados() -
                    platos[posPla].getAtendidos();
            if (quedan < cantidad) {
                aten = quedan;
                noAten = cantidad - quedan;
            } else {
                aten = cantidad;
                noAten = 0;
            }
            cliente.modifica(aten, platos[posPla].getPrecio(),
                    platos[posPla].getDescuento());
            platos[posPla].modifica(aten, noAten,
                    cliente.getDescuento());
        }
        if (arch.get() != ',')break;
    }
}

int Restaurante::buscarPlato(const char* codPla) const {
    char cod[8];
    for (int i = 0; i < cantidadDePlatos; i++) {
        platos[i].getCodigo(cod);
        if (strcmp(cod, codPla) == 0)return i;
    }
    return NO_ENCONTRADO;
}

void Restaurante::operator>>(const char*nombArch) const {
    ofstream arch(nombArch, ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch;
        exit(1);
    }
    arch << "PLATOS" << endl;
    for (int i = 0; i < cantidadDePlatos; i++) {
        arch << platos[i];
    }

    arch << endl;

    arch << "CLIENTES" << endl;
    for (int i = 0; i < cantidadDeClientes; i++) {
        arch << clientes[i];
    }
}



