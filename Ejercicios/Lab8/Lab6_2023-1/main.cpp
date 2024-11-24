/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 10 de noviembre de 2024, 19:23
 */

#include <iostream>
#include <iomanip>
#include "FuncionesAuxiliares.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    struct Libros libros[50]{};
    struct Usuarios usuarios[60]{};
    struct Solicitudes solicitudes[250];
    
    int cant_libros,cant_usuarios,cant_solicitudes;
    
    leerDatosLibros(cant_libros, libros, "Libros_Laboratorio6.csv");
    leerDatosUsuarios(cant_usuarios, usuarios, "Usuarios.csv");
    leerDatosSolicitudes(cant_solicitudes, solicitudes, 
            "SolicitudesDePrestamo.txt");
    
    imprimirReporte(cant_libros, libros, cant_usuarios, usuarios, 
            cant_solicitudes, solicitudes, "Prueba.txt");
    
    
    ordenarUsuarios(cant_usuarios, usuarios);
    
    imprimirReporte(cant_libros, libros, cant_usuarios, usuarios, 
            cant_solicitudes, solicitudes, "Prueba2.txt");
    
    atenderSolicitudes(cant_libros, libros, cant_usuarios, usuarios, 
            cant_solicitudes, solicitudes, "SolicitudesDenegadas.txt");
    
    imprimirReporte(cant_libros, libros, cant_usuarios, usuarios, 
            cant_solicitudes, solicitudes, "ReporteDeSolicitudes.txt");
    
    return 0;
}

