/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 7 de mayo de 2025, 10:37 AM
 */

#include "BibliotecaGenerica.h"
#include "ListaconEnteros.h"
#include "ListaconRegistros.h"

using namespace std;
int main(int argc, char** argv) {
    void *lista;
    crealista(lista,leenumeros,"numeros1.txt");
    cargalista(lista,compruebanumero,leeregnumeros,"numeros2.txt");
    muestralista(lista,imprimenumeros,"repnum.txt");
    crealista(lista,leeregistros,"repartidores.csv");
    cargalista(lista,compruebaregistro,leeordenes,"ordenes.csv");
    muestralista(lista,imprimeregistros,"repregistros.txt");
    return 0;
}
