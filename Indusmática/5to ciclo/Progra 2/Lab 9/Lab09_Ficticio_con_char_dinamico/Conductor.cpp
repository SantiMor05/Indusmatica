//
// Created by kenyi on 24/06/2025.
//

#include "Conductor.h"

#include <iomanip>
#include <queue>
#include <cstring>
#include <iostream>

#include "Multa.h"
using namespace std;

Conductor::Conductor() {
    nombre = nullptr;
}

Conductor::Conductor(const Conductor &conductor) {
    nombre = nullptr;
    *this = conductor;
}

Conductor::~Conductor() {
    if (nombre != nullptr) delete []nombre;
}

int Conductor::get_dni() const {
    return dni;
}

void Conductor::set_dni(int dni) {
    this->dni = dni;
}

void Conductor::get_nombre(char *nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Conductor::set_nombre(const char *nomb) {
    if (nombre != nullptr) delete []nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Conductor::imprimirPlacas(ofstream &out) const {
    for (Automovil a: placas) {
        char aux[20];
        a.get_placa(aux);
        out << aux << " ";
    }
    out << endl;
}

void Conductor::insertarPlaca(const char *str) {
    Automovil automovil;
    automovil.set_placa(str);
    placas.push_back(automovil);
}

void Conductor::imprimir(ofstream &arch) const {
    arch << dni << " " << nombre << endl;
}

void Conductor::cargarPlaca(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }
    arch.seekg(0, ios::beg);
    arch.clear();
    int dni_conductor;
    char placa[20];
    while (true) {
        arch >> dni_conductor;
        if (arch.eof()) break;
        arch.get();
        arch.getline(placa, 20);
        if (dni_conductor == dni) insertarPlaca(placa);
    }
    arch.close();
}

string Conductor::buscarTipoMulta(int numMulta, const vector<Multa> &multas) {
    for (Multa m: multas) {
        if (numMulta == m.get_num_multa())return m.get_tipo();
    }
    return "";
}

void Conductor::cargarMultas(const char *nombArch, const vector<Multa> &multas) {
    ifstream arch(nombArch, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }
    arch.seekg(0, ios::beg);
    arch.clear();
    int dni_conductor;
    string tipo;
    Infracciones infraccion;
    while (true) {
        arch >> dni_conductor;
        if (arch.eof()) break;
        if (dni_conductor == dni) {
            arch.get();
            infraccion.leer(arch);
            tipo = buscarTipoMulta(infraccion.get_num(), multas);
            infracciones[tipo].push_back(infraccion);
        } else while (arch.get() != '\n');
    }
    arch.close();
}

void Conductor::imprimirInfracciones(ofstream &out) const {
    if (infracciones.count("Leve") == 0)out << "Leve: No hay infraccion" << endl;
    if (infracciones.count("Grave") == 0)out << "Grave: No hay infraccion" << endl;
    if (infracciones.count("Muy Grave") == 0)out << "Muy Grave: No hay infraccion" << endl;
    for (auto infraccion: infracciones) {
        out << infraccion.first << ": " << endl;
        for (int i = 0; i < infraccion.first.size() + 1; i++)out.put('-');
        out << endl;
        for (Infracciones inf: infraccion.second) {
            inf.imprime(out);
        }
    }
    out << "===================================================" << endl;
}

void Conductor::operator=(const Conductor &conductor) {

    char aux[100];
    conductor.get_nombre(aux);
    set_nombre(aux);
    dni = conductor.dni;
    infracciones = conductor.infracciones;
    placas = conductor.placas;

}

void operator<<(ofstream &out, const Conductor &conductor) {
    conductor.imprimir(out);
    out << "Placas: ";
    conductor.imprimirPlacas(out);
    conductor.imprimirInfracciones(out);
}
