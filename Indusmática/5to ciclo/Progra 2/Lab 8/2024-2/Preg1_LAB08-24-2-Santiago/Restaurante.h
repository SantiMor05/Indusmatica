/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Restaurante.h
 * Author: santi
 *
 * Created on 18 de junio de 2025, 11:06
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "Cola.h"

class Restaurante {
private:
    Cola Ccomanda;

public:
    Restaurante();
//    Restaurante(const Restaurante& orig);
    virtual ~Restaurante();
    void carga();
    void atiende();
    void elimina(int tip_prote);

};

#endif /* RESTAURANTE_H */

