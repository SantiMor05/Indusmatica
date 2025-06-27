/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Lenovo
 * 
 * Created on 26 de junio de 2025, 05:20 PM
 */

#include <iostream> 
#include <iomanip> 
#include <fstream>
#include <string>
#include "Libro.h"
using namespace std;

Libro::Libro() {
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

void Libro::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Libro::GetNombre() const {
    return nombre;
}

/*
 N,Diamantes y pedernales,120,0.7,  Jose Maria Arguedas
 E,ENCICLOPEDIA SALVAT,2000,12,     78323,2015
 R,Educacion,48,0.2,    10199403,2024,6
   NOMBRE  PAGINAS   PESO
 */
void Libro::lee(ifstream &arch){
    char c;
    getline(arch, nombre, ',');
    arch>>paginas>>c>>peso;
    arch.get();
}
void Libro::imprime(ofstream &arch){
    arch<<"Titulo: "<<nombre<<endl;
    arch<<"Peso: "<<peso<<endl;
}