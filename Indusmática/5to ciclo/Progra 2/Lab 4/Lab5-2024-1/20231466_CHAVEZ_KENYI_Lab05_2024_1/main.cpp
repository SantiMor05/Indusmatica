/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 20231466 Kenyi Chavez
 *
 * Created on 7 de mayo de 2025, 08:22 PM
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;
#include "BibliotecaGenerica.h"
#include "FuncionesEnteras.h"
#include "FuncionesRegistros.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void *pedidos1,*pedidos2,*pedidosfinal;
    
    crearlista(pedidos1,leenum,"RegistroNum1.txt");
    imprimelista(pedidos1,imprimenum,"Repnum1.txt");
    crearlista(pedidos2, leenum, "RegistroNum2.txt");
    imprimelista(pedidos2, imprimenum, "Repnum2.txt");
    combinalista(pedidos1,pedidos2,pedidosfinal,cmpnum);
    imprimelista(pedidosfinal,imprimenum,"RepnumFinal.txt");
    
    crearlista(pedidos1,leeregistro,"Pedidos31.csv");
    imprimelista(pedidos1,imprimeregistro,"Repreg1.txt");
    crearlista(pedidos2, leeregistro, "Pedidos32.csv");
    imprimelista(pedidos2, imprimeregistro, "Repreg2.txt");
    combinalista(pedidos1,pedidos2,pedidosfinal,cmpregistro);
    imprimelista(pedidosfinal,imprimeregistro,"RepregFinal.txt");
    return 0;
}

