/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 26 de junio de 2025, 18:33
 */

#include "Flota.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Flota Unidades;
    
    Unidades.cargaflota();
    Unidades.cargapedidos();
    Unidades.muestracarga();

    return 0;
}

