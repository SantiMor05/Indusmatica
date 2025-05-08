/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Lenovo
 *
 * Created on 7 de mayo de 2025, 10:58 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "BibliotecaGenerica.h"
#include "FuncionesEnteras.h"
#include "FuncionesRegistro.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *pedidos1, *pedidos2, *pedidosFinal;
    //Pregunta 1 y 2
//    creaLista(pedidos1, leeNum, "RegistroNum1.txt");
//    imprimeLista(pedidos1, imprimeNum, "RepNum1.txt");
//    creaLista(pedidos2, leeNum, "RegistroNum2.txt");
//    imprimeLista(pedidos2, imprimeNum, "RepNum2.txt");
//    combinaLista(pedidos1, pedidos2, pedidosFinal,cmpNum);
//    imprimeLista(pedidosFinal, imprimeNum ,"RepNumFinal.txt");

    //Pregunta 3
    creaLista(pedidos1, leeRegistro, "Pedidos31.csv");
    imprimeLista(pedidos1, imprimeRegistro, "RepReg1.txt");
    creaLista(pedidos2, leeRegistro, "Pedidos32.csv");
    imprimeLista(pedidos2, imprimeRegistro, "RepReg2.txt");
    combinaLista(pedidos1, pedidos2, pedidosFinal,cmpReg);
    imprimeLista(pedidosFinal, imprimeRegistro, "RepRegFinal.txt");

    return 0;
}

