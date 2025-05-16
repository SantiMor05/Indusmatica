/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 6 de mayo de 2025, 11:47 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "BibliotecaGenerica.h"
#include "ListaconEnteros.h"
#include "ListaConRegistro.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *lista;
    
//    creaLista(lista, leeNumeros, "numeros1.txt");
//    cargaLista(lista,compruebaNumero, leeRegNumeros, "numeros2.txt");
//    muestraLista(lista, imprimeNumeros, "ReporteNumerosFinal.txt");

    creaLista(lista, leeRegistros, "Repartidores.csv");
    cargaLista(lista, compruebaRegistro, leeOrdenes, "Ordenes.csv");
    muestraLista(lista, imprimeRegistros, "ReporteRegistros.txt");   
    return 0;
}

