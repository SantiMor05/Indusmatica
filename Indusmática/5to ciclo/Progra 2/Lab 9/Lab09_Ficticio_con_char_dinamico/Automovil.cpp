//
// Created by kenyi on 25/06/2025.
//

#include "Automovil.h"

#include <cstring>

void Automovil::get_placa(char *plac) const {
    if (placa == nullptr) plac[0] = 0;
    else strcpy(plac, placa);
}

void Automovil::set_placa(const char *plac) {
    if (placa != nullptr) delete placa;
    placa = new char[strlen(plac) + 1];
    strcpy(placa, plac);
}

Automovil::Automovil() {
    placa = nullptr;
}

Automovil::~Automovil() {
    if (placa != nullptr) delete placa;
}

Automovil::Automovil(const Automovil &automovil) {
    placa = nullptr;
    *this = automovil;
}

void Automovil::operator=(const Automovil &automovil) {
    char aux[20];
    automovil.get_placa(aux);
    set_placa(aux);
}
