/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 1 de mayo de 2025, 11:42
 */


#include <iostream>
#include <iomanip>
#include "MuestraPunteros.h"
#include "PunterosGenericos.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    void *productos, *clientes;
    
    cargaproductos(productos);
    imprimeproductos(productos);
    
    cargaclientes(clientes);
    imprimeclientes(clientes);
    
    cargapedidos(productos,clientes);
    imprimerepfinal(clientes);

    return 0;
}

