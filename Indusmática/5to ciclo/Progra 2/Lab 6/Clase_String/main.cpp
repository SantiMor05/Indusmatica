/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 31 de mayo de 2025, 20:06
 */


#include <iostream>
#include <iomanip>
#include "Cadena.h"
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Cadena *ptr;
    
    leerDatos(ptr);
    
    imprimirDatos(ptr);
    int n = contar(ptr);
    
    qsort(ptr,n,sizeof(Cadena), compara);
    cout << endl << endl;
    imprimirDatos(ptr);

    return 0;
}

