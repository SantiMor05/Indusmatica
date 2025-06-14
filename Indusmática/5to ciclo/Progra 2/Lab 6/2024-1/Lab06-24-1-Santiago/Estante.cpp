/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.cpp
 * Author: santi
 * 
 * Created on 4 de junio de 2025, 20:06
 */

#include "Estante.h"
#include "Espacio.h"

Estante::Estante() {
    
    inicializa();
}

//Estante::Estante(const Estante& orig) {
//    inicializa();
//}

Estante::~Estante() {
    if(espacios != nullptr)delete []espacios;
    if(codigo != nullptr) delete codigo;
}

void Estante::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estante::GetCantidad_libros() const {
    return cantidad_libros;
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(char* cod) {
    if(codigo != nullptr)delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Estante::GetCodigo(char *buffer) const {
    if(codigo == nullptr) buffer[0] = 0;
    else
        strcpy(buffer, codigo);
}

void Estante::inicializa(){
    codigo = nullptr;
    cantidad_libros = 0;
    espacios = nullptr;    
}



//void Estante::operator =(const Estante &estante){
//    char buffer[500];
//    
//    estante.GetCodigo(buffer);
//    SetCodigo(buffer);
//    
//    anchura = estante.GetAnchura();
//    altura = estante.GetAltura();
//    cantidad_libros = 
//    
//}

void operator >>(ifstream &arch, Estante &estante){
    
    char buffer[500] , car;
    int ancho, alto;
    
    arch.getline(buffer, 500, ',');
    if(arch.eof())return;
    estante.SetCodigo(buffer);    
    arch >> ancho >> car >> alto;
    arch.get();//Leemos el salto de linea
    estante.SetAltura(alto);
    estante.SetAnchura(ancho);
    
    estante.asignaEspacios();
    
}

void Estante::asignaEspacios(){
    
    if(espacios != nullptr) delete []espacios;
    if(altura != 0 and anchura != 0)
        espacios = new Espacio[anchura *altura]{};
    
}


/*Para una matriz de 4x6 tenemos
 * 18 19 20 21 22 23
 * 12 13 14 15 16 17
 *  6  7  8  9 10 11
 *  0  1  2  3  4  5 
 
 En el arreglo se guardaria 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
 
 
 */
bool Estante::operator +=(Libro &libro){
    
    int ancho,alto;
    
    buscarEspacios(ancho, alto);
    
}

void Estante::buscarEspacios(int &ancho, int &alto){
    
    ancho = alto = 0;
    
    for(int i = 0; i < anchura * altura; i++){
        if(espacios[i].GetContenido() == ' '){
            
        }
    }
    
}