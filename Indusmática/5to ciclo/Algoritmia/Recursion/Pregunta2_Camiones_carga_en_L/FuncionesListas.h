/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesListas.h
 * Author: Usuario
 *
 * Created on 2 de mayo de 2025, 08:41 PM
 */

#ifndef FUNCIONESLISTAS_H
#define FUNCIONESLISTAS_H

#endif /* FUNCIONESLISTAS_H */

#include "Elemento.h"
#include "Nodo.h"

void crearLista(struct Lista &lista);
void insertar_al_final(struct Lista &lista, int num);
struct Nodo *crearNodo(Elemento &elemento,Nodo *siguiente);
void imprimirLista(Lista lista);

