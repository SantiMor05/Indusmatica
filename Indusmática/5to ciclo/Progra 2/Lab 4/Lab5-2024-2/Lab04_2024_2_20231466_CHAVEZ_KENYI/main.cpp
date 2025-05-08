/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 8 de mayo de 2025, 11:45 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "BibliotecaGenerica.h"
#include "ListaconEnteros.h"
#include "ListaconRegistros.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *lista;
    
    crelista(lista,leenumeros,"numeros1.txt");
    cargalista(lista,compruebanumero,leeregnumeros,"numeros2.txt");
    muestralista(lista,imprimenumeros,"repnum.txt");
    
    crelista(lista,leeregistro,"repartidores.csv");
    cargalista(lista,compruebaregistro,leeordenes,"ordenes.csv");
    muestralista(lista,imprimeregistros,"repregistros.txt");
    return 0;
}

