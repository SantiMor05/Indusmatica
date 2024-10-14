/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 10 de octubre de 2024, 21:46
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    procesarDatos("Pacientes.txt", "CitasMedicas.txt", "Medicos.txt", 
            "Medicinas.txt", "DetalleCitas.txt");

    return 0;
}

