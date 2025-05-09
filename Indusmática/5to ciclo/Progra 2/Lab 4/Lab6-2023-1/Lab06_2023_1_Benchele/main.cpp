/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 8 de mayo de 2025, 06:56 PM
 */

 /* Created on 8 de mayo de 2025, 05:59 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "ArreglosGenericos.h"
#include "ListasGenericas.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *arrHeroes, *listaHeroes;
    int cantTotalHeroes;
    
    //llenarArregloHeroes(arrHeroes, cantTotalHeroes, "Datos.txt");
    llenarArregloHeroes(arrHeroes, cantTotalHeroes, "heroes_changelog_1223.csv");
    //imrpimriHeros(arrHeroes);
    qsort(arrHeroes, cantTotalHeroes, sizeof(void *), cmpMulticriterioVoid);
    //imrpimriHeros(arrHeroes);
    crearListaHeroes(arrHeroes, listaHeroes, leerRegHeroe);
    imrpimirListaHeroes(listaHeroes, imprimirRegHeroe, "ReporteHeores.txt");
    eliminarHeroesRepetidos(listaHeroes, eliminarRegistro);
    imrpimirListaHeroes(listaHeroes, imprimirRegHeroe, "ReporteHeoresFinal.txt");
    
    return 0;
}

