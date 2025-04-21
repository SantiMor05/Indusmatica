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
    ConjuntoDeRepartidores buffRep;
    Repartidor repartidor;
    buffRep.cantidad = 0;
    buffRep.conjunto_de_datos = new Repartidor[50]{};
    int nd;
    while(archivo_de_repartidores>>repartidor){
        nd = buffRep.cantidad;
        buffRep.conjunto_de_datos[nd].codigo = repartidor.codigo;
        buffRep.conjunto_de_datos[nd].nombre = repartidor.nombre;
        buffRep.conjunto_de_datos[nd].vehiculo =  repartidor.vehiculo;
        buffRep.cantidad++;
    }
    conjuntoDeRepartidores.cantidad = buffRep.cantidad;
    conjuntoDeRepartidores.conjunto_de_datos = new Repartidor[buffRep.cantidad+1]{};
    for (int i = 0; i < buffRep.cantidad; i++) {
        conjuntoDeRepartidores.conjunto_de_datos[i].codigo = buffRep.conjunto_de_datos[i].codigo;
        conjuntoDeRepartidores.conjunto_de_datos[i].nombre = buffRep.conjunto_de_datos[i].nombre;
        conjuntoDeRepartidores.conjunto_de_datos[i].vehiculo = buffRep.conjunto_de_datos[i].vehiculo;
    }
    delete buffRep.conjunto_de_datos;
}

void liberar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores){
    
}