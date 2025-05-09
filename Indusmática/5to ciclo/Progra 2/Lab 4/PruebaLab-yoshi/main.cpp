/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 8 de mayo de 2025, 18:16
 */

#include <cstdlib>
#include <fstream>
using namespace std;
#include "BibliotecaGenerica.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void* lista;
    crearLista(lista,"Infracciones.csv");
    imprimeLista(lista,"Reporte.txt");
    return 0;
}

