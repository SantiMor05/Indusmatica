/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: 00123
 *
 * Created on 9 de abril de 2025, 10:01 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

//#include <fstream>
//using namespace std;


void leerLibros(struct Libro*libros,const char*nombDoc);
void leerClientes(struct Cliente*clientes,const char*nombDoc);
void procesarPedidos(struct Libro*libros,struct Cliente*clientes,const char*nombDoc);
void calcPagosClien(struct Cliente*clientes);
int buscarClie(struct Cliente*clientes,int dni);
void procesarLibros(ifstream &arch,struct Libro*libros,struct Cliente*clientes,
        int numPedido,int dni,int posClie);
void emitirLibros(struct Libro*libros,const char*nombDoc);
void emitirClientes(struct Cliente*clientes,const char*nombDoc);


#endif /* FUNCIONES_H */

