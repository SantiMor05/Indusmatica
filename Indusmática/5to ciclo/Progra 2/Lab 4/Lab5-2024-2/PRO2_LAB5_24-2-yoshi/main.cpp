/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 7 de mayo de 2025, 13:48
 */

#include <cstdlib>
#include <fstream>
using namespace std;
#include "ListaConRegistros.h"
#include "ListaConEnteros.h"
#include "BibliotecaGenerica.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void* lista;
    crearLista(lista,leerNumeros,"numeros1.txt");
    cargarLista(lista,compruebaNum,leerRegNum,"numeros2.txt");
    muestraLista(lista,imprimeNumeros,"repnum.txt");
    
    crearLista(lista,leerRegistros,"repartidores.csv");
    cargarLista(lista,compruebaRegistro,leerOrdenes,"ordenes.csv");
    muestraLista(lista,imprimeReg,"repregistros.txt");
    return 0;
}

