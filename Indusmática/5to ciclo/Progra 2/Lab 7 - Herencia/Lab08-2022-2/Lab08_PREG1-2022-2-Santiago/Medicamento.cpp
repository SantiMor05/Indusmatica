/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medicamento.cpp
 * Author: santi
 * 
 * Created on 12 de junio de 2025, 22:09
 */

#include "Medicamento.h"
#include <cstring>
#include <iomanip>
using namespace std;

Medicamento::Medicamento() {
    inicializa();
}

//Medicamento::Medicamento(const Medicamento& orig) {
//}

Medicamento::~Medicamento() {
    if(nombre != nullptr) delete nombre; 
}

void Medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Medicamento::GetFecha() const {
    return fecha;
}

void Medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double Medicamento::GetPrecio() const {
    return precio;
}

void Medicamento::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Medicamento::GetCantidad() const {
    return cantidad;
}

void Medicamento::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Medicamento::GetNombre(char *buffer) const {
    if(nombre == nullptr) buffer[0] = 0;
    else strcpy(buffer, nombre);
}

void Medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medicamento::GetCodigo() const {
    return codigo;
}

void Medicamento::inicializa(){
    nombre = nullptr;
    codigo = 0; //Servira para la impresion
}

void Medicamento::buscarLeerMedicamento(ifstream &arch, int medicamento){
    arch.seekg(0,ios::beg);
    int med;
    char nomb[100];
    while(true){
        arch >> med;
        if(arch.eof())return;
        if(med == medicamento){
            codigo = med;
            arch.get();
            arch.getline(nomb, 100, ',');
            SetNombre(nomb);
            arch >> precio;
            break;
        }
        else while(arch.get() != '\n');
    }
    
}

void Medicamento::imprimir(ofstream &arch){
    
    arch << left << setw(12) << codigo << setw(45) << nombre << right << setw(4)
            << cantidad;
    
}