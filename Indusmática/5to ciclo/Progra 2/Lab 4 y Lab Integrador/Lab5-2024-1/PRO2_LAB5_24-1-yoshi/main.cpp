/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 8 de mayo de 2025, 10:02
 */

#include <cstdlib>
#include <fstream>
using namespace std;
#include "FuncionesEnteras.h"
#include "FuncionesRegistro.h"
#include "BibliotecaGenerica.h"
/*
 * 
 */
int main(int argc, char** argv) {
    /*Para quien vea esto, la impresión de datos la hice con el destructor, por tanto,
     cuando lees la cabeza de la lista, saca el nodo de la lista, como indica el problema,
     esto hace que a la hora de fusionar las listas, el programa no encuentre las
     cabezas de las listas 1 y 2, comentar la impresión de las listas 1 y 2 y ver
     que el programa funciona al 100%*/
    
    
    void*pedidos1, *pedidos2, *pedidosFinal;
    crearLista(pedidos1,leenum,"RegistroNum1.txt");
    imprimeLista(pedidos1,imprimenum,"Repnum1.txt");
    crearLista(pedidos2,leenum,"RegistroNum2.txt");
    imprimeLista(pedidos2,imprimenum,"Repnum2.txt");
    combinaLista(pedidos1,pedidos2,pedidosFinal,cmpnum);
    imprimeLista(pedidosFinal,imprimenum,"RepNumFinal.txt");
    
    crearLista(pedidos1,leeReg,"Pedidos31.csv");
    imprimeLista(pedidos1,imprimeReg,"RepReg1.txt");
    crearLista(pedidos2,leeReg,"Pedidos32.csv");
    imprimeLista(pedidos2,imprimeReg,"RepReg2.txt");
    combinaLista(pedidos1,pedidos2,pedidosFinal,cmpReg);
    imprimeLista(pedidosFinal,imprimeReg,"RepRegFinal.txt");
    return 0;
}

