/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 22 de mayo de 2025, 17:46
 */

#include <cstring>
#include <iostream>
#include <iomanip>
#include "funcionesCola.h"
#include "Elemento.h"
#include "Cola.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Cola cola;
    Elemento elemento;
    
    construir(cola);
    
    
    elemento.prioridad = 2;
    strcpy(elemento.codigo, "ISI001");
    encola_prioridad(cola,elemento);
    
    elemento.prioridad = 1;
    strcpy(elemento.codigo, "ISI002");
    encola_prioridad(cola,elemento);
    
    elemento.prioridad = 1;
    strcpy(elemento.codigo, "ISI003");
    encola_prioridad(cola,elemento);
    
    elemento.prioridad = 3;
    strcpy(elemento.codigo, "ISI004");
    encola_prioridad(cola,elemento);
    
    elemento.prioridad = 2;
    strcpy(elemento.codigo, "ISI005");
    encola_prioridad(cola,elemento);
    
    elemento.prioridad = 3;
    strcpy(elemento.codigo, "ISI006");
    encola_prioridad(cola,elemento);
    
    elemento.prioridad = 1;
    strcpy(elemento.codigo, "ISI007");
    encola_prioridad(cola,elemento);
    
    

    imprimir(cola);
    
    return 0;
}

