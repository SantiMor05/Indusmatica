/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 9 de abril de 2025, 22:35
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
#include "Estructuras.h"
using namespace std;

void leerLibros(struct Libro *libros, int &n);
void leerClientes(struct Cliente *clientes, int &n);
void leerPedidos(struct Libro *libros, int nLibros, struct Cliente *clientes,
        int nClientes);
int buscarCliente(int dni, struct Cliente *clientes, int n);
void imprimriLibros(struct Libro *libros, int nLibros);
void imprimirCaracter(char car, int n, ofstream &arch);
void imprimirClientes(struct Cliente *clientes, int n);


#endif /* FUNCIONESAUXILIARES_H */

