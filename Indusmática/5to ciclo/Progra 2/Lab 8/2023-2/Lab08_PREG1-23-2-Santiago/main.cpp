/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 19 de junio de 2025, 14:17
 */

#include <cstdlib>
#include "Flota.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Flota transporte;
    
    transporte.cargaflota();
    transporte.cargaPedidos();
    transporte.muestracarga();

    return 0;
}

