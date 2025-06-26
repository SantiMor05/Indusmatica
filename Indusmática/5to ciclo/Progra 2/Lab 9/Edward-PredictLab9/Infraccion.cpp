/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.cpp
 * Author: 00123
 * 
 * Created on 26 de junio de 2025, 03:24 PM
 */
#include <fstream>
#include <string>
using namespace std;
#include "Infraccion.h"

//Infraccion::Infraccion() {
//}
//
//Infraccion::Infraccion(const Infraccion& orig) {
//}
//
//Infraccion::~Infraccion() {
//}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetGravedad(string gravedad) {
    this->gravedad = gravedad;
}

string Infraccion::GetGravedad() const {
    return gravedad;
}

void Infraccion::SetDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

string Infraccion::GetDescripcion() const {
    return descripcion;
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

void Infraccion::leer(ifstream& arch) {

    arch>>codigo;
    if(arch.eof())return;
    arch.get();
    getline(arch,descripcion,',');
    getline(arch,gravedad,',');
    arch>>multa;
}

bool Infraccion::operator<(const Infraccion& i) const {

    return codigo<i.codigo;
}
