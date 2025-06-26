//
// Created by kenyi on 26/06/2025.
//

#include "Multa.h"

string Multa::get_tipo() const {
    return tipo;
}

void Multa::set_tipo(const string &tipo) {
    this->tipo = tipo;
}

int Multa::get_num_multa() const {
    return numMulta;
}

void Multa::set_num_multa(int num_multa) {
    numMulta = num_multa;
}

string Multa::get_descripcion() const {
    return descripcion;
}

void Multa::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(double multa) {
    this->multa = multa;
}
