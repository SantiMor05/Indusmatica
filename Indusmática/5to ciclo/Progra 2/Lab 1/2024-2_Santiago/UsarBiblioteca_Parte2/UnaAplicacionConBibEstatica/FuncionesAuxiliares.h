/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 7 de abril de 2025, 22:55
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerPlatos(struct Plato *platos, int &nPlatos);
void leerPedidos(struct Pedido *pedidos, int &nPedidos);
void leerRepartidores(struct Repartidor *repartidores, int &nRepar);
void imprimirReportePlatos(struct Plato *platos, int nPlatos);
void imprimirReporteRepartidores(struct Repartidor *repartidores, int nRepar);
void imprimirCaracter(char car, int n, ofstream &outPlatos);

#endif /* FUNCIONESAUXILIARES_H */

