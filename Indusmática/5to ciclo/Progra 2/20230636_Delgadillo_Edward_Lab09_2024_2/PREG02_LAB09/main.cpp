/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 23 de junio de 2025, 05:04 PM
 */

#include <iostream>
#include <string>
using namespace std;
#include "Palabra.h"
#include "AnalisisSentimiento.h"
/*
 * 
 */
int main(int argc, char** argv) {

    AnalisisSentimiento analisis;
    
    analisis.cargar_lexicon();
    analisis.cargar_comentarios_restaurantes();
    analisis.ordenar_comentarios();
    analisis.imprimir_analisis();
    
    return 0;
}

