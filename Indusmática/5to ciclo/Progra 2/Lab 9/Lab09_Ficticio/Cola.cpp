//
// Created by kenyi on 25/06/2025.
//

#include "Cola.h"
#include  "Nodo.h"
#include  "Multa.h"
#include <fstream>
#include <iostream>
using namespace std;

Cola::Cola() {
    cabeza = nullptr;
    cola = nullptr;
}

void Cola::insertarConductores(ifstream &arch) {
    string nombre;
    int dni;
    while (true) {
        arch >> dni;
        if (arch.eof()) break;
        arch.get();
        getline(arch, nombre);
        Conductor conductor;
        conductor.set_nombre(nombre);
        conductor.set_dni(dni);
        conductor.cargarPlaca("Unidades.csv");
        conductor.cargarMultas("faltas.csv", multas);
        encolar(conductor);
    }
}

void Cola::encolar(Conductor &conductor) {
    Nodo *nodo = new Nodo;
    nodo->datoConductor = conductor;
    if (cabeza == nullptr) {
        cabeza = nodo;
        cola = nodo;
    } else {
        cola->siguiente = nodo;
        cola = nodo;
    }
}

void Cola::cargarConductores(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch) {
        cout << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }
    insertarConductores(arch);
}

Conductor Cola::desencola() {
    if (cabeza == nullptr) return Conductor();
    Conductor conductor;
    Nodo *temp = cabeza;
    conductor = temp->datoConductor;
    cabeza = cabeza->siguiente;
    delete temp;
    if (cabeza == nullptr) cola = nullptr;
    return conductor;
}

Cola::~Cola() {
    while (cabeza != nullptr) {
        desencola();
    }
}

void Cola::imprimirConductores(const char *nombArch) {
    ofstream arch(nombArch, ios::out);
    if (!arch) {
        cout << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }
    Conductor conductor;
    while (cola) {
        conductor = desencola();
        arch << conductor;
    }
}

void Cola::insertarMultar(ifstream &arch) {
    int numMulta;
    string desc, tipo;
    double monto;
    while (true) {
        arch >> numMulta;
        if (arch.eof()) break;
        arch.get();
        getline(arch, desc, ';');
        getline(arch, tipo, ';');
        arch >> monto;
        Multa multa;
        multa.set_descripcion(desc);
        multa.set_tipo(tipo);
        multa.set_multa(monto);
        multa.set_num_multa(numMulta);
        multas.push_back(multa);
    }
}

void Cola::cargarMultas(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch) {
        cout << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }
    insertarMultar(arch);
}
