/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Restaurante.h
 * Author: santi
 *
 * Created on 8 de junio de 2025, 20:14
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "Comanda.h"

class Restaurante {
private:
    Comanda comandas[100];
    int cantidad_comandas;
    void imprimirLinea(ofstream &arch, char car);
public:
    Restaurante();
    //Restaurante(const Restaurante& orig);
    virtual ~Restaurante();
    void SetCantidad_comandas(int cantidad_comandas);
    int GetCantidad_comandas() const;
    void inicializa();
    void cargar_comandas();
    int buscarComanda(int id);
    void imprimir_comandas();
    void actualizar_comandas();
};

#endif /* RESTAURANTE_H */

