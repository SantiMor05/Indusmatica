/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Restaurante.h
 * Author: kenyi
 *
 * Created on 12 de junio de 2025, 04:46 PM
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include <fstream>
#include <iostream>
using namespace std;
#include "Comanda.h"


class Restaurante {
private:
    Comanda comandas[250];
    int cantidad_comandas;
public:
    Restaurante();
    void SetCantidad_comandas(int cantidad_comandas);
    int GetCantidad_comandas() const;
    void cargar_comandas();
    void imprimir_comandas();
    void leerCom(const char*);
    void leerAten(const char*);
    int buscarPro(int ident);
    void actualizar_comandas();
};

#endif /* RESTAURANTE_H */

