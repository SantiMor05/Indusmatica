/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Restaurante.h
 * Author: Usuario
 *
 * Created on 12 de junio de 2025, 08:22
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <fstream>
using namespace std;
#include "Comanda.h"


class Restaurante {
private:
    Comanda comandas[150];
    int cantidad_comandas;
public:
    Restaurante();
    void cargar_comandas();
    void leerAtenciones(const char* nomArch);
    int formarTemp(int horaI,int minI);
    void leerComandas(const char* nomArch2);
    int buscarProd(Comanda *comandas,int id);
    void imprimirComandas();
    void imprimirLinea(ofstream &arch,char c,int n);
    void actualizaComandas();
};

#endif /* RESTAURANTE_H */

