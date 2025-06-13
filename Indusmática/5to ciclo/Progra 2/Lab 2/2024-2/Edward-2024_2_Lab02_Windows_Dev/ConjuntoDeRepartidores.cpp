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

void operator>>(istream &arch, ConjuntoDeRepartidores &repartidores){   

    Repartidor bufRepartidores[50]{};
    int nd=0;
    while(true){
        if(arch>>bufRepartidores[nd])nd++;
        else break;
    }
    repartidores.conjunto_de_datos=new Repartidor[nd]{};
    repartidores.cantidad=nd;
    for (int i = 0; i < nd; i++) {
        repartidores.conjunto_de_datos[i]=bufRepartidores[i];
    }
}

void liberar_conjunto_de_repartidores(ConjuntoDeRepartidores &conjuntoDeRepartidores){
    
}