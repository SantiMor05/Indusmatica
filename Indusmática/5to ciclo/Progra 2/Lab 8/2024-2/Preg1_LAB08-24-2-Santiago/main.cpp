/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 18 de junio de 2025, 10:46
 */

#include <cstdlib>
#include "Restaurante.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
        
    Restaurante res;
    
    res.carga();
    res.atiende();

    return 0;
}

//Me quede en 1:04:00