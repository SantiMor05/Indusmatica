/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NEstante.cpp
 * Author: Lenovo
 * 
 * Created on 26 de junio de 2025, 05:24 PM
 */

#include <iostream> 
#include <iomanip> 
#include "NEstante.h"
#include "NLibro.h"
#define MAX_LINEA 120
using namespace std;

NEstante::NEstante() {
    izq = nullptr;
    der = nullptr;
}

NEstante::NEstante(const NEstante& orig) {
}

NEstante::~NEstante() {
}

void NEstante::SetDisponible(double disponible) {
    this->disponible = disponible;
}

double NEstante::GetDisponible() const {
    return disponible;
}

void NEstante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double NEstante::GetCapacidad() const {
    return capacidad;
}

void NEstante::SetId(int id) {
    this->id = id;
}

int NEstante::GetId() const {
    return id;
}

/*
 N, Diamantes y pedernales,120,0.7,  Jose Maria Arguedas
 E, ENCICLOPEDIA SALVAT,2000,12,     78323,2015
 R, Educacion,48,0.2,    10199403,2024,6
    NOMBRE  PAGINAS   PESO
 */
void NEstante::leerLibros(ifstream &arch){
    char tipo, c;
    class NLibro libro;

    for (int i = 0; i < 10; i++) {
        arch>>tipo>>c;
        libro.asignaMemoria(tipo);
        libro.leer(arch);
        if(libro.getPeso() <= disponible){
            vLibros.push_back(libro);
            disponible -= libro.getPeso();
        }
    }
}

void NEstante::imprime(ofstream &arch){
    imprimirLinea(arch, '-');
    arch<<"Estante: "<<id<<endl;
    arch<<"Capacidad: "<<left<<setw(8)<<capacidad<<"Disponible: "<<disponible<<endl;
    imprimirLinea(arch,'=');
    for (auto libro: vLibros) {
        libro.imprimir(arch);
    }
}

void NEstante::imprimirLinea(ofstream &arch, char linea){
    for (int i = 0; i < MAX_LINEA; i++)arch.put(linea);
    arch<<endl;
}