/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 24 de junio de 2025, 22:33
 */

#include "AnalisisSentimiento.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    AnalisisSentimiento analisis;
    
    analisis.cargar_lexicon();
    analisis.cargar_comentarios_restaurantes();
    analisis.imprimir_analisis();

    return 0;
}

