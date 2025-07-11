/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   funcionesCola.h
 * Author: anaro
 *
 * Created on 5 de mayo de 2025, 10:55
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H
void construir(struct Cola & );       
bool esColaVacia(const struct Cola & cola);
void encolar(struct Cola & cola, const struct Elemento &);
void encolar(struct Cola & cola, struct NodoArbol *&nodo);
NodoArbol * desencolar2(struct Cola & cola);
void imprimir(const struct Cola & cola);
struct Elemento desencolar(struct Cola & cola);
#endif /* FUNCIONESCOLA_H */
