/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 9 de abril de 2025, 22:18
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "FuncionesSobrecargadas.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    ifstream archLibros, archClientes;
    struct Cliente clientes[100];
    struct Libro libros[300];
    AperturaDeUnArchivoDeTextosParaLeer(archLibros, "Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archClientes, "Cientes.csv");
    
    int nd = 0;
    bool valor;
    while(true){
        valor = archLibros >> libros[nd];
        if(!valor)
            break;
        nd++;
    }
    strcpy(libros[nd].codigo, "FIN");
    nd++;
    
    int n = 0;
    while(true){
        valor = archClientes >> clientes[n];
        if(!valor)
            break;
        n++;
    }
    
    
    struct LibroSolicitado pedido[10];
    
    
    
    strcpy(pedido[0].codigoDelLibro, "TAB4639");
    pedido[0].numeroDePedido = 000001;
    pedido[0].precio = 26.91;
    
    strcpy(pedido[1].codigoDelLibro, "DTH6788");
    pedido[1].numeroDePedido = 0000002;
    pedido[1].precio = 5.00;
    
    
    strcpy(pedido[2].codigoDelLibro, "QKH2262");
    pedido[2].numeroDePedido = 0000003;
    pedido[2].precio = 83.83;
    
    libros[188].stock = 0;
    
    clientes[0] << pedido[0];
    clientes[0] << pedido[1];
    
    clientes[1] << pedido[2];
    
    for(int i = 0; i < 2; i++)
        clientes[0].librosSolicitados[i] >> libros;
    
    clientes[1].librosSolicitados[0] >> libros;
    
    ++(clientes[0]);
    ++(clientes[1]);
    
    ofstream outLibros, outClientes;
    
    AperturaDeUnArchivoDeTextosParaEscribir(outLibros, "PruebaLibros.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(outClientes, "PruebaClientes.txt");
    
    for(int i = 0; i < nd; i++){
        outLibros << libros[i];
    }
    
    for(int i = 0; i < n; i++)
        outClientes << clientes[i];
    
    return 0;
}


