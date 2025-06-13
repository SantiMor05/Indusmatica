/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 9 de abril de 2025, 23:26
 */


#include <iostream>
#include <iomanip>
#include "AperturaDeArchivos.h"
#include "FuncionesSobrecargadas.h"
#include "Estructuras.h"
#include <cstring>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ifstream archProductos, archClientes, archPedidos;

    struct Cliente clientes[150];
    struct Producto productos[200];
    struct Pedido pedidos[600];

    AperturaDeUnArchivoDeTextosParaLeer(archProductos, "Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos, "Pedidos.csv");

    int nProductos = 0, nClientes = 0, nPedidos = 0;
    bool valor;


    valor = archClientes >> clientes[nClientes];
    nClientes++;
    clientes[nClientes].dni = 0;
    nClientes++;

    valor = archProductos >> productos[nProductos];
    nProductos++;
    
    strcpy(productos[nProductos].codigo, "XXXXXXX");
    nProductos++;
    
    valor = archPedidos >> pedidos[nPedidos];
    nPedidos++;
    

    pedidos[1].dniCliente = clientes[0].dni;
    strcpy(pedidos[1].CodigoProducto, productos[0].codigo);
    
    for(int i = 0; i < 2; i++){
        valor = productos += pedidos[i];
        if(valor){
            clientes += pedidos[i];
        }
    }
    
    ofstream outClientes, outProductos;

    AperturaDeUnArchivoDeTextosParaEscribir(outClientes, "PruebaClientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(outProductos, "PruebaProductos.txt");

    for(int i = 0; clientes[i].dni; i++)
        outClientes << clientes[i];
    
    for(int i = 0; strcmp(productos[i].codigo, "XXXXXXX"); i++)
        outProductos << productos[i];

    return 0;

    
}



