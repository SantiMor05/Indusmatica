/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 1 de mayo de 2025, 08:10 PM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
#include "PunterosGenericos.h"
#include "MuestraPunteros.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *productos,*clientes;
    
    cargaproductos(productos);
    cargaclientes(clientes);
    cargapedidos(productos,clientes);
    imprimereporte(clientes);
 
    return 0;
}

