/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: santi
 *
 * Created on 8 de septiembre de 2024, 12:18
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerYProcesarDatosArchivo(int distrito1, int distrito2, int hh, 
        int min, int seg, int duracion, char alimentos);
void lecturaEImpresionDatosUsuario(int &distrito1, int &distrito2, int &hh, 
        int &min, int &seg, int &duracion, char &alimentos);
void imprimirCaracter(char car, int n);  
void calcularDuracion(int hh_ini, int min_ini, int seg_ini, int hh_fin, 
        int min_fin, int seg_fin, int &dura, int &dura_hh, int &dura_min, 
        int &dura_seg);
void imprimirHora(int hh,int min, int seg);
void leerImprimirTexto(int n);



#endif /* FUNCIONESAUXILIARES_H */

