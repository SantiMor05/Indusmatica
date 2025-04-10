/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 7 de abril de 2025, 22:50
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "AperturaDeArchivos.h"
#include "FuncionesSobrecargadas.h"
#include "FuncionesAuxiliares.h"
#include "Estructuras.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    struct Plato platos[200];
    struct Pedido pedidos[200];
    struct Repartidor repartidores[50];
  
    int nPlatos = 0, nPedidos = 0, nRepar = 0;

    //Leemos Platos
    leerPlatos(platos, nPlatos);
    leerRepartidores(repartidores, nRepar);
    leerPedidos(pedidos, nPedidos);


    for (int i = 0; i < nPedidos; i++)
        pedidos[i] <= platos;

    for (int i = 0; i < nPedidos; i++)
        repartidores <= pedidos[i];

    for (int i = 0; i < nRepar; i++) {
        int n = repartidores[i].cantidadDeOrdenes;
        for (int j = 0; j < n; j++)
            !repartidores[i].ordenesDeCompra[j];

        !repartidores[i];
    }
    
    imprimirReportePlatos(platos, nPlatos);
    imprimirReporteRepartidores(repartidores, nRepar);
    
    return 0;
}

