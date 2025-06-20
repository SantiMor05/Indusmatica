/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.h
 * Author: santi
 *
 * Created on 18 de junio de 2025, 11:02
 */

#ifndef COLA_H
#define COLA_H

#include "Nodo.h"


class Cola {
private:
    int longitud;
    Nodo *cabeza;
    Nodo *cola;

public:
    Cola();
//    Cola(const Cola& orig);
    virtual ~Cola();
    void SetLongitud(int longitud);
    int GetLongitud() const;
    void inicializa();
    void encola(DetalleComanda &);
    void desencola(DetalleComanda&);
    void elimina(int tipo_prote);
};

#endif /* COLA_H */

