/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 8 de mayo de 2025, 10:08
 */

#include "BibliotecaGenerica.h"
#include "funcionesEnteras.h"
#include "FuncionesRegistros.h"
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    void *pedidos1, *pedidos2, *pedidosFinal;
    
    crealista(pedidos1,leenum,"RegistroNum1.txt");
    imprimelista(pedidos1,imprimenum,"Repnum1.txt");
    
    
    crealista(pedidos2,leenum,"RegistroNum2.txt");
    imprimelista(pedidos2,imprimenum,"Repnum2.txt");
    
    combinalista(pedidos1,pedidos2,pedidosFinal,cmpnum);
    imprimelista(pedidosFinal,imprimenum,"RepnumFinal.txt");
    
    
    crealista(pedidos1,leeregistro,"Pedidos31.csv");
    imprimelista(pedidos1,imprimeregistro,"Repreg1.txt");
    crealista(pedidos2,leeregistro,"Pedidos32.csv");
    imprimelista(pedidos2,imprimeregistro,"Repreg2.txt");
    
    combinalista(pedidos1,pedidos2,pedidosFinal,cmpregistro);
    imprimelista(pedidosFinal,imprimeregistro,"RepregFinal.txt");

    
    return 0;
}

