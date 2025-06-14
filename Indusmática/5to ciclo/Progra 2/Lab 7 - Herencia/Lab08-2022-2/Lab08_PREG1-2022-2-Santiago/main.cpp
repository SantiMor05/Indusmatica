/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 12 de junio de 2025, 22:03
 */

#include <cstdlib>
#include "Farmacia.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Farmacia ofarma;
    
    ofarma.cargamedico();
    ofarma.leerecetas();
    ofarma.imprimirrecetas();
    
    return 0;
}

