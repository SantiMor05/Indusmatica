/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 14 de octubre de 2024, 11:41
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int ciclo, anho;
    
    solicitarCiclo(ciclo, anho);
    
    procesarDatos(ciclo, anho, "Alumnos.txt", "Cursos.txt", "Escalas.txt",
            "Matricula.txt", "ReportePorCiclo.txt");

    return 0;
}

