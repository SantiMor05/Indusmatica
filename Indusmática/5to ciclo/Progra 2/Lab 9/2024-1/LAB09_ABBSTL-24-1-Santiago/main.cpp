/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 25 de junio de 2025, 22:22
 */

#include "Biblioteca.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Biblioteca bli;
    
    bli.carga();
    bli.muestra();
    bli.prueba(8);
    
    return 0;
}

