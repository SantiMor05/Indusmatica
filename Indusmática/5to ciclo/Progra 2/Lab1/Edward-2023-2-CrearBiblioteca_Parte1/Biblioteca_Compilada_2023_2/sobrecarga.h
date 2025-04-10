/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecarga.h
 * Author: 00123
 *
 * Created on 10 de abril de 2025, 10:55 AM
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H

bool operator >>(ifstream &arch,struct Cliente &cliente);
bool operator >>(ifstream &arch,struct Producto &producto);
bool operator >>(ifstream &arch,struct Pedido &pedido);
void operator +=(struct Cliente *clientes,const struct Pedido &pedido);
void agregarPedido(struct Cliente &cliente,const struct Pedido &pedido);
bool operator +=(struct Producto *productos,struct Pedido &pedido);
bool actualizarProduc(struct Producto &producto,struct Pedido &pedido);
void operator <<(ofstream &arch,const struct Cliente &cliente);
void operator <<(ofstream &arch,const struct Producto &producto);
void imprimirArr(ofstream &arch,const int*dnis,int cant);


#endif /* SOBRECARGA_H */

