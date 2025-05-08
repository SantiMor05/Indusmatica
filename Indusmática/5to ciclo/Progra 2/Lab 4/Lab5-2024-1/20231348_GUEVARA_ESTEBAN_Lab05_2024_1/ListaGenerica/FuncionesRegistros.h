/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesRegistros.h
 * Author: esteban
 *
 * Created on 8 de mayo de 2025, 13:34
 */

#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H

void* leeregistro(ifstream &archLeer);
char * lecturaExacta(ifstream &archLeer);
void imprimeregistro(void* registro, ofstream& archReporte);
int cmpregistro(const void* regLst1,const void* regLst2);
#endif /* FUNCIONESREGISTROS_H */
