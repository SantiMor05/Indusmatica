/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 8 de junio de 2025, 19:17
 */

#include <cstdlib>
#include "Restaurante.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Restaurante restaurante;
    
    restaurante.cargar_comandas();
    restaurante.actualizar_comandas();
    restaurante.imprimir_comandas();

    return 0;
}

