/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   main.cpp
 * Author: esteban
 *
 * Created on 8 de mayo de 2025, 16:40
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistro.h"
/*
 * 
 */
int main(int argc, char** argv) {
    void* lista1, *lista2;
    
    creaLista(lista1,leenum,cmpnum,"RegistroDeFaltas1.csv");
    creaLista(lista2,leenum,cmpnum,"RegistroDeFaltas2.csv");
    uneLista(lista1,lista2);
    imprimeLista(lista1,imprimenum,"Repnum.txt"); 
    
    
     creaLista(lista1,leeregistro,cmpregistro,"RegistroDeFaltas1.csv");
     creaLista(lista2,leeregistro,cmpregistro,"RegistroDeFaltas2.csv");
     uneLista(lista1,lista2);
    imprimeLista(lista1,imprimeregistro,"RepFalta.txt"); 

    
    
    return 0;
}

