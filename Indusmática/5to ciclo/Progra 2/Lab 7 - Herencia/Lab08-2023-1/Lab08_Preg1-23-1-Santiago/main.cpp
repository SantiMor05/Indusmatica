/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 11 de junio de 2025, 23:15
 */

#include <cstdlib>
#include "Tesoreria.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Tesoreria caja;
    caja.cargaescalas();
    caja.cargaalumnos();
    caja.actualiza(20);
    caja.imprime();
    
   
    return 0;
}

