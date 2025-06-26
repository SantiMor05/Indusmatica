/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 23 de junio de 2025, 07:52 PM
 */

#include <iostream>

using namespace std;
#include "AnalisisSentimiento.h"
/*
 * 
 */
int main(int argc, char** argv) {
    AnalisisSentimiento analisis,analisis2;
    
    analisis.cargar_lexicon();
    analisis.cargar_comentarios_restaurantes();
    analisis.ordenar_comentarios();
    analisis.imprimir_analisis2();
    
    
//    analisis2.cargar_lexicon();
//    analisis2.cargar_comentarios_restaurantes2();
//    analisis2.imprimir_analisis2();
    return 0;
}

