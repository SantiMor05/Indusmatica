//
// Created by kenyi on 25/06/2025.
//

#include "Infracciones.h"

#include <iomanip>

string Infracciones::get_placa() const {
    return placa;
}

void Infracciones::set_placa(const string &placa) {
    this->placa = placa;
}

int Infracciones::get_fecha() const {
    return fecha;
}

void Infracciones::set_fecha(int fecha) {
    this->fecha = fecha;
}

int Infracciones::get_num() const {
    return num;
}

void Infracciones::set_num(int num) {
    this->num = num;
}

void Infracciones::leer(ifstream &arch) {
    int dd, mm, aa;
    char c;
    getline(arch, placa, ';');
    arch >> dd >> c >> mm >> c >> aa >> c >> num;
    fecha = aa * 10000 + mm * 100 + dd;
}

void Infracciones::imprime(ofstream &out) const {
    out << placa << " " << setw(2) << setfill('0') << fecha % 100
            << "/" << setw(2) << (fecha % 10000) / 100 << "/" << setw(4) << fecha / 10000
            << setfill(' ') << " " << num << endl;
}
