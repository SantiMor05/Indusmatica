/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: YOSHI
 *
 * Created on 12 de junio de 2025, 08:15
 */

#include <cstdlib>

using namespace std;
#include "Restaurante.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Restaurante restaurante;
    restaurante.cargar_comandas();
    restaurante.actualizaComandas();
    restaurante.imprimirComandas();
    return 0;
}

