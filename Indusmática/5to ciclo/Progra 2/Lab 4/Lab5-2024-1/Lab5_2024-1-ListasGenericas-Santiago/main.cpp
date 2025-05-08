/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 6 de mayo de 2025, 22:38
 */


#include <iostream>
#include <iomanip>
#include "BibliotecaGenerica.h"
#include "FuncionesEnteras.h"
#include "FuncionesRegistros.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    void *pedidos1, *pedidos2, *pedidosfinal;   
    
    crealista(pedidos1, leenum, "RegistroNum1.txt");
    imprimelista(pedidos1, imprimenum, "Repnum1.txt");
    crealista(pedidos2, leenum, "RegistroNum2.txt");
    imprimelista(pedidos2, imprimenum, "Repnum2.txt");
    combinaLista(pedidos1, pedidos2,pedidosfinal, cmpnum);
    imprimelista(pedidosfinal, imprimenum, "RepnumFinal.txt");
    
    
    crealista(pedidos1, leeregistro, "Pedidos31.csv");
    imprimelista(pedidos1,imprimeRegistro,"Repreg1.txt");
    crealista(pedidos2, leeregistro, "Pedidos32.csv");
    imprimelista(pedidos2,imprimeRegistro,"Repreg2.txt");
    combinaLista(pedidos1, pedidos2, pedidosfinal, cmpregistro);
    imprimelista(pedidosfinal,imprimeRegistro,"RepregFinal.txt");
    
    return 0;
}

