/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00123
 *
 * Created on 26 de junio de 2025, 03:23 PM
 */

#include "MinisterioTransportes.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    MinisterioTransportes mini;
    
    mini.cargarConductores();
    mini.cargarInfracciones();
    mini.destinarFaltas();
    mini.impirmir();
    return 0;
}

