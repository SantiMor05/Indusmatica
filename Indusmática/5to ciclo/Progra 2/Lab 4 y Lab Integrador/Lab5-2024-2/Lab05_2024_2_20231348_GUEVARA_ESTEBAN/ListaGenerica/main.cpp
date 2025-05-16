/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 7 de mayo de 2025, 20:48
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "BibliotecaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistros.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    void* lista;
    crealista(lista,leenumeros,"numeros1.txt");    
    cargalista(lista,compruebanumero,leeregnumeros,"numeros2.txt");
    muestralista(lista,imprimenumeros,"repnum.txt");
    
    crealista(lista,leeregistros,"repartidores.csv");    
    cargalista(lista,compruebaregistro,leeordenes,"ordenes.csv");
    muestralista(lista,imprimeregistros,"registros.txt");

            
    return 0;
}

