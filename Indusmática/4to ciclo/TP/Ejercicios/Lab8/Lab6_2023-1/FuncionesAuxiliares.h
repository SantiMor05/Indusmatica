/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 10 de noviembre de 2024, 19:24
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
#include "Libros.h"
#include "stSolicitudes.h"
#include "stUsuarios.h"

using namespace std;

void leerDatosLibros(int &cant_libros, struct Libros *libros, 
        const char *nomblibros);
void leerLibro(ifstream &archLibros, struct Libros &libros);
void leerDatosUsuarios(int &cant_usuarios, struct Usuarios *usuarios,
        const char *nombUsuario);
void leerUsuario(ifstream &archUsuario, struct Usuarios &usuarios);
void leerDatosSolicitudes(int &cant_solicitudes, struct Solicitudes *solicitudes,
        const char *nombSoli);
void leerSolicitud(ifstream &archSoli, struct Solicitudes &solicitudes);
void imprimirReporte(int cant_libros, struct Libros *libros, int cant_usuarios,
        struct Usuarios *usuarios, int cant_solicitudes,
        struct Solicitudes *solicitudes, const char *nombReporte);
void imprimirLibros(int &cant_libros, struct Libros *libros,
        ofstream &archReporte);
void imprimirUsuarios(int cant_usuarios, struct Usuarios *usuarios,
        ofstream &archReporte);
void imprimirSolicitudes(int cant_solicitudes, struct Solicitudes *solicitudes, 
        ofstream &archReporte);
void imprimirCaracter(char car, ofstream &archReporte);
void ordenarUsuarios(int cant_usuarios, struct Usuarios *usuarios);
void intercambiarUsuarios(struct Usuarios &usuarios1, struct Usuarios &usuarios2);
void atenderSolicitudes(int cant_libros, struct Libros *libros, 
        int cant_usuarios, struct Usuarios *usuarios, int cant_solicitudes,
        struct Solicitudes *solicitudes, const char *nombDenegados);
int encontrarMax(const struct Usuarios &usuarios);
int buscarLibro(char *cod_libro, int cant_libros, struct Libros *libros);

#endif /* FUNCIONESAUXILIARES_H */

