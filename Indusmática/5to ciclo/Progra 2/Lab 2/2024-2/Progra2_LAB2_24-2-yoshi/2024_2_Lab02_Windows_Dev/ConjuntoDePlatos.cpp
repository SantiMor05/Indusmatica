/* 
 * Archivo: ConjuntoDePlatos.cpp
 * Autor: Andrés Melgar
 * Fecha: 30 de agosto de 2024, 22:50
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "ConjuntoDePlatos.hpp"
#include "AperturaDeArchivos.h"

using namespace std;

void cargar_conjunto_de_platos(ConjuntoDePlatos &conjuntoDePlatos, const char *nombre_de_archivo) {
    ifstream archivo_de_platos;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_platos, nombre_de_archivo);
    archivo_de_platos >> conjuntoDePlatos;
    archivo_de_platos.close();
}

void operator>>(istream &archivo_de_platos, ConjuntoDePlatos &conjuntoDePlatos) {
    ConjuntoDePlatos bufferPlat;
    bufferPlat.conjunto_de_datos = new Plato[150]{};
    bufferPlat.cantidad = 0;
    Plato plato;
    int nd;
    while(archivo_de_platos>>plato){
        nd = bufferPlat.cantidad;
        bufferPlat.conjunto_de_datos[nd].codigo = plato.codigo;
        bufferPlat.conjunto_de_datos[nd].nombre = plato.nombre;
        bufferPlat.conjunto_de_datos[nd].precio = plato.precio;
        bufferPlat.conjunto_de_datos[nd].tipo = plato.tipo;
        bufferPlat.cantidad++;
    }
    conjuntoDePlatos.conjunto_de_datos = new Plato[bufferPlat.cantidad+1]{};
    for (int i = 0; i < bufferPlat.cantidad; i++) {
        conjuntoDePlatos.conjunto_de_datos[i].codigo = bufferPlat.conjunto_de_datos[i].codigo;
        conjuntoDePlatos.conjunto_de_datos[i].nombre = bufferPlat.conjunto_de_datos[i].nombre;
        conjuntoDePlatos.conjunto_de_datos[i].precio = bufferPlat.conjunto_de_datos[i].precio;
        conjuntoDePlatos.conjunto_de_datos[i].tipo = bufferPlat.conjunto_de_datos[i].tipo;
    }
    conjuntoDePlatos.cantidad = bufferPlat.cantidad;
    delete bufferPlat.conjunto_de_datos;
}

void liberar_conjunto_de_platos(ConjuntoDePlatos &conjuntoDePlatos) {

}

double operator+=(const ConjuntoDePlatos &conjuntoDePlatos, const char *codigo) {    
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        if (strcmp(conjuntoDePlatos.conjunto_de_datos[i].codigo, codigo) == 0)
            return conjuntoDePlatos.conjunto_de_datos[i].precio;
    }
}

char* operator==(const ConjuntoDePlatos &conjuntoDePlatos, const char *codigo) {
    for (int i = 0; i < conjuntoDePlatos.cantidad; i++) {
        if (strcmp(conjuntoDePlatos.conjunto_de_datos[i].codigo, codigo) == 0)
            return conjuntoDePlatos.conjunto_de_datos[i].nombre;
    }
    return nullptr;
}