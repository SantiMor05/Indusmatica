/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 1 de mayo de 2025, 21:50
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
    
    void *productos, *pedidos, *clientes;
    
    cargaproductos(productos);
    imprimeproductos(productos);
    
    cargapedidos(pedidos);
    imprimepedidos(pedidos);

    procesaclientes(productos, pedidos, clientes);
    
    imprimeReporte(clientes);
    imprimeproductos(productos);
    
    return 0;
}

