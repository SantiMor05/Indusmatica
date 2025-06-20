/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 19 de junio de 2025, 18:17
 */

#include <cstdlib>
#include "Tesoreria.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Tesoreria ABoleta;
    
    ABoleta.cargaalumnos();
    ABoleta.actualizaboleta();
    ABoleta.imprimeBoleta();

    return 0;
}

