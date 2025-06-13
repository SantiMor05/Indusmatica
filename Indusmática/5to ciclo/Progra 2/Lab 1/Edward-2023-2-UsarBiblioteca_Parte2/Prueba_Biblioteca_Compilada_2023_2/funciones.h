/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: 00123
 *
 * Created on 10 de abril de 2025, 03:30 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void leerClientes(struct Cliente*clientes,const char*nombArch);
void leerProductos(struct Producto*productos,const char*nombArch);
void procesarPedidos(struct Cliente*clientes,struct Producto*productos,
        const char*nombArch);
void hallarMontosClie(struct Cliente*clientes);
void calcMonto(struct Cliente &cliente);
void emitirClientes(struct Cliente*clientes,const char*nombArch);
void emitirProductos(struct Producto*productos,const char*nombArch);


#endif /* FUNCIONES_H */

