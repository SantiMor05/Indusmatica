/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 1 de junio de 2025, 13:19
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Restaurante.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Restaurante restaurante{};
    
    restaurante < "Clientes.csv";
    restaurante <= "PlatosOfrecidos.csv";
    
    restaurante <<= "Pedidos.csv";
    
    restaurante >> "ReporteDeVentasDelDia.txt";
    
    return 0;
}

