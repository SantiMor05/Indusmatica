/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 12 de junio de 2025, 06:23 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

#include "Restaurante.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Restaurante restaurante{};

    restaurante.cargar_comandas();
    restaurante.actualizar_comandas();
    restaurante.imprimir_comandas();
    return 0;
}
