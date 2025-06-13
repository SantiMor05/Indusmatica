/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 12 de junio de 2025, 05:01 PM
 */

#include <cstdlib>
#include "Restaurante.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Restaurante restaurante{};

    restaurante.cargar_comandas("atenciones.csv", "comandas.csv");
    restaurante.actualizar_comandas();
    restaurante.imprimir_comandas("Reporte.txt");
    
    return 0;
}

