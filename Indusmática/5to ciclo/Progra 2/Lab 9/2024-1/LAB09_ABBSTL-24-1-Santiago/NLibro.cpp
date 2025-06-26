/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NLibro.cpp
 * Author: santi
 * 
 * Created on 25 de junio de 2025, 22:28
 */

#include "NLibro.h"
#include "Novela.h"
#include "Enciclopedia.h"
#include "Revista.h"

NLibro::NLibro() {
    inicializa();
}

NLibro::NLibro(const NLibro& orig) {
   *this = orig;
}
//
//NLibro::~NLibro() {
//     if(plibro != nullptr)delete plibro;
//}

void NLibro::operator =(const NLibro& orig){
    plibro = orig.plibro;
}
void NLibro::inicializa(){
    plibro = nullptr;
}

void NLibro::asignaTipo(char car){
    
    if(car == 'N')
        plibro = new Novela;
    else if(car == 'E')
        plibro = new Enciclopedia;
    else 
        plibro = new Revista;
}


void NLibro::lee(ifstream &arch){
    plibro->lee(arch);
}

double  NLibro::getPeso(){
    
    return plibro->GetPeso();
    
}

void NLibro::imprime(ofstream &arch){
    
    plibro->imprime(arch);
    
}