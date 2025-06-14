/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioridadBaja.h
 * Author: santi
 *
 * Created on 8 de junio de 2025, 23:55
 */

#ifndef PRIORIDADBAJA_H
#define PRIORIDADBAJA_H

#include "Pedido.h"

class PrioridadBaja : public Pedido{
private:
    int dias_espera;
    int nueva_fecha_entrega;

public:
    PrioridadBaja();
    PrioridadBaja(const PrioridadBaja& orig);
    virtual ~PrioridadBaja();
    void inicializa();
    void setNueva_fecha_entrega(int nueva_fecha_entrega);
    int getNueva_fecha_entrega() const;
    void setDias_espera(int dias_espera);
    int getDias_espera() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza();
};

#endif /* PRIORIDADBAJA_H */

