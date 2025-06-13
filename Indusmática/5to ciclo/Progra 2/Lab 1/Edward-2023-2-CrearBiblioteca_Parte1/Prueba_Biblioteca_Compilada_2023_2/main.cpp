/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Edward Delgadillo
 * Codigo: 20230636
 * Created on 10 de abril de 2025, 10:55 AM
 */

#include <iostream>
#include <fstream>

using namespace std;
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "sobrecarga.h"


/*
 * 
 */
int main(int argc, char** argv) {

    struct Cliente clientes[140]{};
    struct Producto productos[170]{};
    
    ifstream archCliIn,archProIn,archPediIn;
    ofstream archCliOut,archProOut;
    AperturaDeUnArchivoDeTextosParaLeer(archCliIn,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProIn,"Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPediIn,"Pedidos.csv");
    
    AperturaDeUnArchivoDeTextosParaEscribir(archCliOut,"pruebaCli.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archProOut,"pruebaPro.txt");
    
    int cantCli=0;
    while(true){
        if(archCliIn>>clientes[cantCli]){
            cantCli++;
        }
        else break;
    }
    clientes[cantCli++].dni=0;
    int cantPro=0;
    while(true){
        if(archProIn>>productos[cantPro]){
            cantPro++;
        }
        else break;
    }
    strcpy(productos[cantPro++].codigo,"XXX");

    struct Pedido pedido{};
    archPediIn>>pedido;

    clientes+=pedido;
    productos+=pedido;
    
    for (int i = 0; clientes[i].dni; i++) {
        archCliOut<<clientes[i];
    }
    
    for (int i = 0; strcmp(productos[i].codigo,"XXX"); i++) {
        archProOut<<productos[i];
        archProOut<<endl;
    }
    
    return 0;
}

