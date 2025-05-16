/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: Esteban
 * cod: 20231348
 *
 * Created on 15 de mayo de 2025, 15:19
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std; 
#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"
//
int main(int argc, char** argv) { 
    void *arreglo,*pilaini,*pilafin; 

    cargaarreglo(arreglo,cmpnumero,leenumero,"numeros.txt"); 
    cargapila(pilaini,arreglo); 
    muevepila(pilaini,pilafin); 
    
    imprimepila(pilafin,imprimenumero,"repnumeros.txt");
    
    
    cargaarreglo(arreglo,cmpregistro,leeregistro,"medicinas.csv"); 
    cargapila(pilaini,arreglo); 
    muevepila(pilaini,pilafin); 
    imprimepila(pilafin,imprimeregistro,"repmedicinas.txt"); 
    return 0; 
}


