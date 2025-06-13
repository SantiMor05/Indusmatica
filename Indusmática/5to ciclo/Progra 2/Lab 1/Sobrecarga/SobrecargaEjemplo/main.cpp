/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 30 de enero de 2025, 16:59
 */

#include <iostream>
#include <iomanip>
#include "Vector.h"
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    struct Vector v1, v2, v3;
    
    
    //Inicializamos las estructuras
    !v1;
    !v2;
    
//    v1 + 5 + 6+7+7+7; //Agrega varios elementos
//    v1 + 10;
//    v1 + 7;
//    v1 + 8;
//    
//    v2 + 1;
//    v2 + 2;
//    v2 + 3;
//    v2 + 4;
    
    cin >> v1 >> v2;
    
    v1 += v2;
    v3 = v1 + v2;
    cout << v1  << v2 << v3 << endl;
    
    return 0;
}

