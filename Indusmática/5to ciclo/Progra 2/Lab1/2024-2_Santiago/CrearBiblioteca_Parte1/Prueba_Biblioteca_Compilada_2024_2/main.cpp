/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 7 de abril de 2025, 22:40
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "AperturaDeArchivos.h"
#include "FuncionesSobrecargadas.h"
#include "Estructuras.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream archPlatos, archOrdenes, archRepar;
    ofstream outPlatos, outOrdenes, outRepar;
    struct Plato plato[200];
    struct Pedido pedido[200];
    struct Repartidor repartidor[50];
    
    AperturaDeUnArchivoDeTextosParaLeer(archOrdenes, "OrdenesDeCompra.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archPlatos, "PlatosOfrecidos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archRepar, "RepartidoresContratados.csv");
    
     AperturaDeUnArchivoDeTextosParaEscribir(outPlatos, 
            "PruebaImpresionPlatos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(outOrdenes, 
            "PruebaImpresionOrdenes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(outRepar, 
            "PruebaImpresionRepar.txt");
    
    
    int nPlatos = 0, nPedidos = 0, nRepar = 0;
    while(true){
        archPlatos >> plato[nPlatos];
        if(archPlatos.eof())break;
        nPlatos++;
    }
    strcpy(plato[nPlatos].codigo, "FIN");
    nPlatos++;
    
    while(true){
        archOrdenes >> pedido[nPedidos];
        if(archOrdenes.eof())break;
        nPedidos++;
    }
    
    while(true){
        archRepar >> repartidor[nRepar];
        if(archRepar.eof())break;
        nRepar++;
    }
    strcpy(repartidor[nRepar].codigo, "FIN");
    nRepar++;
    
    for(int i = 0; i < nPedidos;i++)
        pedido[i] <= plato;
    
    for(int i = 0; i <nPedidos; i++)
        outOrdenes << pedido[i].precio << setw(10) << pedido[i].cantidad
                << setw(10) << pedido[i].codigoDelPlato<< endl;
    
    for(int i = 0; i < nPedidos;i++)
        repartidor <= pedido[i];
    
   
    
    for(int i = 0; i < nRepar; i++){
        int n = repartidor[i].cantidadDeOrdenes;
        for(int j = 0; j < n; j++)
            !repartidor[i].ordenesDeCompra[j];
        
        !repartidor[i];
    }
    
    
    
    for(int i = 0; i < nPlatos;i++)
        outPlatos << plato[i];
    
    for(int i = 0; i < nRepar; i++){
        outRepar << repartidor[i];
    }

    return 0;
}

