/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesLista.h
 * Author: Usuario
 *
 * Created on 2 de mayo de 2025, 17:19
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construirLista(Lista &lista);
void insertarOrdenado(Lista &lista, int prioridad, int hora, int sucursal);
bool esListaVacia(Lista lista);
Nodo* crearNodo(struct Elemento elemento,struct Nodo *siguiente);
void imprimeLista(Lista lista);
void Fusion(Lista &L1, Lista L2);

#endif /* FUNCIONESLISTA_H */
