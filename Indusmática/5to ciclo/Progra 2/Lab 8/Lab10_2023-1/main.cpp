/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kenyi
 *
 * Created on 19 de junio de 2025, 03:48 PM
 */

#include <cstdlib>

#include "Tesoreria.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Tesoreria Aboleta;
    
    Aboleta.cargaalumnos();
    Aboleta.actualizaboleta();
    Aboleta.imprimeboleta();
    return 0;
}

