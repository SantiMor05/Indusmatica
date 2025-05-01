/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: alulab14
 *
 * Created on 29 de abril de 2025, 03:03 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <fstream>
using namespace std;

void cargarInventario(const char*nombArch, void*&inv);
void* leeInsumo(ifstream &arch);
char* leeCadena(ifstream &arch,char deli);
void pasarInfo(void**&inventario,void**bufInventario,int nd);
void cargarMenu(const char*nombArch, void*&menu);
void actualizarMenu(const char*nombArch, void*inventrario,void*menu);
void reporteMenu(const char*nombArch, void*menu);
void* leerMenu(ifstream &arch);

void actualizarMenu(const char*nombArch, void*ins,void*bebs);
int buscarBebida(const char*codBebida,void**bebidas);
void agregarInsumo(ifstream &arch,void*beb,int &nd,int &capa,void**ins);
int buscarInsumo(void**insumos,const char*codInsumo);
bool aumentarRequerido(void*in,double resultado);
void incrementar(void*&ins,int &nd,int &capa);
void addInsumo(void*&ingre,void*insu,double*cantidad,
        const char*uniMed);

void reporteMenu(const char*nombArch, void*bebs);
void imprimirBebida(ofstream &arch,void*beb);
const char*hallarNombre(char*letratipo);
void imprimeLinea(ofstream &arch,int n,char c);


#endif /* FUNCIONES_H */
