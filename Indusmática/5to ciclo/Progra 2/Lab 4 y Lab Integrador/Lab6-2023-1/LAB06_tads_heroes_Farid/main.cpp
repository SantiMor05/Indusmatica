/* 
 * File:   main.cpp
 * Author: Farid Oswaldo
 *
 * Created on 8 de mayo de 2025, 03:13 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "arreglos_genericos.h"
#include "listas_genericas.h"

/*
 * 
 */

int main(int argc, char** argv) {
    void *arreglo_heroes, *lista_heroes;
    int cantidad_total_heroes;
    
    llenar_arreglo_heroes(arreglo_heroes, cantidad_total_heroes,"heroes.csv");
//    imprimirarr(arreglo_heroes, "RepHeroes.txt", cantidad_total_heroes);
    qsort(arreglo_heroes, cantidad_total_heroes, sizeof(void*), cmp_multicriteriovoid);
//    imprimirarr(arreglo_heroes, "RepHeroesOrd.txt", cantidad_total_heroes);
    crear_lista_heroes(arreglo_heroes, lista_heroes, leer_heroes);
    imprimir_lista_heroes(lista_heroes, imprimirLista);
    eliminar_lista_heroes_repetidos(lista_heroes, eliminar_registro);
    imprimir_lista_heroes(lista_heroes, imprimirLista);
    
    return 0;
}

