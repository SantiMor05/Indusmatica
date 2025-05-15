/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 15 de mayo de 2025, 09:54
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
#include "arreglos_genericos.h"
#include "listas_genericas.h"
/*
 * 
 */
int main(int argc, char** argv) {

    void* arreglo_heroes,*lista_heroes;
    int cantidad_total_heroes;
    
    llenar_arreglo_heroes(arreglo_heroes,cantidad_total_heroes,
            "heroes_changelog_1223.csv");
    
    qsort(arreglo_heroes,cantidad_total_heroes,sizeof(void*),
            cmp_multicriterio_void);
    
    crear_lista_heroes(arreglo_heroes,lista_heroes, lee_heroe);
    
    imprimir_lista_heroes(lista_heroes, imprimir_registro_heroe);
    
    eliminar_lista_heroes_repetidos(lista_heroes,eliminar_registro);
    
    imprimir_lista_heroes(lista_heroes, imprimir_registro_heroe);
    
    return 0;
}


