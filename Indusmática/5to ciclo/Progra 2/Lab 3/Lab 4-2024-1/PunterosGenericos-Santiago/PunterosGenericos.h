/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.h
 * Author: santi
 *
 * Created on 1 de mayo de 2025, 10:33
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;

void cargaclientes(void *&clientes);
void *leerCliente(ifstream &arch);
char *leerCadenaExacta(ifstream &arch, char deli);
void creareserva(void *&reserva);
void * leerLibro(ifstream &arch);
void cargareservar(void *clientes, void *reserva);
void agregarReserva(void *cliente, void *libro);
char *asignarCadena(char *nombre);
int buscarCliente(int dni, void *clientes);
int buscarLibro(char *codigo, void *reserva);

#endif /* PUNTEROSGENERICOS_H */
