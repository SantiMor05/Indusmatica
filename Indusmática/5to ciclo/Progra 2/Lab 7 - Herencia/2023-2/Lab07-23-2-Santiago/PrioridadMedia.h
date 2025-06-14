/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioridadMedia.h
 * Author: santi
 *
 * Created on 8 de junio de 2025, 23:51
 */

#ifndef PRIORIDADMEDIA_H
#define PRIORIDADMEDIA_H

#include "Pedido.h"

class PrioridadMedia : public Pedido{

private:
    char *descripcion;
    int nueva_fecha_entrega;

public:
    PrioridadMedia();
    //PrioridadMedia(const PrioridadMedia& orig);
    virtual ~PrioridadMedia();
    void SetNueva_fecha_entrega(int nueva_fecha_entrega);
    int GetNueva_fecha_entrega() const;
    void SetDescripcion(char* descripcion);
    void GetDescripcion(char *buffer) const;
    void inicializa();
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void actualiza();
};

#endif /* PRIORIDADMEDIA_H */

