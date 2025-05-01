/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 11 de abril de 2025, 2:45 PM
 */

#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

int main(int argc, char** argv) {

    Lista lista;
    
    construir(lista);
    insertarAlInicioArchivo("datos.txt",lista);
    imprime(lista);
    ordenar(lista,true);
    imprime(lista);
    ordenar(lista,false);
    imprime(lista);
    
    return 0;
}

