/* 
 * File:   main.cpp
 * Author: Farid Oswaldo
 *
 * Created on 1 de mayo de 2025, 08:17 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "PunterosGenericos.h"
/*
 * 
 */

int main(int argc, char** argv) {
    
    void *producto, *clientes;
    
    cargaproductos(producto);
    cargaclientes(clientes);
    cargapedidos(producto, clientes);
//    imprimereporte(clientes);
//    
    
    return 0;
}

