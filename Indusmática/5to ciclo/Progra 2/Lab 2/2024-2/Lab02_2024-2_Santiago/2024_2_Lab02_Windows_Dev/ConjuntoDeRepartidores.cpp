/* 
 * Archivo: ConjuntoDeRepartidores.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 00:44
 */

#include <iostream>
#include <fstream>
#include "ConjuntoDeRepartidores.hpp"
#include "AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores, const char *nombre_de_archivo){
    ifstream archivo_de_repartidores;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_repartidores, nombre_de_archivo);
    archivo_de_repartidores >> conjuntoDeRepartidores;
    archivo_de_repartidores.close();
}

void operator>>(istream &archivo_de_repartidores, ConjuntoDeRepartidores &conjuntoDeRepartidores){   
    struct Repartidor repartidores[100], aux;
    int numDat = 0;
    bool valido;
    while(true){
        valido = archivo_de_repartidores >> aux;
        if(!valido)
            break;
        repartidores[numDat] = aux;
        numDat++;
    }
    
    conjuntoDeRepartidores.conjunto_de_datos = new struct Repartidor[numDat];
    for(int i = 0; i < numDat; i++)
        conjuntoDeRepartidores.conjunto_de_datos[i] = repartidores[i];
    conjuntoDeRepartidores.cantidad = numDat;
}

void liberar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores){
    
}