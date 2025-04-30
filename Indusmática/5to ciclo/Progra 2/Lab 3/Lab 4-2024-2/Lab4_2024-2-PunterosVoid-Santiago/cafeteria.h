/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cafeteria.h
 * Author: santi
 *
 * Created on 29 de abril de 2025, 21:53
 */

#ifndef CAFETERIA_H
#define CAFETERIA_H

#include <fstream>
using namespace std;
void cargarInventario(const char *nombArch, void *&inventario);
void *leerInsumo(ifstream &arch);
char *leerCadenaExacta(ifstream &arch, char deli);
void cargarMenu(const char *nombArch, void *&menu);
void *leerMenu(ifstream &arch);
void actualizarMenu(const char *nombArch,void *inventario, void *menu);
void verificarDisponibilidad(void *bebida, void*insumo,
                    int cantidad, char *unidad, int &numDat, int &cap);
char *asignarCadena(char *unidad);
void incrementarEspacios(void *&insumos, int &numDat, int &cap);
int buscar(char *codBebida, void *menu);
void reporteMenu(const char *nombArch, void *menu);
void imprimirLinea(ofstream &arch, int n, char car);
void imprimirRegistro(void *menu,ofstream &arch);

#endif /* CAFETERIA_H */
