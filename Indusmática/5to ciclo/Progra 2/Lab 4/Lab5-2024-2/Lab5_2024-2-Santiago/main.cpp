/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 5 de mayo de 2025, 18:59
 */

#include <iostream>
#include <iomanip>
#include "BibliotecaGenerica.h"
#include "ListaconEnteros.h"
#include "ListaconRegistros.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    void *lista;
    
//    crealista(lista, leenumeros, "numeros1.txt");
//    cargalista(lista,compruebanumeros, leeregnumeros, "numeros2.txt");
//    muestralista(lista, imprimenumeros, "repnum.txt");
    
    crealista(lista, leeregistros, "Repartidores.csv");
    cargalista(lista, compruebaregistros, leeregistros, "Ordenes.csv");
    muestralista(lista, imprimeRegistro, "repregistros.txt");
    
    return 0;
}

